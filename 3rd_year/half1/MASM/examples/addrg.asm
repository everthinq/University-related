.486
.model flat, stdcall
option casemap: none
 
include /masm32/include/windows.inc
include /masm32/include/user32.inc
include /masm32/include/kernel32.inc
 
includelib /masm32/lib/user32.lib
includelib /masm32/lib/kernel32.lib

include /masm32/macros/macros.asm 
uselib masm32, comctl32, ws2_32 

.data
msg_title db "Title", 0
A DB 1h
B DB 2h
buffer db 128 dup(?)
format db "%d",0

.code
start:

MOV AL, A
ADD AL, B

invoke wsprintf, addr buffer, addr format, eax
invoke MessageBox, 0, addr buffer, addr msg_title, MB_OK

invoke ExitProcess, 0

end start