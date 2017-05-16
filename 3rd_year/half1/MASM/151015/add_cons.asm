.686
.model flat,stdcall
option casemap:none
 
include \masm32\include\msvcrt.inc
includelib \masm32\lib\msvcrt.lib

message_1  PROTO
message_2  PROTO
message_3  PROTO
message_4  PROTO

.data
msg1 byte 'This is programm of addition',0
msg2 byte 'Enter first number',0
msg3 byte 'Enter second number',0
msg4 byte 'Result of addition',0
msg1310 byte 13, 10	

.code
start proc
local x,y:dword
 
invoke message_1

	mov esi,2
	lea edi,x
	push 'd%'
	mov ebx,esp

invoke message_2

@@:
invoke crt_scanf,ebx,edi  ; вводим два числа
invoke message_3

	sub edi,4
	dec esi
	jnz @b

invoke message_4
	mov eax,y             ; дальше работаем (складываем)
	add eax,x
 
invoke crt_printf,ebx,eax ; выводим результат нашей работы
	add esp,4
 
invoke crt__getch
	ret                   ; если после выполнения этой инструкции программа не упала,

                      ; то со стеком всё в порядке
					  
start endp
;///////////MESSAGE_1////////////////////
message_1 proc

invoke crt_printf,addr msg1
invoke crt_printf,addr msg1310
	ret

message_1 endp
;///////////MESSAGE_2////////////////////
message_2 proc

invoke crt_printf,addr msg2
invoke crt_printf,addr msg1310
	ret

message_2 endp
;///////////MESSAGE_3////////////////////
message_3 proc
	.if esi == 2
invoke crt_printf,addr msg3
invoke crt_printf,addr msg1310
	.endif
	ret

message_3 endp
;///////////MESSAGE_4////////////////////
message_4 proc

invoke crt_printf,addr msg4
invoke crt_printf,addr msg1310
	ret

message_4 endp
end start