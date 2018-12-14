function [ ] = prepare_camera()
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
global dwTriggerMode


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


end

