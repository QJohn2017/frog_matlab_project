//Created Date:2012/07/23 15:08
//=============================================================================
//StTrgAPI.h
//=============================================================================
#ifndef __ST_TRG_API_H
#define __ST_TRG_API_H

#ifdef __cplusplus
extern "C" {
#endif  //__cplusplus

//Callback Function
typedef void (WINAPI *funcExposureEndCallback)(HANDLE hCamera, DWORD dwFrameNo, PVOID pvContext);
typedef void (WINAPI *funcTransferEndCallback)(HANDLE hCamera, DWORD dwFrameNo, DWORD dwWidth, DWORD dwHeight, WORD wColorArray, PBYTE pbyteRaw, PVOID pvContext);
typedef void (WINAPI *funcRcvErrorCallback)(HANDLE hCamera, DWORD dwErrorCode, PVOID pvContext);

//-----------------------------------------------------------------------------
//Initialize
//-----------------------------------------------------------------------------
HANDLE WINAPI StTrg_Open();
VOID WINAPI StTrg_Close(HANDLE hCamera);

//-----------------------------------------------------------------------------
//Camera Information
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_GetDllVersion(PDWORD pdwFileVersionMS, PDWORD pdwFileVersionLS, PDWORD pdwProductVersionMS, PDWORD pdwProductVersionLS);
BOOL WINAPI StTrg_GetCameraVersion(HANDLE hCamera, PWORD pwUSBVendorID, PWORD pwUSBProductID, PWORD pwFPGAVersion, PWORD pwFirmVersion);
BOOL WINAPI StTrg_GetProductNameA(HANDLE hCamera, PSTR pszProductName, DWORD dwBufferSize);
BOOL WINAPI StTrg_GetProductNameW(HANDLE hCamera, PWSTR pszProductName, DWORD dwBufferSize);
BOOL WINAPI StTrg_GetColorArray(HANDLE hCamera, PWORD pwColorArray);
BOOL WINAPI StTrg_HasFunction(HANDLE hCamera, DWORD dwCameraFunctionID, BOOL* pbHasFunction);
BOOL WINAPI StTrg_ReadUserMemory(HANDLE hCamera, PBYTE pbyteData, WORD wOffset, WORD wLength);
BOOL WINAPI StTrg_WriteUserMemory(HANDLE hCamera, PBYTE pbyteData, WORD wOffset, WORD wLength);
BOOL WINAPI StTrg_ReadCameraUserIDA(HANDLE hCamera, PDWORD pdwCameraID, PSTR pszCameraName, DWORD dwBufferSize);
BOOL WINAPI StTrg_ReadCameraUserIDW(HANDLE hCamera, PDWORD pdwCameraID, PWSTR pszCameraName, DWORD dwBufferSize);
BOOL WINAPI StTrg_WriteCameraUserIDA(HANDLE hCamera, DWORD dwCameraID, PCSTR pszCameraName, DWORD dwBufferSize);
BOOL WINAPI StTrg_WriteCameraUserIDW(HANDLE hCamera, DWORD dwCameraID, PCWSTR pszCameraName, DWORD dwBufferSize);
BOOL WINAPI StTrg_ResetCounter(HANDLE hCamera);

//-----------------------------------------------------------------------------
//Setting
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_WriteSettingFileW(HANDLE hCamera, PCWSTR pszFileName);
BOOL WINAPI StTrg_WriteSettingFileA(HANDLE hCamera, PCSTR pszFileName);
BOOL WINAPI StTrg_ReadSettingFileW(HANDLE hCamera, PCWSTR pszFileName);
BOOL WINAPI StTrg_ReadSettingFileA(HANDLE hCamera, PCSTR pszFileName);
BOOL WINAPI StTrg_CameraSetting(HANDLE hCamera, WORD wMode);

//-----------------------------------------------------------------------------
//Image Information
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_GetEnableScanMode(HANDLE hCamera, PWORD pwEnableScanMode);
BOOL WINAPI StTrg_GetMaximumImageSize(HANDLE hCamera, PDWORD pdwMaximumImageWidth, PDWORD pdwMaximumImageHeight);
BOOL WINAPI StTrg_GetScanMode(HANDLE hCamera, PWORD pwScanMode, PDWORD pdwOffsetX, PDWORD pdwOffsetY, PDWORD pdwWidth, PDWORD pdwHeight);
BOOL WINAPI StTrg_SetScanMode(HANDLE hCamera, DWORD wScanMode, DWORD dwOffsetX, DWORD dwOffsetY, DWORD dwWidth, DWORD dwHeight);
BOOL WINAPI StTrg_GetEnableTransferBitsPerPixel(HANDLE hCamera, PDWORD pdwEnableTransferBitsPerPixel);
BOOL WINAPI StTrg_GetTransferBitsPerPixel(HANDLE hCamera, PDWORD pdwTransferBitsPerPixel);
BOOL WINAPI StTrg_SetTransferBitsPerPixel(HANDLE hCamera, DWORD dwTransferBitsPerPixel);
BOOL WINAPI StTrg_GetSkippingAndBinning(HANDLE hCamera, PBYTE pbyteHSkipping, PBYTE pbyteVSkipping, PBYTE pbyteHBinning, PBYTE pbyteVBinning);
BOOL WINAPI StTrg_SetSkippingAndBinning(HANDLE hCamera, BYTE byteHSkipping, BYTE byteVSkipping, BYTE byteHBinning, BYTE byteVBinning);
BOOL WINAPI StTrg_GetBinningSumMode(HANDLE hCamera, PWORD pwValue);
BOOL WINAPI StTrg_SetBinningSumMode(HANDLE hCamera, WORD wValue);
BOOL WINAPI StTrg_ConvTo8BitsImage(DWORD dwWidth, DWORD dwHeight, DWORD dwTransferBitsPerPixel, PWORD pwRaw, PBYTE pbyteRaw);
BOOL WINAPI StTrg_ConvYUVOrBGRToBGRImage(DWORD dwWidth, DWORD dwHeight, DWORD dwTransferBitsPerPixel, PBYTE pbyteYUVOrBGR, DWORD dwPixelFormat, PBYTE pbyteBGR);

//-----------------------------------------------------------------------------
//Clock
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_GetOutputFPS(HANDLE hCamera, PFLOAT pfFPS);
BOOL WINAPI StTrg_GetClock(HANDLE hCamera, PDWORD pdwClockMode, PDWORD pdwClock);
BOOL WINAPI StTrg_SetClock(HANDLE hCamera, DWORD dwClockMode, DWORD dwClock);
BOOL WINAPI StTrg_GetEnableClockMode(HANDLE hCamera, PDWORD pdwClockMode);
BOOL WINAPI StTrg_GetVBlankForFPS(HANDLE hCamera, PDWORD pdwVLines);
BOOL WINAPI StTrg_SetVBlankForFPS(HANDLE hCamera, DWORD dwVLines);
BOOL WINAPI StTrg_GetFrameClock(HANDLE hCamera, PWORD pwTotalLine, PWORD pwTotalHClock);

//-----------------------------------------------------------------------------
//Shutter Gain Control
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_SetGain(HANDLE hCamera, DWORD wGain);
BOOL WINAPI StTrg_GetGain(HANDLE hCamera, PDWORD pwGain);
BOOL WINAPI StTrg_GetMaxGain(HANDLE hCamera, PWORD pwMaxGain);
BOOL WINAPI StTrg_GetGainDBFromSettingValue(HANDLE hCamera, WORD wGain, PFLOAT pfGaindB);
BOOL WINAPI StTrg_GetExposureClock(HANDLE hCamera, PDWORD pdwExposureValue);
BOOL WINAPI StTrg_SetExposureClock(HANDLE hCamera, DWORD dwExposureValue);
BOOL WINAPI StTrg_GetMaxShortExposureClock(HANDLE hCamera, PDWORD pdwMaximumExposureClock);
BOOL WINAPI StTrg_GetMaxLongExposureClock(HANDLE hCamera, PDWORD pdwMaximumExposureClock);
BOOL WINAPI StTrg_GetExposureClockFromTime(HANDLE hCamera, FLOAT fExpTime, PDWORD pdwExposureClock);
BOOL WINAPI StTrg_GetExposureTimeFromClock(HANDLE hCamera, DWORD dwExposureClock, PFLOAT pfExpTime);
BOOL WINAPI StTrg_SetDigitalGain(HANDLE hCamera, DWORD wDigitalGain);
BOOL WINAPI StTrg_GetDigitalGain(HANDLE hCamera, PWORD pwDigitalGain);
BOOL WINAPI StTrg_ALC(HANDLE hCamera, WORD wCurrentBrightness, PDWORD pdwALCStatus);
BOOL WINAPI StTrg_GetAveragePixelValue(DWORD dwImageWidth, DWORD dwImageHeight, WORD wColorArray, DWORD dwTransferBitsPerPixel, PBYTE pbyteRaw, DWORD dwAOIOffsetX, DWORD dwAOIOffsetY, DWORD dwAOIWidth, DWORD dwAOIHeight, PFLOAT pfAverage);
BOOL WINAPI StTrg_SetALCMode(HANDLE hCamera, BYTE byteALCMode);
BOOL WINAPI StTrg_GetALCMode(HANDLE hCamera, PBYTE pbyteALCMode);
BOOL WINAPI StTrg_SetALCTargetLevel(HANDLE hCamera, WORD wLevel);
BOOL WINAPI StTrg_GetALCTargetLevel(HANDLE hCamera, PWORD pwLevel);
BOOL WINAPI StTrg_GetAGCMinGain(HANDLE hCamera, PWORD pwMinGain);
BOOL WINAPI StTrg_SetAGCMinGain(HANDLE hCamera, WORD wMinGain);
BOOL WINAPI StTrg_GetAGCMaxGain(HANDLE hCamera, PWORD pwMaxGain);
BOOL WINAPI StTrg_SetAGCMaxGain(HANDLE hCamera, WORD wMaxGain);
BOOL WINAPI StTrg_GetAEMinExposureClock(HANDLE hCamera, PDWORD pdwMinExposureClock);
BOOL WINAPI StTrg_SetAEMinExposureClock(HANDLE hCamera, DWORD dwMinExposureClock);
BOOL WINAPI StTrg_GetAEMaxExposureClock(HANDLE hCamera, PDWORD pdwMaxExposureClock);
BOOL WINAPI StTrg_SetAEMaxExposureClock(HANDLE hCamera, DWORD dwMaxExposureClock);

//-----------------------------------------------------------------------------
//Trigger
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_GetTriggerMode(HANDLE hCamera, PDWORD pdwTriggerMode);
BOOL WINAPI StTrg_SetTriggerMode(HANDLE hCamera, DWORD dwTriggerMode);
BOOL WINAPI StTrg_GetTriggerTiming(HANDLE hCamera, DWORD dwTriggerTimingType, PDWORD pdwValue);
BOOL WINAPI StTrg_SetTriggerTiming(HANDLE hCamera, DWORD dwTriggerTimingType, DWORD dwValue);
BOOL WINAPI StTrg_SoftTrigger(HANDLE hCamera);
BOOL WINAPI StTrg_SoftSubTrigger(HANDLE hCamera);
BOOL WINAPI StTrg_TriggerReadOut(HANDLE hCamera);

//-----------------------------------------------------------------------------
//IOPin
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_GetIOPinDirection(HANDLE hCamera, PDWORD pdwDirection);
BOOL WINAPI StTrg_SetIOPinDirection(HANDLE hCamera, DWORD dwDirection);
BOOL WINAPI StTrg_GetIOPinPolarity(HANDLE hCamera, PDWORD pdwPolarity);
BOOL WINAPI StTrg_SetIOPinPolarity(HANDLE hCamera, DWORD dwPolarity);
BOOL WINAPI StTrg_GetIOPinMode(HANDLE hCamera, DWORD bytePinNo, PDWORD pdwMode);
BOOL WINAPI StTrg_SetIOPinMode(HANDLE hCamera, DWORD bytePinNo, DWORD dwMode);
BOOL WINAPI StTrg_GetIOPinStatus(HANDLE hCamera, PDWORD pdwStatus);
BOOL WINAPI StTrg_SetIOPinStatus(HANDLE hCamera, DWORD dwStatus);
BOOL WINAPI StTrg_GetSwStatus(HANDLE hCamera, PDWORD pdwSwStatus);
BOOL WINAPI StTrg_GetLEDStatus(HANDLE hCamera, PDWORD pdwLEDStatus);
BOOL WINAPI StTrg_SetLEDStatus(HANDLE hCamera, DWORD dwLEDStatus);

//-----------------------------------------------------------------------------
//Timeout
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_GetTimeOut(HANDLE hCamera, DWORD dwTimeOutType, PDWORD pdwTimeOutMS);
BOOL WINAPI StTrg_SetTimeOut(HANDLE hCamera, DWORD dwTimeOutType, DWORD dwTimeOutMS);

//-----------------------------------------------------------------------------
//Callback Function
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_SetExposureEndCallback(HANDLE hCamera, funcExposureEndCallback func, PVOID pvContext);
BOOL WINAPI StTrg_SetTransferEndCallback(HANDLE hCamera, funcTransferEndCallback func, PVOID pvContext);
BOOL WINAPI StTrg_SetRcvErrorCallback(HANDLE hCamera, funcRcvErrorCallback func, PVOID pvContext);

//-----------------------------------------------------------------------------
//Image Acquisition
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_SetRcvMsgWnd(HANDLE hCamera, HWND hWnd);
BOOL WINAPI StTrg_SetRawSnapShotBufferCount(HANDLE hCamera, DWORD dwBufferCount);
BOOL WINAPI StTrg_TakeRawSnapShot(HANDLE hCamera, PBYTE pbyteRaw, DWORD dwBufferSize, PDWORD pdwNumberOfByteTrans, PDWORD pdwFrameNo, DWORD dwMilliseconds);

//-----------------------------------------------------------------------------
//Transfer Control
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_StartTransfer(HANDLE hCamera);
BOOL WINAPI StTrg_StopTransfer(HANDLE hCamera);

//-----------------------------------------------------------------------------
//Noise Reduction
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_NoiseReduction(HANDLE hCamera, DWORD dwNoiseReductionMode, DWORD dwWidth, DWORD dwHeight, WORD wColorArray, PBYTE pbyteRaw);

//-----------------------------------------------------------------------------
//White Balance Control
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_GetWhiteBalanceMode(HANDLE hCamera, PBYTE pbyteWBMode);
BOOL WINAPI StTrg_SetWhiteBalanceMode(HANDLE hCamera, BYTE byteWBMode);
BOOL WINAPI StTrg_GetWhiteBalanceGain(HANDLE hCamera, PWORD pwWBGainR, PWORD pwWBGainGr, PWORD pwWBGainGb, PWORD pwWBGainB);
BOOL WINAPI StTrg_SetWhiteBalanceGain(HANDLE hCamera, WORD wWBGainR, WORD wWBGainGr, WORD wWBGainGb, WORD wWBGainB);
BOOL WINAPI StTrg_WhiteBalance(HANDLE hCamera, PBYTE pbyteRaw);

//-----------------------------------------------------------------------------
//Gamma
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_GetGammaModeEx(HANDLE hCamera, BYTE byteGammaTarget, PBYTE pbyteGammaMode, PWORD pwGamma, PSHORT pshtBrightness, PBYTE pbyteContrast, PBYTE pbyteGammaTable);
BOOL WINAPI StTrg_SetGammaModeEx(HANDLE hCamera, BYTE byteGammaTarget, BYTE byteGammaMode, WORD wGamma, SHORT shtBrightness, BYTE byteContrast, PBYTE pbyteGammaTable);
BOOL WINAPI StTrg_RawColorGamma(HANDLE hCamera, DWORD dwWidth, DWORD dwHeight, WORD wColorArray, PBYTE pbyteRaw);
BOOL WINAPI StTrg_BGRGamma(HANDLE hCamera, DWORD dwWidth, DWORD dwHeight, DWORD dwPixelFormat, PBYTE pbyteBGR);
BOOL WINAPI StTrg_GetCameraGammaValue(HANDLE hCamera, PWORD pwValue);
BOOL WINAPI StTrg_SetCameraGammaValue(HANDLE hCamera, WORD wValue);

//-----------------------------------------------------------------------------
//Mirror Rotation
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_MirrorRotation(BYTE byteMirrorMode, BYTE byteRotationMode, PDWORD pdwWidth, PDWORD pdwHeight, PWORD pwColorArray, PBYTE pbyteRaw);
BOOL WINAPI StTrg_GetMirrorMode(HANDLE hCamera, PBYTE pbyteMirrorMode);
BOOL WINAPI StTrg_SetMirrorMode(HANDLE hCamera, BYTE byteMirrorMode);

//-----------------------------------------------------------------------------
//Color Interpolation
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_ColorInterpolation(DWORD dwWidth, DWORD dwHeight, WORD wColorArray, PBYTE pbyteRaw, PBYTE pbyteBGR, BYTE byteColorInterpolationMethod, DWORD dwPixelFormat);

//-----------------------------------------------------------------------------
//Hue Saturation/Color Matrix
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_GetHueSaturationMode(HANDLE hCamera, PBYTE pbyteHueSaturationMode, PSHORT pshtHue, PWORD pwSaturation);
BOOL WINAPI StTrg_SetHueSaturationMode(HANDLE hCamera, BYTE byteHueSaturationMode, SHORT shtHue, WORD wSaturation);
BOOL WINAPI StTrg_GetColorMatrix(HANDLE hCamera, PBYTE pbyteColorMatrixMode, PSHORT pshtColorMatrix);
BOOL WINAPI StTrg_SetColorMatrix(HANDLE hCamera, BYTE byteColorMatrixMode, PSHORT pshtColorMatrix);
BOOL WINAPI StTrg_HueSaturationColorMatrix(HANDLE hCamera, DWORD dwWidth, DWORD dwHeight, DWORD dwPixelFormat, PBYTE pbyteBGR);

//-----------------------------------------------------------------------------
//Sharpness
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_GetSharpnessMode(HANDLE hCamera, PBYTE pbyteSharpnessMode, PWORD pwSharpnessGain, PBYTE pbyteSharpnessCoring);
BOOL WINAPI StTrg_SetSharpnessMode(HANDLE hCamera, BYTE byteSharpnessMode, WORD wSharpnessGain, BYTE byteSharpnessCoring);
BOOL WINAPI StTrg_Sharpness(HANDLE hCamera, DWORD dwWidth, DWORD dwHeight, DWORD dwPixelFormat, PBYTE pbyteGrayOrBGR);

//-----------------------------------------------------------------------------
//Save Image
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_SaveImageA(DWORD dwWidth, DWORD dwHeight, DWORD dwPixelFormat, PBYTE pbyteGrayOrBGR, PCSTR pszFileName, DWORD dwParam);
BOOL WINAPI StTrg_SaveImageW(DWORD dwWidth, DWORD dwHeight, DWORD dwPixelFormat, PBYTE pbyteGrayOrBGR, PCWSTR pszFileName, DWORD dwParam);

//-----------------------------------------------------------------------------
//Defect Pixel Correction
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_GetEnableDefectPixelCorrectionCount(HANDLE hCamera, PWORD pwCount);
BOOL WINAPI StTrg_GetDefectPixelCorrectionMode(HANDLE hCamera, PWORD pwMode);
BOOL WINAPI StTrg_SetDefectPixelCorrectionMode(HANDLE hCamera, WORD wMode);
BOOL WINAPI StTrg_GetDefectPixelCorrectionPosition(HANDLE hCamera, WORD wIndex, PDWORD pdwX, PDWORD pdwY);
BOOL WINAPI StTrg_SetDefectPixelCorrectionPosition(HANDLE hCamera, WORD wIndex, DWORD dwX, DWORD dwY);
BOOL WINAPI StTrg_DetectDefectPixel(HANDLE hCamera, DWORD dwWidth, DWORD dwHeight, PBYTE pbyteRaw, WORD wThreashold);

//-----------------------------------------------------------------------------
//Preview
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_Draw(HANDLE hCamera, HDC hDC, int DestOffsetX, int DestOffsetY, DWORD dwDestWidth, DWORD dwDestHeight, int SrcOffsetX, int SrcOffsetY, DWORD dwSrcWidth, DWORD dwSrcHeight, DWORD dwOrgWidth, DWORD dwOrgHeight, PBYTE pbyteGrayOrBGR, DWORD dwPixelFormat);

//-----------------------------------------------------------------------------
//For Specific Camera
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_GetIOARegister(HANDLE hCamera, DWORD dwStartAdd, DWORD dwEndAdd, PWORD pwValue);
BOOL WINAPI StTrg_SetIOARegister(HANDLE hCamera, DWORD dwStartAdd, DWORD dwEndAdd, PWORD pwValue);
BOOL WINAPI StTrg_GetITARegister(HANDLE hCamera, DWORD dwStartAdd, DWORD dwEndAdd, PWORD pwValue);
BOOL WINAPI StTrg_SetITARegister(HANDLE hCamera, DWORD dwStartAdd, DWORD dwEndAdd, PWORD pwValue);
BOOL WINAPI StTrg_GetJBARegister(HANDLE hCamera, DWORD dwStartAdd, DWORD dwEndAdd, PWORD pwValue);
BOOL WINAPI StTrg_SetJBARegister(HANDLE hCamera, DWORD dwStartAdd, DWORD dwEndAdd, PWORD pwValue);

//-----------------------------------------------------------------------------
//Other
//-----------------------------------------------------------------------------
BOOL WINAPI StTrg_GetProcessorIdleState(PDWORD pdwAC, PDWORD pdwDC);
BOOL WINAPI StTrg_SetProcessorIdleState(DWORD dwAC, DWORD dwDC);
BOOL WINAPI StTrg_SetDigitalClamp(HANDLE hCamera, WORD wValue);
BOOL WINAPI StTrg_GetDigitalClamp(HANDLE hCamera, PWORD pwValue);
BOOL WINAPI StTrg_ClearBuffer(HANDLE hCamera);
//Use the correct version dependig on the UNICODE identifier
#ifdef UNICODE
#define StTrg_SaveImage StTrg_SaveImageW
#define StTrg_ReadCameraUserID StTrg_ReadCameraUserIDW
#define StTrg_WriteCameraUserID StTrg_WriteCameraUserIDW
#define StTrg_WriteSettingFile StTrg_WriteSettingFileW
#define StTrg_ReadSettingFile StTrg_ReadSettingFileW
#define StTrg_GetProductName StTrg_GetProductNameW
#else
#define StTrg_SaveImage StTrg_SaveImageA
#define StTrg_ReadCameraUserID StTrg_ReadCameraUserIDA
#define StTrg_WriteCameraUserID StTrg_WriteCameraUserIDA
#define StTrg_WriteSettingFile StTrg_WriteSettingFileA
#define StTrg_ReadSettingFile StTrg_ReadSettingFileA
#define StTrg_GetProductName StTrg_GetProductNameA
#endif //UNICODE

//Only For Backward Compatibility
#define STCAM_TRIGGER_MODE_READOUT_SOFT 0x00000000
#define STCAM_TRIGGER_MODE_READOUT_HARD 0x00000040
#define STCAM_TRIGGER_MODE_SOURCE_SOFT 0x00000400
#define STCAM_TRIGGER_MODE_SOURCE_HARD 0x00000800
#define STCAM_TRIGGER_TIMING_STROBO_START_DELAY 0x00000001
#define STCAM_TRIGGER_TIMING_STROBO_END_DELAY 0x00000002
#define STCAM_TRIGGER_TIMING_TRIGGER_DELAY 0x00000003
#define STCAM_TRIGGER_TIMING_TRIGGER_PULSE_WIDTH 0x00000004
#define STCAM_OUT_PIN_MODE_GENERAL_OUT 0x0001
#define STCAM_OUT_PIN_MODE_TRIGGER_OUT 0x0010
#define STCAM_OUT_PIN_MODE_TRIGGER_TROUGH_OUT 0x0011
#define STCAM_OUT_PIN_MODE_CCD_PUTTING_OUT_END 0x0013
#define STCAM_OUT_PIN_MODE_STROBO_OUT_SETTING 0x0020
#define STCAM_OUT_PIN_MODE_STROBO_OUT_EXPOSURE 0x0021
#define STCAM_IN_PIN_MODE_GENERAL_IN 0x0001
#define STCAM_IN_PIN_MODE_TRIGGER_IN 0x0010
#define STCAM_IN_PIN_MODE_READOUT 0x0030
#define STCAM_SCAN_MODE_PARTIAL_FREE 0x0008
#define STCAM_SCAN_MODE_BINNING_PARTIAL_FREE 0x0100

//-----------------------------------------------------------------------------
//ALC_MODE
//-----------------------------------------------------------------------------
#define STCAM_ALCMODE_CAMERA_AE_AGC_ON	0x30
#define STCAM_ALCMODE_OFF	0
#define STCAM_ALCMODE_CAMERA_AGC_ON	0x20

//-----------------------------------------------------------------------------
//BINNING_SUM_MODE
//-----------------------------------------------------------------------------
#define STCAM_BINNING_SUM_MODE_OFF	0x0000

//-----------------------------------------------------------------------------
//ALC_MODE
//-----------------------------------------------------------------------------
#define STCAM_ALCMODE_CAMERA_AE_ON	0x10

//-----------------------------------------------------------------------------
//DEFECT_PIXEL_CORRECTION_MODE
//-----------------------------------------------------------------------------
#define STCAM_DEFECT_PIXEL_CORRECTION_OFF	0x0000

//-----------------------------------------------------------------------------
//BINNING_SUM_MODE
//-----------------------------------------------------------------------------
#define STCAM_BINNING_SUM_MODE_H	0x0001

//-----------------------------------------------------------------------------
//DEFECT_PIXEL_CORRECTION_MODE
//-----------------------------------------------------------------------------
#define STCAM_DEFECT_PIXEL_CORRECTION_ON	0x0001

//-----------------------------------------------------------------------------
//ALC_MODE
//-----------------------------------------------------------------------------
#define STCAM_ALCMODE_PC_AE_AGC_ON	0x01
#define STCAM_ALCMODE_PC_AE_ON	0x02
#define STCAM_ALCMODE_PC_AGC_ON	0x03
#define STCAM_ALCMODE_PC_AE_AGC_ONESHOT	0x04
#define STCAM_ALCMODE_PC_AE_ONESHOT	0x05
#define STCAM_ALCMODE_PC_AGC_ONESHOT	0x06

//-----------------------------------------------------------------------------
//ERROR_STCAM
//-----------------------------------------------------------------------------
#define ERR_EXPOSURE_END_DROPPED	0xE0000001
#define ERR_IMAGE_DATA_DROPPED	0xE0000002
#define ERR_TIMEOUT_ST2EE	0xE0000003
#define ERR_TIMEOUT_TE2EE	0xE0000004
#define ERR_TIMEOUT_EE2TE	0xE0000005
#define ERR_TIMEOUT_RO2TE	0xE0000006
#define ERR_INVALID_FUNCTION_WHILE_TRANSFERRING	0xE0000100

//-----------------------------------------------------------------------------
//WM_STCAM
//-----------------------------------------------------------------------------
#define WM_STCAM_TRANSFER_END	0xB101
#define WM_STCAM_EXPOSURE_END	0xB102
#define WM_STCAM_RCV_ERROR	0xB103

//-----------------------------------------------------------------------------
//COLOR_ARRAY
//-----------------------------------------------------------------------------
#define STCAM_COLOR_ARRAY_MONO	0x0001
#define STCAM_COLOR_ARRAY_RGGB	0x0002
#define STCAM_COLOR_ARRAY_GRBG	0x0003
#define STCAM_COLOR_ARRAY_GBRG	0x0004
#define STCAM_COLOR_ARRAY_BGGR	0x0005

//-----------------------------------------------------------------------------
//SCAN_MODE
//-----------------------------------------------------------------------------
#define STCAM_SCAN_MODE_NORMAL	0x0000
#define STCAM_SCAN_MODE_PARTIAL_2	0x0001
#define STCAM_SCAN_MODE_PARTIAL_4	0x0002
#define STCAM_SCAN_MODE_PARTIAL_1	0x0004
#define STCAM_SCAN_MODE_VARIABLE_PARTIAL	0x0008
#define STCAM_SCAN_MODE_BINNING	0x0010
#define STCAM_SCAN_MODE_BINNING_PARTIAL_1	0x0020
#define STCAM_SCAN_MODE_BINNING_PARTIAL_2	0x0040
#define STCAM_SCAN_MODE_BINNING_PARTIAL_4	0x0080
#define STCAM_SCAN_MODE_BINNING_VARIABLE_PARTIAL	0x0100
#define STCAM_SCAN_MODE_AOI	0x8000

//-----------------------------------------------------------------------------
//PIXEL_FORMAT
//-----------------------------------------------------------------------------
#define STCAM_PIXEL_FORMAT_08_MONO_OR_RAW	0x00000001
#define STCAM_PIXEL_FORMAT_24_BGR	0x00000004
#define STCAM_PIXEL_FORMAT_32_BGR	0x00000008

//-----------------------------------------------------------------------------
//PIXEL_FORMAT_FOR_SAVE
//-----------------------------------------------------------------------------
#define STCAM_PIXEL_FORMAT_10_MONO_OR_RAW	0x00000010
#define STCAM_PIXEL_FORMAT_12_MONO_OR_RAW	0x00000020
#define STCAM_PIXEL_FORMAT_16_MONO_OR_RAW	0x00000002

//-----------------------------------------------------------------------------
//COLOR_INTERPOLATION
//-----------------------------------------------------------------------------
#define STCAM_COLOR_INTERPOLATION_NONE_MONO	0
#define STCAM_COLOR_INTERPOLATION_NONE_COLOR	1
#define STCAM_COLOR_INTERPOLATION_NEAREST_NEIGHBOR	2
#define STCAM_COLOR_INTERPOLATION_BILINEAR	3
#define STCAM_COLOR_INTERPOLATION_BILINEAR_FALSE_COLOR_REDUCTION	5
#define STCAM_COLOR_INTERPOLATION_BICUBIC	4

//-----------------------------------------------------------------------------
//WB
//-----------------------------------------------------------------------------
#define STCAM_WB_OFF	0
#define STCAM_WB_MANUAL	1
#define STCAM_WB_FULLAUTO	2
#define STCAM_WB_ONESHOT	3

//-----------------------------------------------------------------------------
//GAMMA_MODE
//-----------------------------------------------------------------------------
#define STCAM_GAMMA_OFF	0
#define STCAM_GAMMA_ON	1
#define STCAM_GAMMA_REVERSE	2
#define STCAM_GAMMA_TABLE	255

//-----------------------------------------------------------------------------
//GAMMA_TARGET
//-----------------------------------------------------------------------------
#define STCAM_GAMMA_TARGET_Y	0
#define STCAM_GAMMA_TARGET_R	1
#define STCAM_GAMMA_TARGET_GR	2
#define STCAM_GAMMA_TARGET_GB	3
#define STCAM_GAMMA_TARGET_B	4

//-----------------------------------------------------------------------------
//SHARPNESS
//-----------------------------------------------------------------------------
#define STCAM_SHARPNESS_OFF	0
#define STCAM_SHARPNESS_ON	1

//-----------------------------------------------------------------------------
//HUE_SATURATION
//-----------------------------------------------------------------------------
#define STCAM_HUE_SATURATION_OFF	0
#define STCAM_HUE_SATURATION_ON	1

//-----------------------------------------------------------------------------
//COLOR_MATRIX
//-----------------------------------------------------------------------------
#define STCAM_COLOR_MATRIX_OFF	0x00
#define STCAM_COLOR_MATRIX_CUSTOM	0xFF

//-----------------------------------------------------------------------------
//MIRROR
//-----------------------------------------------------------------------------
#define STCAM_MIRROR_OFF	0
#define STCAM_MIRROR_HORIZONTAL	1
#define STCAM_MIRROR_VERTICAL	2
#define STCAM_MIRROR_HORIZONTAL_VERTICAL	3

//-----------------------------------------------------------------------------
//MIRROR_CAMERA
//-----------------------------------------------------------------------------
#define STCAM_MIRROR_HORIZONTAL_CAMERA	16
#define STCAM_MIRROR_VERTICAL_CAMERA	32

//-----------------------------------------------------------------------------
//ROTATION
//-----------------------------------------------------------------------------
#define STCAM_ROTATION_OFF	0
#define STCAM_ROTATION_CLOCKWISE_90	1
#define STCAM_ROTATION_COUNTERCLOCKWISE_90	2

//-----------------------------------------------------------------------------
//CLOCK_MODE
//-----------------------------------------------------------------------------
#define STCAM_CLOCK_MODE_NORMAL	0x00000000
#define STCAM_CLOCK_MODE_DIV_2	0x00000001
#define STCAM_CLOCK_MODE_DIV_4	0x00000002
#define STCAM_CLOCK_MODE_VGA_90FPS	0x00000100

//-----------------------------------------------------------------------------
//USBPID
//-----------------------------------------------------------------------------
#define STCAM_USBPID_STC_B33USB	0x0705
#define STCAM_USBPID_STC_C33USB	0x0305
#define STCAM_USBPID_STC_B83USB	0x0805
#define STCAM_USBPID_STC_C83USB	0x0605
#define STCAM_USBPID_STC_TB33USB	0x0906
#define STCAM_USBPID_STC_TC33USB	0x1006
#define STCAM_USBPID_STC_TB83USB	0x1106
#define STCAM_USBPID_STC_TC83USB	0x1206
#define STCAM_USBPID_STC_TB133USB	0x0109
#define STCAM_USBPID_STC_TC133USB	0x0209
#define STCAM_USBPID_STC_TB152USB	0x1306
#define STCAM_USBPID_STC_TC152USB	0x1406
#define STCAM_USBPID_STC_TB202USB	0x1506
#define STCAM_USBPID_STC_TC202USB	0x1606
#define STCAM_USBPID_STC_MB33USB	0x0110
#define STCAM_USBPID_STC_MC33USB	0x0210
#define STCAM_USBPID_STC_MB83USB	0x0310
#define STCAM_USBPID_STC_MC83USB	0x0410
#define STCAM_USBPID_STC_MB133USB	0x0510
#define STCAM_USBPID_STC_MC133USB	0x0610
#define STCAM_USBPID_STC_MB152USB	0x0710
#define STCAM_USBPID_STC_MC152USB	0x0810
#define STCAM_USBPID_STC_MB202USB	0x0910
#define STCAM_USBPID_STC_MC202USB	0x1010
#define STCAM_USBPID_APBWVUSB_LED	0x0509
#define STCAM_USBPID_APCWVUSB_LED	0x0609
#define STCAM_USBPID_STC_MBA5MUSB3	0x0111
#define STCAM_USBPID_STC_MCA5MUSB3	0x0211

//-----------------------------------------------------------------------------
//TRIGGER_MODE
//-----------------------------------------------------------------------------
#define STCAM_TRIGGER_MODE_TYPE_MASK	0x00000003
#define STCAM_TRIGGER_MODE_CAMERA_MEMORY_MASK	0x00000030
#define STCAM_TRIGGER_MODE_READOUT_SOURCE_MASK	0x00000040
#define STCAM_TRIGGER_MODE_EXPEND_MASK	0x00000100
#define STCAM_TRIGGER_MODE_SOURCE_MASK	0x00000C00
#define STCAM_TRIGGER_MODE_EXPTIME_MASK	0x00003000
#define STCAM_TRIGGER_MODE_EXPOSURE_WAIT_HD_MASK	0x00004000
#define STCAM_TRIGGER_MODE_EXPOSURE_WAIT_READOUT_MASK	0x00008000
#define STCAM_TRIGGER_MODE_TRIGGER_MASK_MASK	0x00010000
#define STCAM_TRIGGER_MODE_CMOS_RESET_TYPE_MASK	0x00020000
#define STCAM_TRIGGER_MODE_TYPE_FREE_RUN	0x00000000
#define STCAM_TRIGGER_MODE_TYPE_TRIGGER	0x00000001
#define STCAM_TRIGGER_MODE_TYPE_TRIGGER_RO	0x00000002
#define STCAM_TRIGGER_MODE_EXPTIME_EDGE_PRESET	0x00000000
#define STCAM_TRIGGER_MODE_EXPTIME_PULSE_WIDTH	0x00001000
#define STCAM_TRIGGER_MODE_EXPTIME_START_STOP	0x00002000
#define STCAM_TRIGGER_MODE_SOURCE_NONE	0x00000000
#define STCAM_TRIGGER_MODE_SOURCE_SOFTWARE	0x00000400
#define STCAM_TRIGGER_MODE_SOURCE_HARDWARE	0x00000800
#define STCAM_TRIGGER_MODE_READOUT_SOFTWARE	0x00000000
#define STCAM_TRIGGER_MODE_READOUT_HARDWARE	0x00000040
#define STCAM_TRIGGER_MODE_EXPEND_DISABLE	0x00000000
#define STCAM_TRIGGER_MODE_EXPEND_ENABLE	0x00000100
#define STCAM_TRIGGER_MODE_EXPOSURE_WAIT_HD_OFF	0x00000000
#define STCAM_TRIGGER_MODE_EXPOSURE_WAIT_HD_ON	0x00004000
#define STCAM_TRIGGER_MODE_EXPOSURE_WAIT_READOUT_OFF	0x00000000
#define STCAM_TRIGGER_MODE_EXPOSURE_WAIT_READOUT_ON	0x00008000
#define STCAM_TRIGGER_MODE_CAMERA_MEMORY_TYPE_B	0x00000000
#define STCAM_TRIGGER_MODE_CAMERA_MEMORY_TYPE_A	0x00000010
#define STCAM_TRIGGER_MODE_CAMERA_MEMORY_OFF	0x00000020
#define STCAM_TRIGGER_MODE_TRIGGER_MASK_OFF	0x00000000
#define STCAM_TRIGGER_MODE_TRIGGER_MASK_ON	0x00010000
#define STCAM_TRIGGER_MODE_CMOS_RESET_TYPE_ERS	0x00000000
#define STCAM_TRIGGER_MODE_CMOS_RESET_TYPE_GRR	0x00020000

//-----------------------------------------------------------------------------
//TRIGGER_TIMING
//-----------------------------------------------------------------------------
#define STCAM_TRIGGER_TIMING_EXPOSURE_DELAY	0x00000000
#define STCAM_TRIGGER_TIMING_STROBE_START_DELAY	0x00000001
#define STCAM_TRIGGER_TIMING_STROBE_END_DELAY	0x00000002
#define STCAM_TRIGGER_TIMING_OUTPUT_PULSE_DELAY	0x00000003
#define STCAM_TRIGGER_TIMING_TRIGGER_PULSE_DELAY	0x00000003
#define STCAM_TRIGGER_TIMING_OUTPUT_PULSE_DURATION	0x00000004
#define STCAM_TRIGGER_TIMING_TRIGGER_PULSE_DURATION	0x00000004
#define STCAM_TRIGGER_TIMING_READOUT_DELAY	0x00000005

//-----------------------------------------------------------------------------
//IO_PIN_MODE
//-----------------------------------------------------------------------------
#define STCAM_OUT_PIN_MODE_DISABLE	0x0000
#define STCAM_OUT_PIN_MODE_GENERAL_OUTPUT	0x0001
#define STCAM_OUT_PIN_MODE_TRIGGER_OUTPUT_PROGRAMMABLE	0x0010
#define STCAM_OUT_PIN_MODE_TRIGGER_OUTPUT_LOOP_THROUGH	0x0011
#define STCAM_OUT_PIN_MODE_EXPOSURE_END	0x0012
#define STCAM_OUT_PIN_MODE_CCD_READ_END_OUTPUT	0x0013
#define STCAM_OUT_PIN_MODE_STROBE_OUTPUT_PROGRAMMABLE	0x0020
#define STCAM_OUT_PIN_MODE_STROBE_OUTPUT_EXPOSURE	0x0021
#define STCAM_OUT_PIN_MODE_TRIGGER_VALID_OUT	0x0014
#define STCAM_IN_PIN_MODE_DISABLE	0x0000
#define STCAM_IN_PIN_MODE_GENERAL_INPUT	0x0001
#define STCAM_IN_PIN_MODE_TRIGGER_INPUT	0x0010
#define STCAM_IN_PIN_MODE_READOUT_INPUT	0x0030
#define STCAM_IN_PIN_MODE_SUB_TRIGGER_INPUT	0x0040

//-----------------------------------------------------------------------------
//TIMEOUT
//-----------------------------------------------------------------------------
#define STCAM_TIMEOUT_ST2EE	0x00000000
#define STCAM_TIMEOUT_TE2EE	0x00000001
#define STCAM_TIMEOUT_EE2TE	0x00000002
#define STCAM_TIMEOUT_RO2TE	0x00000003

//-----------------------------------------------------------------------------
//CAMERA_FUNCTION
//-----------------------------------------------------------------------------
#define STCAM_CAMERA_FUNCTION_VGA90FPS	0
#define STCAM_CAMERA_FUNCTION_STARTSTOP	1
#define STCAM_CAMERA_FUNCTION_MEMORY	2
#define STCAM_CAMERA_FUNCTION_IO_CHANGE_DIRECTION	4
#define STCAM_CAMERA_FUNCTION_LED	5
#define STCAM_CAMERA_FUNCTION_DISABLE_DIP_SW	7
#define STCAM_CAMERA_FUNCTION_10BIT	8
#define STCAM_CAMERA_FUNCTION_12BIT	15
#define STCAM_CAMERA_FUNCTION_CDS_GAIN_TYPE	16
#define STCAM_CAMERA_FUNCTION_PHOTOCOUPLER	17
#define STCAM_CAMERA_FUNCTION_TRIGGER_MASK	18
#define STCAM_CAMERA_FUNCTION_V_BLANK_FOR_FPS	21
#define STCAM_CAMERA_FUNCTION_MIRROR_HORIZONTAL	22
#define STCAM_CAMERA_FUNCTION_MIRROR_VERTICAL	23
#define STCAM_CAMERA_FUNCTION_AWB	24
#define STCAM_CAMERA_FUNCTION_AGC	25
#define STCAM_CAMERA_FUNCTION_AE	26
#define STCAM_CAMERA_FUNCTION_IO_UNIT_US	27
#define STCAM_CAMERA_FUNCTION_CMOS_RESET_TYPE_ERS_GRR	28
#define STCAM_CAMERA_FUNCTION_DISABLED_READOUT	29
#define STCAM_CAMERA_FUNCTION_DIGITAL_CLAMP	55
#define STCAM_CAMERA_FUNCTION_TRIGGER_VALID_OUT	56
#define STCAM_CAMERA_FUNCTION_CAMERA_GAMMA	57
#define STCAM_CAMERA_FUNCTION_STORE_CAMERA_SETTING	58
#define STCAM_CAMERA_FUNCTION_DEFECT_PIXEL_CORRECTION	59
#define STCAM_CAMERA_FUNCTION_DISABLE_MEMORY_TYPE_SELECTION	60
#define STCAM_CAMERA_FUNCTION_BINNING_COLUMN_SUM	61
#define STCAM_CAMERA_FUNCTION_DISABLE_EXPOSURE_START_WAIT_HD	62
#define STCAM_CAMERA_FUNCTION_DISABLE_EXPOSURE_START_WAIT_READ_OUT	63
#define STCAM_CAMERA_FUNCTION_TRIGGER	256
#define STCAM_CAMERA_FUNCTION_DIGITAL_GAIN	257
#define STCAM_CAMERA_FUNCTION_VARIABLE_PARTIAL	258
#define STCAM_CAMERA_FUNCTION_BINNING_PARTIAL	259
#define STCAM_CAMERA_FUNCTION_IO	260
#define STCAM_CAMERA_FUNCTION_RESET_FRAME_COUNTER	261

//-----------------------------------------------------------------------------
//NOISE_REDUCTION
//-----------------------------------------------------------------------------
#define STCAM_NR_OFF	0x00000000
#define STCAM_NR_EASY	0x00000001
#define STCAM_NR_COMPREX	0x00000002
#define STCAM_NR_DARK_CL	0x80000000

//-----------------------------------------------------------------------------
//LED_STATUS
//-----------------------------------------------------------------------------
#define STCAM_LED_GREEN_ON	0x00000001
#define STCAM_LED_RED_ON	0x00000002

//-----------------------------------------------------------------------------
//TRANSFER_BITS_PER_PIXEL
//-----------------------------------------------------------------------------
#define STCAM_TRANSFER_BITS_PER_PIXEL_08	0x00000001
#define STCAM_TRANSFER_BITS_PER_PIXEL_10	0x00000002
#define STCAM_TRANSFER_BITS_PER_PIXEL_12	0x00000004
#define STCAM_TRANSFER_BITS_PER_PIXEL_RAW_08	0x00000001
#define STCAM_TRANSFER_BITS_PER_PIXEL_RAW_10	0x00000002
#define STCAM_TRANSFER_BITS_PER_PIXEL_RAW_12	0x00000004
#define STCAM_TRANSFER_BITS_PER_PIXEL_RAW_14	0x00000008
#define STCAM_TRANSFER_BITS_PER_PIXEL_RAW_16	0x00000010
#define STCAM_TRANSFER_BITS_PER_PIXEL_MONO_08	0x00000020
#define STCAM_TRANSFER_BITS_PER_PIXEL_MONO_10	0x00000040
#define STCAM_TRANSFER_BITS_PER_PIXEL_MONO_12	0x00000080
#define STCAM_TRANSFER_BITS_PER_PIXEL_MONO_14	0x00000100
#define STCAM_TRANSFER_BITS_PER_PIXEL_MONO_16	0x00000200
#define STCAM_TRANSFER_BITS_PER_PIXEL_BGR_08	0x00000400
#define STCAM_TRANSFER_BITS_PER_PIXEL_BGR_10	0x00000800

//-----------------------------------------------------------------------------
//JBA_REG_ADDRESS
//-----------------------------------------------------------------------------
#define JBA_REG_ADD_HDR_MODE	0x03
#define JBA_REG_ADD_T2_RATIO	0x04
#define JBA_REG_ADD_T3_RATIO	0x05
#define JBA_REG_ADD_V1_STEP	0x06
#define JBA_REG_ADD_V2_STEP	0x07
#define JBA_REG_ADD_V3_STEP	0x08
#define JBA_REG_ADD_ADC_MODE	0x1F
#define JBA_REG_ADD_LED1	0x20
#define JBA_REG_ADD_LED2	0x21

//-----------------------------------------------------------------------------
//CAMERA_SETTING
//-----------------------------------------------------------------------------
#define STCAM_CAMERA_SETTING_INITIALIZE	0x8000
#define STCAM_CAMERA_SETTING_WRITE	0x2000
#define STCAM_CAMERA_SETTING_READ	0x1000
#define STCAM_CAMERA_SETTING_STANDARD	0x0800
#define STCAM_CAMERA_SETTING_DEFECT_PIXEL_POSITION	0x0400
#ifdef __cplusplus
};
#endif  //__cplusplus
#endif //__ST_TRG_API_H

