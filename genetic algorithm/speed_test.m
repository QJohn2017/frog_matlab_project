clear

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
disp('hello world')
current_image = 0;

delay = 1;
phase = 4350; % phase (delay) remains constant during optimization

% parameters
BG_threshhold = 0; %
%BG_threshhold = 10;
frame_avg_num = 1;


% free run, need this setting for exposure settings to work
%dwTriggerMode = 0;

% trigger mode
dwTriggerMode = 2049;

%initial parameters
X0 = [-7300, -30e3, 20e3];




% prepare camera
if not(libisloaded('StTrgApi'))
  loadlibrary('StTrgApi','StTrgApi.h');
end
disp('run')
% prepare camera
hCamera=calllib('StTrgApi', 'StTrg_Open');

dwTransferBitsPerPixel=1;

dwWidth=1600;
dwHeight=1200;
dwBufferSize = dwWidth * dwHeight;
Data=zeros(dwWidth,dwHeight);
Data=int16(Data);
pbyteRaw=libpointer('uint8Ptr',Data);
dwNumberOfByteTrans = 0;
dwNumberOfByteTrans=libpointer('uint32Ptr',dwNumberOfByteTrans);
dwFrameNo = 0;
dwFrameNo=libpointer('uint32Ptr',dwFrameNo);
dwMilliseconds = 3000;
pdwClockMode=1;
pdwClockMode=libpointer('uint32Ptr',pdwClockMode);
pdwClock=1;
pdwClock=libpointer('uint32Ptr',pdwClock);
pdwExposureValue = 1;
pdwExposureValue=libpointer('uint32Ptr', pdwExposureValue);

calllib('StTrgApi','StTrg_SetTransferBitsPerPixel',hCamera, dwTransferBitsPerPixel);
calllib('StTrgApi','StTrg_SetScanMode',hCamera, 0, 0, 0, 0, 0);
calllib('StTrgApi','StTrg_SetGain',hCamera, 0);
calllib('StTrgApi','StTrg_SetDigitalGain',hCamera, 64);
calllib('StTrgApi','StTrg_GetExposureClock',hCamera, pdwExposureValue);
calllib('StTrgApi','StTrg_SetExposureClock',hCamera, 200000);
calllib('StTrgApi','StTrg_SetClock',hCamera, 0, 0);
calllib('StTrgApi','StTrg_SetTriggerMode',hCamera,dwTriggerMode);
calllib('StTrgApi','StTrg_SetTriggerTiming',hCamera, 0, 0);
calllib('StTrgApi','StTrg_SetIOPinDirection',hCamera, 0);
calllib('StTrgApi','StTrg_SetIOPinPolarity',hCamera, 0);
calllib('StTrgApi','StTrg_SetIOPinMode',hCamera, 0, 16);


% retrieve first image
figure(1)
% send info to dazzler
dazzler_phase(phase, X0(1), X0(2), X0(3));
pause(delay)
clf
hold on
image = RetrieveImage(frame_avg_num);
initial_image = image;

% plot the image
imagesc(image)
xlim([0,1200])
ylim([0,1600])

disp('draw the inner rectangle [red]')
%h = imrect;
%position = wait(h);
%position = round(position);
position = [544, 399, 21, 770];

% draw rectangle
plot([position(1), position(1)], [position(2), position(2)+ position(4)], 'r', 'Linewidth', 1)
plot([position(1)+position(3), position(1)+position(3)], [position(2), position(2)+ position(4)], 'r', 'Linewidth', 1)
plot([position(1), position(1) + position(3)], [position(2)+ position(4), position(2)+ position(4)], 'r', 'Linewidth', 1)
plot([position(1), position(1) + position(3)], [position(2), position(2)], 'r', 'Linewidth', 1)

%pause(1)

disp('draw the outer rectangle [yellow]')
%outer = imrect;
%position_outer = wait(outer);
%position_outer = round(position_outer)
position_outer = [273, 384, 562, 816];

% draw outer rectangle
plot([position_outer(1), position_outer(1)], [position_outer(2), position_outer(2)+ position_outer(4)], 'y', 'Linewidth', 1)
plot([position_outer(1)+position_outer(3), position_outer(1)+position_outer(3)], [position_outer(2), position_outer(2)+ position_outer(4)], 'y', 'Linewidth', 1)
plot([position_outer(1), position_outer(1) + position_outer(3)], [position_outer(2)+ position_outer(4), position_outer(2)+ position_outer(4)], 'y', 'Linewidth', 1)
plot([position_outer(1), position_outer(1) + position_outer(3)], [position_outer(2), position_outer(2)], 'y', 'Linewidth', 1)

figure(2)
p = [-3000, 200, 300];
beam_optimize(p);


figure(3)
p = [-12000, 200, 300];
beam_optimize(p);


figure(4)
p = [-7000, 200, 300];
beam_optimize(p);

calllib('StTrgApi','StTrg_Close',hCamera);



