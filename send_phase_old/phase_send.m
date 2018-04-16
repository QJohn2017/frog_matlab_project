clear
clc

% dazzler front panel parameters
delay = 4350; % fs
order2 = -7551; % fs^2
order3 = -28e3; % fs^3
order4 = 90e3; % fs^4

c = 2.998e8; %m/s
center_lambda_nm = 800; %nm
lambdamax = 950; %nm
lambdamin = 650; %nm

wmin = (c * 2 * pi) / (lambdamax * 1e-9); % rad/s
wmax = (c * 2 * pi) / (lambdamin * 1e-9); % rad/s
w = linspace(wmin, wmax, 100); % create frequency space [rad/s]
a = (c * 2 * pi) / (center_lambda_nm * 1e-9) ; % central frequency rad/s


phi = delay * 1e-15 * (w - a) + (1/2) * order2 * 1e-15 * (w-a).^2 + (1/6) * order3 * 1e-15 * (w-a).^3 + (1/24) * order4 * 1e-15 * (w-a).^4;

wavelength = 1e9 * c * (2 * pi) ./ w;


figure(1)
plot(w, phi)
xlabel('w[rad/s]')
ylabel('phi[rad]')

figure(2)
plot(wavelength, phi)
xlabel('wavelength[nm]')
ylabel('phi[rad]')

% send parameters to dazzler
%phase(wavelength, phi);



