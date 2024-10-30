from typing import List, Tuple, Optional, TextIO
import logging
import re
import warnings
warnings.filterwarnings("ignore", category=SyntaxWarning)

import numpy as np
import pandas as pd
from scipy.io import arff
from sklearn import metrics
from sklearn.tree import DecisionTreeClassifier, export_graphviz
from sklearn.model_selection import train_test_split


def is_leaf(src: str) -> bool:
    r = re.match('[0-9]+ \[label="', src)
    s = re.search("\\\\n", src)
    return (r is not None) and (s is None)


def print_class_name(src: str, dt_file: TextIO) -> None:
    r = re.search('[0-9]+ \[label="', src)
    s = re.search('"\] ;', src)
    t = re.search("\\\\n", src)
    if (r is not None) and (s is not None) and (t is None):
        print(src[r.end():s.start()], end="", file=dt_file)


def print_condition(src: str, dt_file: TextIO) -> None:
    r = re.search('[0-9]+ \[label="', src)
    s = re.search("\\\\n", src)
    if (r is not None) and (s is not None):
        print(src[r.end():s.start()], end="", file=dt_file)


def get_node_num(src: str) -> Optional[int]:
    r = re.match("[0-9]+", src)
    if r is not None:
        return int(r.group(0))
    return None


def get_next_line_idx(src_list: List[str], node_num: int) -> int:
    i = len(src_list) - 1
    for line in reversed(src_list):
        if get_node_num(line) == int(node_num):
            return i
        i -= 1
    return -1


def is_node_info(src: str) -> bool:
    return re.match("[0-9]+ -> [0-9]+[ ]+;", src) is not None


def replace_node_sign(src: str) -> str:
    src = src.replace("<=", ">")
    src = src.replace(">=", "<")
    return src


def format_tree(lines: List[str], indent: int, dt_file: TextIO) -> np.ndarray:
    # Init to zeros, will store n_nodes and n_leaves
    size = np.array([0, 0])
    # If the first line is just node connection info line, skip it
    if is_node_info(lines[0]):
        lines = lines[1:]

    # Add this node
    size[0] += 1

    # If the first line is a leaf, print its name with \n, otherwise only \n
    if is_leaf(lines[0]):
        print(": ", end="", file=dt_file)
        print_class_name(lines[0], dt_file)
        print("", file=dt_file)
        return np.array([1, 1])
    else:
        print("", file=dt_file)

    node_index = get_node_num(lines[0])  # Get node index
    split_index = get_next_line_idx(lines[1:], node_index)  # Get split index

    if len(lines[1:split_index]) > 0:
        # Print original condition
        print("|   " * indent, end="", file=dt_file)
        print_condition(lines[0], dt_file)
        size += format_tree(
            lines[1:split_index], indent + 1, dt_file
        )  # Call recursively for the first part of original tree

    if len(lines[split_index - 1:]) > 0:
        # Print opposite condition
        print("|   " * indent, end="", file=dt_file)
        print_condition(replace_node_sign(lines[0]), dt_file)
        size += format_tree(
            lines[split_index - 1:], indent + 1, dt_file
        )  # Call recursively for the second part of original tree

    return size


def print_tree(dot_tree: str, dt_file: TextIO) -> Tuple[int, int]:
    new_tree = []

    # Preprocess the tree
    for line in dot_tree.split("\n"):
        r = re.search("[0-9]+\\\\n\[(([0-9]+[,]?[ ]?)|([0-9]+\\\\n))+\]\\\\n", line)
        s = re.search(
            '\[labeldistance=[0-9]+\.?[0-9]*, labelangle=-?[0-9]+, headlabel="(False|True)"\]',
            line,
        )
        t = re.search("(\d+\s*\[.*)|(\d\s*->\s*\d)|(.*}.*)", line)
        if r is not None:
            line = line[:r.start()] + line[r.end():]
        if s is not None:
            line = line[:s.start()] + line[s.end():]
        if t is not None:
            new_tree.append(line)

    # Print in Weka format
    size_tree, n_leaves = format_tree(new_tree[:-1], 0, dt_file)

    print(f"\nNumber of Leaves : {n_leaves}", file=dt_file)
    print(f"Size of the Tree : {size_tree}", file=dt_file)

    n_nodes = n_leaves - 1

    return n_nodes, n_leaves


def generate_decision_tree(
    arff_filename: str,
    dectree_filename: str,
) -> Tuple[float, int]:
    data = arff.loadarff(arff_filename)
    data_set = pd.DataFrame(data[0])
    data_set["class"] = data_set["class"].str.decode("ASCII")
    col_names = list(data_set)
    feature_cols = col_names[:-1]

    X = data_set[feature_cols]  # Features
    y = data_set[col_names[-1]]  # Target variable

    # Split dataset into training set and test set
    # 70% training and 30% test
    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.3, random_state=1
    )

    # Create Decision Tree classifer object
    clf = DecisionTreeClassifier(random_state=42, max_depth=256)

    # Train Decision Tree Classifer
    clf = clf.fit(X_train, y_train)

    # Predict the response for test dataset
    y_pred = clf.predict(X_test)
    dectree_accuracy = metrics.accuracy_score(y_test, y_pred)

    dot_tree = export_graphviz(
        clf,
        out_file=None,
        class_names=clf.classes_,
        label="none",
        impurity=False,
        feature_names=feature_cols,
    )

    # Save to file
    with open(dectree_filename, "w", encoding="ascii") as dt:
        n_nodes, _ = print_tree(dot_tree, dt)

    # Read file for logging
    text_file = open(dectree_filename, "r", encoding="ascii")
    file_content = text_file.read()
    text_file.close()
    if n_nodes > 0:
        logging.info("Accuracy: %d", dectree_accuracy)
        logging.info(file_content)
    else:
        logging.error("ERROR: decision tree empty. Please check selected "
                      "features")

    return dectree_accuracy, n_nodes


def generate_arff_subset(
    arff_filename: str,
    arff_subset_filename: str,
    classes_subset: List[str],
) -> None:
    inp = open(arff_filename, "r", encoding="ascii")
    out = open(arff_subset_filename, "w", encoding="ascii")
    data_section_started = False
    for line in inp:
        if line.startswith("@attribute class {"):
            new_line_class = "@attribute class {"
            for i, class_i in enumerate(classes_subset):
                if i > 0:
                    new_line_class += ", "
                new_line_class += class_i
            new_line_class += "}\n"
            out.write(new_line_class)
        else:
            if line.startswith("@data"):
                data_section_started = True
                out.write(line)

            if data_section_started is False:
                out.write(line)
            else:
                class_in_line = line.split(", ")[-1]
                if class_in_line.rstrip() in classes_subset:
                    out.write(line)
    inp.close()
    out.close()
