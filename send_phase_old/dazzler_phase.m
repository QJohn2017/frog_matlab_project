function [  ] = dazzler_phase( delay, order2, order3, order4 )
% function writes parameters to the dazzler over the shared network folder
home = cd;
cd \\CREOL-FAST-01\data
%cd \\CREOL-FAST-01\Dazzler_experiment

fileID = fopen('Temp.txt', 'wt');

line1 = strcat('delay=', strcat(sprintf('%0.6f', delay), '\n'));
fprintf(fileID, line1);

line2 = strcat('order2=', strcat(sprintf('%0.6f', order2), '\n'));
fprintf(fileID, line2);

line3 = strcat('order3=', strcat(sprintf('%0.6f', order3), '\n'));
fprintf(fileID, line3);

line4 = strcat('order4=', strcat(sprintf('%0.6f', order4), '\n'));
fprintf(fileID, line4);

line5 = 'CEP=1.000000';
fprintf(fileID, line5);


%write the request 
%cd \\CREOL-FAST-01\data
fileID = fopen('request.txt', 'wt');
proj = 'C:\\dazzler\\data\\Temp.txt';
fprintf(fileID, proj);
pause(0.05);
fclose('all');

cd(home);
end

