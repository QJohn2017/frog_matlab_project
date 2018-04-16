function [ quality ] = beam_optimize(p)
global position
global position_outer
global phase
global frame_avg_num
global current_image
global delay
global best_quality
global best_order_vals
global best_image

% function is optimized
order2 = p(1);
order3 = p(2);
order4 = p(3);


disp('sending phase info to dazzler')
disp(strcat('order2: ', num2str(order2)))
disp(strcat('order3: ', num2str(order3)))
disp(strcat('order4: ', num2str(order4)))

disp('dazzler phase')
dazzler_phase(phase, order2, order3, order4);
pause(delay)

image = RetrieveImage(frame_avg_num);

%sum of center region
inner_sum = sum(sum(image(position(2):position(2)+position(4), position(1):position(1)+position(3))));
    
% sum of outer box
outer_sum = sum(sum(image(position_outer(2):position_outer(2)+position_outer(4), position_outer(1):position_outer(1)+position_outer(3))));

% determine uniformity quality
u_quality = uniformity(image);
ratio = inner_sum/outer_sum;


if outer_sum ~= 0
    quality = -1 * ratio * u_quality;
end

if outer_sum == 0 
    quality = 0;
end

 
% plot
figure(1)
clf
hold on
xlim([0,1200])
ylim([0,1600])
imagesc(image);
current_image = image;

% draw the boxes

% display inner box
plot([position(1), position(1)], [position(2), position(2)+ position(4)], 'r', 'Linewidth', 1)
plot([position(1)+position(3), position(1)+position(3)], [position(2), position(2)+ position(4)], 'r', 'Linewidth', 1)
plot([position(1), position(1) + position(3)], [position(2)+ position(4), position(2)+ position(4)], 'r', 'Linewidth', 1)
plot([position(1), position(1) + position(3)], [position(2), position(2)], 'r', 'Linewidth', 1)

% display outer box
plot([position_outer(1), position_outer(1)], [position_outer(2), position_outer(2)+ position_outer(4)], 'y', 'Linewidth', 1)
plot([position_outer(1)+position_outer(3), position_outer(1)+position_outer(3)], [position_outer(2), position_outer(2)+ position_outer(4)], 'y', 'Linewidth', 1)
plot([position_outer(1), position_outer(1) + position_outer(3)], [position_outer(2)+ position_outer(4), position_outer(2)+ position_outer(4)], 'y', 'Linewidth', 1)
plot([position_outer(1), position_outer(1) + position_outer(3)], [position_outer(2), position_outer(2)], 'y', 'Linewidth', 1)


dim = [.15 .6 .3 .3];
str = strcat('ratio  value : ', num2str(ratio));
annotation('textbox',dim,'String',str,'FitBoxToText','on', 'Color','black', 'Edgecolor', 'black');


% write the data to text file
fileID = fopen('test_run.txt', 'at');
fprintf(fileID, '\n');
fprintf(fileID, num2str(order2));
fprintf(fileID, ',');
fprintf(fileID, num2str(order3));
fprintf(fileID, ',');
fprintf(fileID, num2str(order4));
fprintf(fileID, ',');
fprintf(fileID, num2str(quality));
fclose(fileID);

disp('beam quality:')
disp(quality)

if quality < best_quality
    best_quality = quality;
    best_image = image;
    best_order_vals = [order2, order3, order4];
end

end

