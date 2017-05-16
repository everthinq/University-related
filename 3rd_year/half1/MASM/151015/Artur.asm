 .386
 .model flat,stdcall
option casemap:none

include \masm32\include\msvcrt.inc
includelib \masm32\lib\msvcrt.lib
include C:\masm32\include\windows.inc	
					
include <\masm32\include\kernel32.inc>
include <\masm32\include\user32.inc>

includelib <\masm32\lib\kernel32.lib>
includelib <\masm32\lib\user32.lib>

SetConsoleTitleA PROTO :DWORD
GetStdHandle PROTO     :DWORD
WriteConsoleA PROTO    :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExitProcess PROTO      :DWORD
Sleep PROTO            :DWORD

 .const

sConsoleTitle  db 'Program for add',0
sWriteText  db 'Enter 2 numbers:'

 .code

Main PROC
  LOCAL hStdout :DWORD        

  local x,y:dword
 
	mov esi,2
 	lea edi,x
	push 'd%'
	mov ebx,esp

  ;титл консоли
  push offset sConsoleTitle  
  call SetConsoleTitleA

  ;получаем хэндл вывода      
  push -11
  call GetStdHandle
  mov hStdout,EAX

  ;выводим     
  push 0
  push 0
  push 16d
  push offset sWriteText
  push hStdout
  call WriteConsoleA

  ;задержка, чтобы полюбоваться 
  ;push 2000d
 

@@:
invoke crt_scanf,ebx,edi  ; вводим два числа
sub edi,4
dec esi
jnz @b
 
mov eax,y             ; дальше работаем (складываем)
add eax,x
 
invoke crt_printf,ebx,eax ; выводим результат нашей работы
add esp,4

 
invoke crt__getch
ret                   ; если после выполнения этой инструкции программа не упала,
                      ; то со стеком всё в порядке

  ;выход                      
  push 0
  call ExitProcess

Main ENDP
end Main