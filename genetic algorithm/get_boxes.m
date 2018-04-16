function [] = get_boxes()
global hCamera
global position
global position_outer
global pbyteRaw
global dwBufferSize
global dwNumberOfByteTrans
global dwFrameNo
global dwMilliseconds
global BG_threshhold
global phase
global frame_avg_num
global dwWidth
global dwHeight
global initial_image
global current_image
global delay


% retrieve first image
figure(1)
clf
hold on
image = RetrieveImage(frame_avg_num);
initial_image = image;

% plot the image
imagesc(image)
xlim([0,1200])
ylim([0,1600])

disp('draw the inner rectangle [red]')
h = imrect;
position = wait(h);
position = round(position);

% draw rectangle
plot([position(1), position(1)], [position(2), position(2)+ position(4)], 'r', 'Linewidth', 3)
plot([position(1)+position(3), position(1)+position(3)], [position(2), position(2)+ position(4)], 'r', 'Linewidth', 3)
plot([position(1), position(1) + position(3)], [position(2)+ position(4), position(2)+ position(4)], 'r', 'Linewidth', 3)
plot([position(1), position(1) + position(3)], [position(2), position(2)], 'r', 'Linewidth', 3)

pause(1)

disp('draw the outer rectangle [yellow]')
outer = imrect;
position_outer = wait(outer);
position_outer = round(position_outer);

% draw outer rectangle
plot([position_outer(1), position_outer(1)], [position_outer(2), position_outer(2)+ position_outer(4)], 'y', 'Linewidth', 3)
plot([position_outer(1)+position_outer(3), position_outer(1)+position_outer(3)], [position_outer(2), position_outer(2)+ position_outer(4)], 'y', 'Linewidth', 3)
plot([position_outer(1), position_outer(1) + position_outer(3)], [position_outer(2)+ position_outer(4), position_outer(2)+ position_outer(4)], 'y', 'Linewidth', 3)
plot([position_outer(1), position_outer(1) + position_outer(3)], [position_outer(2), position_outer(2)], 'y', 'Linewidth', 3)


end

