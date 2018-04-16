clear

lambdamax = 900e-9; % meters
lambdamin = 700e-9; % meters
lambda0 = 790e-9; %meters

c = 2.998e8;

wmin = (c / (lambdamax)) * 2 * pi;
wmax = (c / (lambdamin)) * 2 * pi;
w0 = (c / (lambda0)) * 2 * pi;


%original
% delay = 4350 * 1e-15;
% order2 = -8873 * 1e-30;
% order3 = -10.29e3 * 1e-45;
% order4 = 78.86e3 * 1e-60;

delay = 4350 * 1e-15;
order2 = -8000 * 1e-30;
order3 = 0 * 1e-45;
order4 = 0 * 1e-60;



w = linspace(wmin, wmax, 1000);
h = -(delay * (w-w0) + (order2/2)*(w-w0).^2 + (order3/6)*(w-w0).^3 + (order4/24)*(w-w0).^4);

%w(100) %wmax

lambda = (c * 2 * pi) ./ w;

lambda = lambda * 1e9;


% plot the function of w
figure(1)
clf
plot(w, h);
xlabel('w (rad/s)')
ylabel('rad')

% calculate function as lambda
figure(2)
clf
plot(lambda, h);
xlabel('lambda')
ylabel('rad')


% send the vectors to dazzler
phase(lambda, h);


