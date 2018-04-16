clear
clc


global initial_image
initial_image = 0;


fileID = fopen('Speck16.dat', 'r');
formatSpec = '%f   %f   %f   %f   %f';
size = [5 inf];

a = fscanf(fileID, formatSpec, size);
a = a';

fclose(fileID);

lambdamin = 730;
lambdamax = 840;
figure(1)
clf
plot(a(:,1), a(:,3))
xlim([lambdamin, lambdamax])

% find points in vector where lambda > lambdamin
lambda = a(:,1);
intensity = a(:, 2);
phase_meas = a(:, 3);


% define part of specturm to send to dazzler

min_index = 0;
max_index = 0;
index = length(lambda);
lambda(10)
while index > 0
    
    
    if lambdamin < lambda(index) && min_index == 0
        min_index = index;
    end
    
    if lambdamax < lambda(index) && max_index == 0
       max_index = index;
    end
    
    index = index - 1;
       
end

lambda_send = lambda(max_index:min_index);
phase_send = 1 * (phase_meas(max_index:min_index) - min(phase_meas(max_index:min_index)));

figure(2)
clf

%test polynomials
% phase_send = 1 * 0.0005 * (lambda_send - 800).^2;
% phase_send = phase_send - max(phase_send);

plot(lambda_send, phase_send);
xlabel('wavelength [nm]')
ylabel('radians')
%lambda_send
%phase_send
%phase(lambda_send, phase_send)



% app;ly second phase %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('Speck_add.dat', 'r');
formatSpec = '%f   %f   %f   %f   %f';
size = [5 inf];

a = fscanf(fileID, formatSpec, size);
a = a';

fclose(fileID);

lambdamin_2 = 730;
lambdamax_2 = 840;
figure(1)
clf
plot(a(:,1), a(:,3))
xlim([lambdamin_2, lambdamax_2])

% find points in vector where lambda > lambdamin
lambda_2 = a(:,1);
intensity_2 = a(:, 2);
phase_meas_2 = a(:, 3);


% define part of specturm to send to dazzler

min_index_2 = 0;
max_index_2 = 0;
index_2 = length(lambda_2);
lambda_2(10)
while index_2 > 0
    
    
    if lambdamin_2 < lambda_2(index_2) && min_index_2 == 0
        min_index_2 = index_2;
    end
    
    if lambdamax_2 < lambda_2(index_2) && max_index_2 == 0
       max_index_2 = index_2;
    end
    
    index_2 = index_2 - 1;
       
end

lambda_send_2 = lambda_2(max_index_2:min_index_2);
phase_send_2 = 1 * (phase_meas_2(max_index_2:min_index_2) - min(phase_meas_2(max_index_2:min_index_2)));

figure(3)
clf

%test polynomials
% phase_send = 1 * 0.0005 * (lambda_send - 800).^2;
% phase_send = phase_send - max(phase_send);

plot(lambda_send_2, phase_send_2);
title('phase 2')
xlabel('wavelength [nm]')
ylabel('radians')
%lambda_send
%phase_send
%phase(lambda_send, phase_send)


%lambda_send
%lambda_send
length(phase_send)
length(phase_send_2)


phase_send_2_corrected_ax = spline(lambda_send_2, phase_send_2, lambda_send);
figure(4)
plot(lambda_send, phase_send_2_corrected_ax)


phase_send_3 = phase_send + (1) * phase_send_2_corrected_ax;
figure(5)
plot(lambda_send, phase_send_3);
phase(lambda_send, phase_send_3)




pause(1)

init_camera()
save('frog.dat', 'initial_image', '-ascii');






