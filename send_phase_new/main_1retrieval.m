clear

global initial_image
initial_image = 0;

% take the output Speck file and use only the values in a wavelength range
% subtract the minimum value of the phase
[ phase_send, lambda_send ] = phase_prepare( 'Speck13.dat', 720, 840, -1, 0, 0);


% plotting the phase that will be sent
figure(1)
plot(lambda_send, phase_send)

% sets the dazzler to both mode
% sends the phase to dazzler
phase(lambda_send, phase_send)

pause(1)

init_camera()
save('frog.dat', 'initial_image', '-ascii');






