.686
.model flat,stdcall
option casemap:none
 
include \masm32\include\msvcrt.inc
includelib \masm32\lib\msvcrt.lib

.data 
main_msg db 'Program of additional', 0
msg1 db 'Enter first variable, please...', 0
msg2 db 'Enter second variable, please...', 0
msg1310 byte 13, 10			; ������� ������ '\n'
 
.code
start proc
local x,y:dword
 
mov esi,2
lea edi,x
push 'd%'
mov ebx,esp

invoke crt_printf, main_msg
 
@@:
invoke crt_scanf,ebx,edi  ; ������ ��� �����
sub edi,4
dec esi
jnz @b
 
mov eax,y             ; ������ �������� (����������)
add eax,x
 
invoke crt_printf,ebx,eax ; ������� ��������� ����� ������
add esp,4
 
invoke crt__getch
ret                   ; ���� ����� ���������� ���� ���������� ��������� �� �����,
                      ; �� �� ������ �� � �������
start endp
end start