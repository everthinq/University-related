This is the example from Iczelion's Win32 Assembly Tutorial part 10.
In order to assemble the example, you have to have ml.exe, link.exe
,nmake.exe and rc.exe in your path.
If they're not in the path, you will have to edit makefile to include the full
path.
You'll have to edit the makefile to correct the path to import libraries in your PC.
Type nmake in the same directory as makefile and the assembly process will
begin.
If you don't want to use the makefile, you can manually assemble the
example with the commands below:

ml /c /coff /Cp dialog.asm
rc dialog.rc
link /SUBSYSTEM:WINDOWS /LIBPATH:c:\masm32\lib dialog.obj dialog.res

The resource script, dialog.rc, requires resource.h which is included in
this package

Any problem: contact me at Iczelion@win32asm.cjb.net
