function [image] = RetrieveImage(number_of_images)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
global hCamera
global pbyteRaw
global dwBufferSize
global dwNumberOfByteTrans
global dwFrameNo
global dwMilliseconds
global BG_threshhold
global dwWidth
global dwHeight

frame_num = 0;
frame_num_old = 0;

image = 1;
final_image = zeros(size(pbyteRaw.value));

while image <= number_of_images
    calllib('StTrgApi', 'StTrg_TakeRawSnapShot',hCamera,pbyteRaw,dwBufferSize,dwNumberOfByteTrans,dwFrameNo,dwMilliseconds);
    % check frame number to make sure the image is new
    a2 = get(dwFrameNo);
    frame_num = a2.Value;
    disp(frame_num)
    if frame_num ~= frame_num_old
        % get image and filter background noise
        a1 = get(pbyteRaw);
        data = a1.Value;
        data(le(data, BG_threshhold)) = 0;
    
        % Add the image data to the final image matrix
        final_image = final_image + double(data);
        image = image + 1;
    end
    
    frame_num_old = frame_num;
    
end

% divide the final image to make the average
final_image = final_image/number_of_images;

image = final_image;