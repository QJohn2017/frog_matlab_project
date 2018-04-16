clear

global initial_image
initial_image = 0;
wavelength = linspace(670, 930, 1000);
wavelength_center = 770;
width = 2;
%radians = 10;
radians= 0 ;
phase_vals = radians * exp(-(wavelength-wavelength_center).^2/(width)^2);
figure(1)
plot(wavelength, phase_vals);
xlabel('wavelength [nm]')
ylabel('phase [rad]')
title('phase')

phase(wavelength, phase_vals);

pause(1)

init_camera()
save('frog.dat', 'initial_image', '-ascii');
