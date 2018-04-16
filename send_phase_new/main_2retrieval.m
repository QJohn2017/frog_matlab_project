clear

global initial_image
initial_image = 0;

% take the output Speck file and use only the values in a wavelength range
% subtract the minimum value of the phase
[ phase_send1, lambda_send1 ] = phase_prepare( 'Speck10.dat', 720, 850, 1, 0, 0);


% plotting the phase that will be sent
figure(1)
plot(lambda_send1, phase_send1)
title('retrieve first phase')

% sets the dazzler to both mode
% sends the phase to dazzler
%phase(lambda_send, phase_send)


% retrieve second phase
[ phase_send2, lambda_send2 ] = phase_prepare( 'Speck10_2.dat', 720, 850, 1, 0, 0);



figure(2)
plot(lambda_send2, phase_send2)
title('retrieve second phase')

% correct the wavelength axis with a spline interpolation
phase_send2_corr = spline(lambda_send2, phase_send2, lambda_send1);

figure(3)
plot(lambda_send1, phase_send2_corr)
title('mapped to same x axis')

figure(4)
phase_send_final = phase_send2_corr + phase_send1;
plot(lambda_send1, phase_send_final)
title('summation of two  phase measurements')



phase(lambda_send1, phase_send_final);





pause(1)

init_camera()
save('frog.dat', 'initial_image', '-ascii');






