# Decision tree generation corpus taken from: https://www.datacamp.com/community/tutorials/decision-tree-classification-python
# Load libraries

import pandas as pd
from sklearn.tree import DecisionTreeClassifier # Import Decision Tree Classifier
from sklearn.model_selection import train_test_split # Import train_test_split function
from sklearn import metrics #Import scikit-learn metrics module for accuracy calculation
from sklearn import tree
from scipy.io import arff
import sys
import re

# === Help functions start ===

def isLeaf ( src_str ):
    r = re.match("[0-9]+ \[label=\"", src_str)
    s = re.search("\\\\n", src_str)
    if (r != None and s == None):
        return True
    else:
        return False

def printClassName (src_str):
    r = re.search("[0-9]+ \[label=\"", src_str)
    s = re.search("\"\] ;", src_str)
    t = re.search("\\\\n", src_str)
    if (r != None and s != None and t == None):
        print(src_str[r.end():s.start()], end = "")
    
def printCondition ( src_str ):
    r = re.search("[0-9]+ \[label=\"", src_str)
    s = re.search("\\\\n", src_str)
    if (r != None and s != None):
        print(src_str[r.end():s.start()], end = "")

def getNodeNum (src_str):
    r = re.match("[0-9]+", src_str)
    if ( r != None):
        return int(r.group(0))
    else:
        return ""

def getNextLineIndex (src_list, node_num):
    tmp = []
    i = len(src_list)-1
    for line in reversed(src_list):
        if ( getNodeNum(line) == int(node_num)):
            return i
        i -= 1
    return -1

def isNodeInfo (src_str):
    if (re.match('[0-9]+ -> [0-9]+[ ]+;', src_str) != None):
        return True
    else:
        return False
def oppOperator (src_str):
    src_str = src_str.replace("<=", ">")
    src_str = src_str.replace(">=", "<")
    return src_str

def formatTree ( line, indent ):
    global leaf_size, tree_size
    
    # If the first line is just node connection info line, skip it
    if (isNodeInfo(line[0])):
        line = line[1:]

    # If the first line is a leaf, print its name with \n, othewise only \n
    if (isLeaf(line[0])):
        print(": ", end = "")
        printClassName(line[0])
        print("")
        leaf_size += 1
        tree_size += 1
        return
    else:
        print("")
        tree_size += 1

    nIndex = getNodeNum(line[0]) # Get node index
    splitIndex = getNextLineIndex (line[1:], nIndex) # Get split index

    if( len(line[1:splitIndex])> 0):
        # Print original condition
        print("|   "*indent, end = "")
        printCondition(line[0])
        formatTree(line[1:splitIndex], indent + 1) # Call recusively for the first part of original tree
        
    if ( len(line[splitIndex-1:]) > 0):
        # Print opposite condition
        print("|   "*indent, end = "")
        printCondition(oppOperator(line[0]))
        formatTree(line[splitIndex-1:], indent + 1)# Call recusively for the second part of original tree
        
def printTree (dot_tree):
    new_tree = []
     
    # Preprocess the tree 
    for line in dot_tree.split("\n"):
        r = re.search("[0-9]+\\\\n\[([0-9]+[,]?[ ]?)+\]\\\\n", line)
        s = re.search("\[labeldistance=[0-9]+\.?[0-9]*, labelangle=-?[0-9]+, headlabel=\"(False|True)\"\]", line)
        if ( r != None ):
            line = line[:r.start()]+line[r.end():]
        if ( s != None ):
            line = line[:s.start()]+line[s.end():]
        new_tree.append(line)
    
    # Print in Weka format
    formatTree ( new_tree[2:-1], 0 )
    
    print(f"\nNumber of Leaves  : \t{leaf_size}")
    print(f"\nSize of the tree : \t{tree_size}")

# === Help functions end ===

# === Code starts here ===

# load dataset
data = arff.loadarff(sys.argv[1]) # Load file into panda dataframe
data_set = pd.DataFrame(data[0])
data_set['class'] = data_set['class'].str.decode('ASCII')
col_names = list(data_set)

feature_cols = col_names[:-1]
class_name = list(set(data_set[col_names[-1]]))


X = data_set[feature_cols] # Features
y = data_set[col_names[-1]] # Target variable

# Split dataset into training set and test set
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=1) # 70% training and 30% test
# Create Decision Tree classifer object
clf = tree.DecisionTreeClassifier() # You can specify the max depth by passing argument for example: max_depth=3

# Train Decision Tree Classifer
clf = clf.fit(X_train,y_train)

#Predict the response for test dataset
y_pred = clf.predict(X_test)

# Model Accuracy, how often is the classifier correct?
print("\nAccuracy:",metrics.accuracy_score(y_test, y_pred), end = "\n\n")


leaf_size = 0
tree_size = 0

dot_tree = tree.export_graphviz(clf, out_file=None, class_names=class_name, label= "none", impurity = False, feature_names = feature_cols)

printTree (dot_tree)
