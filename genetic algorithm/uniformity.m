function [ u ] = uniformity( image )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
global position
%position = [460 568 72 613];

figure(3)
clf
imagesc(image);
set(gca,'YDir','normal')
hold on

x1 = position(1);
x2 = position(1) + position(3);
lowery = position(2)+ position(4);
uppery = position(2);

% draw line through center
middlex = (x1 + x2) / 2;
plot([middlex, middlex], [lowery, uppery], 'y', 'Linewidth', 1);

length_middle = abs(uppery - lowery) + 1;
I_meas = zeros(length_middle, 1);
xpoints = zeros(length_middle, 1);

j = 1;
for i = uppery:lowery
    
    I_meas(j) = sum(image(i, x1:x2));

    xpoints(j) = i;
    j = j + 1;
    
end

figure(4)
clf
hold on
xlim([min(xpoints), max(xpoints)]);
ylim([0, 1200]);
xlabel('pixel number')
ylabel('Intensity Count [au]')

plot(xpoints, I_meas)


%plot I_ref:
% average of points
% average = sum(I_meas) / length_middle;
% I_ref = ones(length_middle, 1) * average;
% plot(xpoints, I_ref, 'r');

% percentage of max
percent = 1;
I_ref = ones(length_middle, 1) * percent * max(I_meas);
plot(xpoints, I_ref, 'r');
legend('Measured Intensity', 'Reference Intensity')

% calculate uniformity
%calculate vector of I_ref-I_meas
delta_I = abs(I_ref - I_meas);
%plot(xpoints, delta_I)
%ylabel('I ref - I meas')
%xlabel('pixel')

% calculate uniformity value for each pixel
% width of gaussian
figure(5)
clf
alpha = 0.5 * max(I_ref);
uniformity_vals = exp(-((delta_I).^2)/(alpha^2));
plot(xpoints, uniformity_vals)
xlabel('pixel number')
ylabel('Uniformity measurement')
u = sum(uniformity_vals) / length(uniformity_vals);
dim = [.15 .6 .3 .3];
str = strcat('uniformity value : ', num2str(u));
annotation('textbox',dim,'String',str,'FitBoxToText','on', 'Color','black', 'Edgecolor', 'black');


end

