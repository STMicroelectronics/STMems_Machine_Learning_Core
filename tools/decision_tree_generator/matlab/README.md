## 1 - Matlab scripts

This folder contains some scripts to be used as example for generating a decision tree with Matlab. 
After importing all the scripts in the Matlab workspace, the function **Generate_DecisionTree()** should be called, specifying two file names (a *.arff* file containing the features computed by the Machine Learning Core tool in Unico, and a *.txt* file which will contain the decision tree generated):

    filename_ARFF = 'features.arff';
    filename_dectree = 'decision_tree.txt';
    Generate_DecisionTree(filename_ARFF, filename_dectree);

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2019 STMicroelectronics**

