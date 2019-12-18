function [tbl, labels, fields] = arff2tbl(filename)
    if isempty(filename)
        error('MATLAB:input', 'Bad file name!');
    end
    
    [~, ~, ext] = fileparts(filename);
    
    if strcmpi(ext, '.arff')
        fid = fopen(filename, 'rt');
    elseif strcmpi(ext, '.gz')
        % unzip to current directory
        dec_files = gunzip(filename, './');
        if ~isempty(dec_files)
            fid = fopen(dec_files{1}, 'rt');
        else
            error('%s is not a valid arff file', filename);
        end
    else 
        error('%s is not a valid arff file', filename);
    end
    
    if fid == -1
        error('MATLAB:file', 'File not found!');
    end
    
    relation = [];
    
    while isempty(relation)
        line = fgetl(fid);
        
        if ~ischar(line)
            fclose(fid);
            error('MATLAB:file', 'ARFF file not recognized');
        end
        
        if ~isempty(line) && line(1) == '@' && (strcmp(line(2:9), 'RELATION') || strcmp(line(2:9), 'relation'))
            relation = line(11:end);
            disp(relation);
            break;
        end
    end
    
    fields = {};
    labels = {};
    types = {};
    index = 0;
    
    while 1
        line = fgetl(fid);
        if ~ischar(line) || length(line) == 5
            break;
        end
        
        if length(line) > 5 && line(1) == '@' && (strcmpi(line(2:10), 'ATTRIBUTE') || strcmpi(line(2:10), 'attribute'))
            attr = textscan(line, '%s');
            attr = attr{1};
            
            if isempty(attr{1}) || isempty(attr{2}) || isempty(attr{3})
                fclose(fid);
                error('MATLAB:file', 'ARFF file not recognized');
            end
            
            if strcmpi(attr{2}, 'class')
                continue
            end
            
            index = index + 1;
            fields{index} = char(attr{2}); %#ok<*AGROW>
            if size(attr,1) == 3
                typedef = char(attr{3});
            else
                bt = strfind(line, '{');
                typedef = line(bt(1):end);
            end
            
            if typedef(1) == '{' && typedef(end) == '}'
                types{index} = 'struct';
%                 out = textscan(typedef, '%s', 'Delimiter', ' ,{}', 'MultipleDelimsAsOne', 1);
%                 nomspec.(fields{index}) = out{:};
            else
                if (strcmpi(typedef, 'NUMERIC') || strcmpi(typedef, 'numeric'))
                    types{index} = 'double';
                elseif (strcmpi(typedef, 'STRING') || strcmpi(typedef, 'string'))
                    types{index} = 'string';
                else
                    dt = strfind(typedef, ' ');
                    
                    if ~isempty(dt) && strcmpi(typedef(1:dt(1)-1), 'DATE')
                        types{index} = 'datetime';
                    else
                        fclose(fid);
                        error('MATLAB:file', 'ARFF file not recognized');
                    end
                end
            end
        end
    end
    
    
    %There may be a bug here because I am assuming all inputs are numeric
    tbl_data = zeros(0,index);  
    %tbl = table();
    tbl = [];
    while ~feof(fid)
        line = fgetl(fid);
        if ~ischar(line) || length(line) == 5
            continue;
        end
        % only supports NUMERIC data types for now
        numbers = textscan(line, '%f,', index);
        numbers = numbers{1};
        col = strfind(line, ',');
        label = strtrim(line(col(end)+1:end));
        labels{end+1} = label;
        %tbl_data = [tbl_data; numbers'];
        %tbl = [tbl; reshape(num2cell(numbers), [1 index])];
        tbl = [tbl numbers];
    end
    %tbl = table(tbl_data);%table('Size', [0, index], 'VariableTypes', types);
    tbl = array2table(tbl');
    fclose(fid);
end