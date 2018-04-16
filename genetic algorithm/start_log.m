function [ ] = start_log( )
global X0
global UB
global LB
global generations
global population_size
global delay
global dwTriggerMode
global frame_avg_num


% start data log
c = clock;
d = datestr(c);
fileID = fopen('test_run.txt', 'wt');
fprintf(fileID, 'begin test\n');
fprintf(fileID, d);
fprintf(fileID, '\norder2, order3, order4, quality');
fclose('all');

% make parameters log
fileID = fopen('parameters.txt', 'wt');

line = strcat('X0: ', num2str(X0), '\n');
fprintf(fileID, line);

line = strcat('UB: ', num2str(UB), '\n');
fprintf(fileID, line);

line = strcat('LB: ', num2str(LB), '\n');
fprintf(fileID, line);

line = strcat('generations: ', num2str(generations), '\n');
fprintf(fileID, line);

line = strcat('population size: ', num2str(population_size), '\n');
fprintf(fileID, line);

line = strcat('delay: ', num2str(delay), '\n');
fprintf(fileID, line);

line = strcat('trigger mode: ', num2str(dwTriggerMode), '\n');
fprintf(fileID, line);

line = strcat('frame avg number: ', num2str(frame_avg_num), '\n');
fprintf(fileID, line);



fclose('all');

end

