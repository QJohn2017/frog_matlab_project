function [ phase_send, lambda_send ] = phase_prepare( filename, lambdamin, lambdamax, phase_mult, minvals, maxvals)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
fileID = fopen(filename, 'r');
formatSpec = '%f   %f   %f   %f   %f';
size = [5 inf];

a = fscanf(fileID, formatSpec, size);
a = a';
fclose(fileID);

% find points in vector where lambda > lambdamin
lambda = a(:,1);
intensity = a(:, 2);
phase_meas = a(:, 3);

% define part of specturm to send to dazzler
min_index = 0;
max_index = 0;
index = length(lambda);

% have to count backward
while index > 0
    
    if lambdamin < lambda(index) && min_index == 0
        min_index = index;
    end
    
    if lambdamax < lambda(index) && max_index == 0
       max_index = index;
    end
    
    index = index - 1;
       
end
a = phase_meas(max_index:min_index);
b = lambda(max_index:min_index);
k = 0;


while (k < maxvals)
    [~, i] = max(a);
    a(i) = [];
    b(i) = [];
%     phase_meas(max_index:min_index) = a;
%     lambda(max_index:min_index) = b;
    k = k + 1;
end
k = 0;
while (k < minvals)
    [~, i] = min(a);
    a(i) = [];
    b(i) = [];
%     phase_meas(max_index:min_index) = a;
%     lambda(max_index:min_index) = b;
    k = k + 1;
end

lambda_send = b;

phase_send = phase_mult * (a - min(a));

end

