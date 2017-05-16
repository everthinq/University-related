.686
.model flat,stdcall
option casemap:none

 include \masm32\include\msvcrt.inc
 include /masm32/include/kernel32.inc 

 includelib /masm32/lib/kernel32.lib
 includelib \masm32\lib\msvcrt.lib

.data 	
 msg2 byte 'Please, enter n elements:',0  
 msg3 byte 'Enter element:',0
 msg4 byte 'Summa = ',0
 msg1310 byte 13,10
 
.code
 
start proc
local x,count,sum :dword 
invoke crt_printf,addr msg2
invoke crt_printf,addr msg1310 
	lea edi,count 
	push 'd%' 
	mov ebx,esp
invoke crt_scanf,ebx,edi
	mov esi,count
	lea edi,x
metka:
invoke crt_printf,addr msg3
invoke crt_printf,addr msg1310
invoke crt_scanf,ebx,edi 
 	mov eax,x
  
 	.if esi == count 
  	mov sum,eax 
	.endif
 	.if esi != count
 	add sum,eax
 	.endif 
	dec esi  

	jnz metka
invoke crt_printf,addr msg4  
invoke crt_printf,ebx,sum
invoke crt_printf,addr msg1310

 invoke crt__getch
 invoke ExitProcess, 0
start endp
end start