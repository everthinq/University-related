@echo off

if exist %1.obj del %1.obj
if exist %1.exe del %1.exe

\masm32\bin\ml /c /coff /Zi %1.asm
\masm32\bin\rc %1.rc
if errorlevel 1 goto errasm

if not exist %1.res goto nores

\masm32\bin\Link /SUBSYSTEM:WINDOWS /DEBUG /OPT:NOREF %1.obj %1.res
if errorlevel 1 goto errlink

dir %1.*
goto TheEnd

:nores
\masm32\bin\Link /SUBSYSTEM:WINDOWS /DEBUG /OPT:NOREF %1.obj
if errorlevel 1 goto errlink
dir %1.*
goto TheEnd

:errlink
echo _
echo Link error
goto TheEnd

:errasm
echo _
echo Assembly Error
goto TheEnd

:TheEnd

pause
