set PRJ=example00
set SPG=spgbld.exe
set EMU=C:\evosdkts\evosdk\tools\unreal_evo\unreal

rem del *.spg
rem del *.bin
rem del %PRG%

zcc +zx -vn example00.c -o example00 -lndos
pause

%SPG% -b spg.ini %PRJ%.spg -c 0
%EMU% %PRJ%.spg
pause
