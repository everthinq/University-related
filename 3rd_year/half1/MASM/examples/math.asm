; ��������� 7*30-2*40 � ������� ������ �������
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
wsprintfA PROTO C :DWORD,:VARARG
wsprintf equ 

.data
bufferforstring db 10 dup(0)
titlestring db "���������",0
szformat db "%u",0

.code

start:
mov eax,7 ;������� � EAX 5
mov ecx,30 ;������� � ECX 25
mul ecx ;�������� EAX �� ECX
mov ebx,eax ;������� ���������� EAX � EBX
mov eax,40 ;������� � EAX 40
mov ecx, 2 ;������� � ECX 2
mul ecx ;������� � ECX 2
sub ebx,eax ;�������� �� EBX EAX
invoke wsprintf,addr bufferforstring,addr szformat,eax
invoke MessageBox,0,ADDR bufferforstring,ADDR titlestring,MB_OK ;������� ��������
invoke ExitProcess,0
end start