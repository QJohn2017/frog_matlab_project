function [  ] = init_camera(  )
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
%X0 = [-5228, 24488, -48705];




% prepare camera
if not(libisloaded('StTrgApi'))
  loadlibrary('StTrgApi','StTrgApi.h');
end
disp('run')
% prepare camera
hCamera=calllib('StTrgApi', 'StTrg_Open');

dwTransferBitsPerPixel=4;
dwWidth=1600;
dwHeight=1200;
dwBufferSize = 2 * dwWidth * dwHeight;
Data=zeros(dwWidth,dwHeight);
Data=int16(Data);
pbyteRaw=libpointer('uint16Ptr',Data);
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


% send info to dazzler
%dazzler_phase(phase, X0(1), X0(2), X0(3));
%pause(delay)

% retrieve first image
figure(10)
clf
hold on
image = RetrieveImage(frame_avg_num);
initial_image = image;

% plot the image
imagesc(image)
xlim([0,1200])
ylim([0,1600])

calllib('StTrgApi','StTrg_Close',hCamera);

end

