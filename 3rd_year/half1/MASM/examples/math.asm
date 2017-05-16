; вычисляет 7*30-2*40 с вомощбю строки формата
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
titlestring db "Результат",0
szformat db "%u",0

.code

start:
mov eax,7 ;заносим в EAX 5
mov ecx,30 ;заносим в ECX 25
mul ecx ;умножаем EAX на ECX
mov ebx,eax ;заносим содержимое EAX в EBX
mov eax,40 ;заносим в EAX 40
mov ecx, 2 ;заносим в ECX 2
mul ecx ;заносим в ECX 2
sub ebx,eax ;отнимаем от EBX EAX
invoke wsprintf,addr bufferforstring,addr szformat,eax
invoke MessageBox,0,ADDR bufferforstring,ADDR titlestring,MB_OK ;выводим резульат
invoke ExitProcess,0
end start