@ECHO OFF
cd ..\TPMakerExe\
call .\Config\make_config.bat

setlocal
echo.
echo ================================================================================
echo ================================================================================> %LOG_FILE%


echo Step 0 : Clear Target...
echo Step 0 : Clear Target...>> %LOG_FILE%
  del .\Image\*.* /F /S /Q 1>> %LOG_FILE% 2>&1
  echo.
  echo. 1>> %LOG_FILE% 2>&1


echo Step 1 : Read Date...
echo Step 1 : Read Date...>> %LOG_FILE%
  SET datecode=%Date:~0,4%%Date:~5,2%%Date:~8,2%
  SET vertr=V100
  echo Date: %datecode%>> %LOG_FILE%
  echo Version: %vertr%>> %LOG_FILE%
  echo.
  echo.>> %LOG_FILE%



echo Step 2 : Copy images...
echo Step 2 : Copy images...>> %LOG_FILE%
  copy ..\MDK_ARMv5\HT32\AP\AP.axf.bin\AP .\Image\%datecode%_%vertr%_AP.bin 1>> %LOG_FILE% 2>&1
  copy ..\MDK_ARMv5\HT32\AP\AP.hex        .\Image\%datecode%_%vertr%_IAP_AP.hex 1>> %LOG_FILE% 2>&1
  echo.
  echo.>> %LOG_FILE%


echo Step 3 : Make IAP exe file...
echo Step 3 : Make IAP exe file...>> %LOG_FILE%
  for /f "tokens=*" %%i in ('.\_TPMaker\HTEncrypt32.exe /s ..\Image\%datecode%_%vertr%_AP.bin ..\Config\Encrypt_Key.bin ..\Image\%datecode%_%vertr%_AP_Encrypt.bin') do set digest=%%i
  echo Digest is %digest%
  echo Digest is %digest%>> %LOG_FILE%

echo Step 3.1 : Press "Make" button, select filename
echo            "...TPMakerExe\images\%datecode%_IAP_%vertr%.exe"....
echo DUMMY_FILE_FOR_SET_FILENAME > .\Image\%datecode%_IAP_%vertr%.exe

  copy .\config\setting.ini .\_TPMaker\setting.ini /Y 1>> %LOG_FILE% 2>&1
  gsar -s_HT32_ENNAME -r"%datecode%_%vertr%_AP_Encrypt.bin" .\_TPMaker\setting.ini  -o 1>> %LOG_FILE% 2>&1
  gsar -s_HT32_VER    -r"%vertr%"                           .\_TPMaker\setting.ini  -o 1>> %LOG_FILE% 2>&1
  gsar -s_HT32_VID_AP -r"%VID_AP%"                          .\_TPMaker\setting.ini  -o 1>> %LOG_FILE% 2>&1
  gsar -s_HT32_PID_AP -r"%PID_AP%"                          .\_TPMaker\setting.ini  -o 1>> %LOG_FILE% 2>&1
  gsar -s_HT32_VID    -r"%VID_IAP%"                         .\_TPMaker\setting.ini  -o 1>> %LOG_FILE% 2>&1
  gsar -s_HT32_PID    -r"%PID_IAP%"                         .\_TPMaker\setting.ini  -o 1>> %LOG_FILE% 2>&1
  gsar -s_HT32_DIG    -r"%digest%"                          .\_TPMaker\setting.ini  -o 1>> %LOG_FILE% 2>&1

  .\_TPMaker\TinyProgrammerMakerIII.exe



:MAKE_END
echo ================================================================================
echo All operation success!....
echo ================================================================================>>%LOG_FILE%
echo All operation success!....>>%LOG_FILE%
echo.


