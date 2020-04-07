import pandas as pd
from sklearn.tree import DecisionTreeClassifier  # Import Decision Tree Classifier
from sklearn.model_selection import train_test_split  # Import train_test_split function
from sklearn import metrics  # Import scikit-learn metrics module for accuracy calculation
from sklearn import tree
from scipy.io import arff
import re
import sys
import numpy as np


def isLeaf(src_str):
    r = re.match("[0-9]+ \[label=\"", src_str)
    s = re.search("\\\\n", src_str)
    if (r != None and s == None):
        return True
    else:
        return False


def printClassName(src_str, dt_file):
    r = re.search("[0-9]+ \[label=\"", src_str)
    s = re.search("\"\] ;", src_str)
    t = re.search("\\\\n", src_str)
    if (r != None and s != None and t == None):
        print(src_str[r.end():s.start()], end="", file=dt_file)


def printCondition(src_str, dt_file):
    r = re.search("[0-9]+ \[label=\"", src_str)
    s = re.search("\\\\n", src_str)
    if (r != None and s != None):
        print(src_str[r.end():s.start()], end="", file=dt_file)


def getNodeNum(src_str):
    r = re.match("[0-9]+", src_str)
    if (r != None):
        return int(r.group(0))
    else:
        return ""


def getNextLineIndex(src_list, node_num):
    tmp = []
    i = len(src_list) - 1
    for line in reversed(src_list):
        if (getNodeNum(line) == int(node_num)):
            return i
        i -= 1
    return -1


def isNodeInfo(src_str):
    if (re.match('[0-9]+ -> [0-9]+[ ]+;', src_str) != None):
        return True
    else:
        return False


def oppOperator(src_str):
    src_str = src_str.replace("<=", ">")
    src_str = src_str.replace(">=", "<")
    return src_str


def formatTree(line, indent, dt_file):
    # Init to zeros, will store n_nodes and n_leaves
    size = np.array([0, 0])
    # If the first line is just node connection info line, skip it
    if (isNodeInfo(line[0])):
        line = line[1:]

    # Add this node
    size[0] += 1

    # If the first line is a leaf, print its name with \n, otherwise only \n
    if (isLeaf(line[0])):
        print(": ", end="", file=dt_file)
        printClassName(line[0], dt_file)
        print("", file=dt_file)
        return np.array([1, 1])
    else:
        print("", file=dt_file)

    nIndex = getNodeNum(line[0])  # Get node index
    splitIndex = getNextLineIndex(line[1:], nIndex)  # Get split index

    if (len(line[1:splitIndex]) > 0):
        # Print original condition
        print("|   " * indent, end="", file=dt_file)
        printCondition(line[0], dt_file)
        size += formatTree(line[1:splitIndex], indent + 1, dt_file)  # Call recursively for the first part of original tree

    if (len(line[splitIndex - 1:]) > 0):
        # Print opposite condition
        print("|   " * indent, end="", file=dt_file)
        printCondition(oppOperator(line[0]), dt_file)
        size += formatTree(line[splitIndex - 1:], indent + 1, dt_file)  # Call recursively for the second part of original tree

    return size


def printTree(dot_tree, dt_file):
    new_tree = []

    # Preprocess the tree
    for line in dot_tree.split("\n"):
        r = re.search("[0-9]+\\\\n\[([0-9]+[,]?[ ]?)+\]\\\\n", line)
        s = re.search("\[labeldistance=[0-9]+\.?[0-9]*, labelangle=-?[0-9]+, headlabel=\"(False|True)\"\]", line)
        if (r != None):
            line = line[:r.start()] + line[r.end():]
        if (s != None):
            line = line[:s.start()] + line[s.end():]
        new_tree.append(line)

    # Print in Weka format
    n_nodes, n_leaves = formatTree(new_tree[2:-1], 0, dt_file)

    print('\nNumber of Leaves  : \t', n_leaves, file=dt_file)
    print('\nSize of the Tree : \t', n_nodes, file=dt_file)

    return n_nodes, n_leaves


def generateDecisionTree(arff_filename, dectree_filename):
    data = arff.loadarff(arff_filename)  # <- Write desired file here
    data_set = pd.DataFrame(data[0])
    data_set['class'] = data_set['class'].str.decode('ASCII')
    col_names = list(data_set)

    feature_cols = col_names[:-1]
    class_name = list(set(data_set[col_names[-1]]))

    X = data_set[feature_cols]  # Features
    y = data_set[col_names[-1]]  # Target variable

    # Split dataset into training set and test set
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3,
                                                        random_state=1)  # 70% training and 30% test

    # Create Decision Tree classifer object
    clf = tree.DecisionTreeClassifier(random_state=1)  # You can specify the max depth by passing argument for example: max_depth=3

    # Train Decision Tree Classifer
    clf = clf.fit(X_train, y_train)

    # Predict the response for test dataset
    y_pred = clf.predict(X_test)

    # Model Accuracy, how often is the classifier correct?
    dectree_accuracy = metrics.accuracy_score(y_test, y_pred)
    print("Accuracy:", dectree_accuracy)

    dot_tree = tree.export_graphviz(clf, out_file=None, class_names=clf.classes_, label="none", impurity=False,
                                    feature_names=feature_cols)

    dt_file = open(dectree_filename, "w")
    n_nodes, n_leaves = printTree(dot_tree, dt_file)
    dt_file.close()

    printTree(dot_tree, sys.stdout)

    return dectree_accuracy, n_nodes


def generate_subset_of_ARFF(arff_filename, arff_subset_filename, classes_subset):
    with open(arff_filename, "r") as input:
        with open(arff_subset_filename, "w") as output:
            data_section_started = False
            for line in input:
                if line.startswith('@attribute class {'):
                    new_line_class = '@attribute class {'
                    for i_class in range(len(classes_subset)):
                        if i_class > 0:
                            new_line_class += ', '
                        new_line_class += classes_subset[i_class]
                    new_line_class += '}\r\n'
                    output.write(new_line_class)
                else:
                    if line.startswith('@data'):
                        data_section_started = True
                        output.write(line)

                    if (data_section_started == False):
                        output.write(line)
                    else:
                        class_in_line = line.split(', ')[-1]
                        if (class_in_line.rstrip() in classes_subset):
                            output.write(line)
    input.close()
    output.close()
    return


arff_filename = "test.arff"
dectree_filename = "dectree.txt"
dectree_accuracy, dectree_nodes = generateDecisionTree(arff_filename, dectree_filename)
