function [ ] = phase_file(lambda, phase)
% accepts lambda and phase as vectors of equal length

home = cd;
cd \\CREOL-FAST-01\data

% write phase file
fileID = fopen('wave11.txt', 'wt');
fprintf(fileID, 'phase=1\n');
fprintf(fileID, '#phase\n');

i = 1;
while i <= length(lambda)
    %line = strcat(num2str(lambda(i)), '\t', num2str(phase(i)), '\n');
    line = strcat(sprintf('%0.6f', lambda(i)), '\t', sprintf('%0.6f', phase(i)), '\n');
    fprintf(fileID, line);
    i = i + 1;
end

% write the request
fileID = fopen('request.txt', 'wt');
proj = 'C:\\dazzler\\data\\wave11.txt';
fprintf(fileID, proj);
pause(0.05);
fclose('all');
cd(home);


end

