function Generate_DecisionTree(arff_filename, dt_filename)
    [tbl, labels, fields] = arff2tbl(arff_filename);  % parse an ARFF file and output the variable names
    tree = fitctree(tbl, labels);                     % MATLAB decision tree function
    str = recursiveProduceTree(tree, fields, 1, '');  % convert decision tree to Weka format
    fid = fopen(dt_filename, 'w');                    % Write above decision tree to text file
    fprintf(fid, str);
    fclose(fid);
end