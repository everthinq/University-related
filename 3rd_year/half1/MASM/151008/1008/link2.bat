if exist %1.exe del %1.exe

\masm32\bin\Link /SUBSYSTEM:CONSOLE /DEBUG /OPT:NOREF %1.obj %2.obj