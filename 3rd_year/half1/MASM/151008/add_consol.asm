.386
.model flat, stdcall 
option casemap :none 

include \MASM32\INCLUDE\windows.inc
include \MASM32\INCLUDE\masm32.inc
include \MASM32\INCLUDE\gdi32.inc
include \MASM32\INCLUDE\user32.inc
include \MASM32\INCLUDE\kernel32.inc
includelib \MASM32\LIB\masm32.lib
includelib \MASM32\LIB\gdi32.lib
includelib \MASM32\LIB\user32.lib
includelib \MASM32\LIB\kernel32.lib

.data
A DWORD 100 dup(?)	
B DWORD 100 dup(?)
;msg1 byte "Hello World",0


.code
start: 

invoke	StdIn, ADDR A, 100
	mov edx,A
invoke StdIn, ADDR B,100
	;add  B,eax 
	mov ebx,B
	add edx,ebx

invoke StdOut, ADDR B
invoke	StdIn, ADDR A, 100

invoke ExitProcess,0
end start 