.386

.model flat, stdcall 
option casemap :none 

;подключение библиотек,необходимых нам
include \MASM32\INCLUDE\windows.inc
include \MASM32\INCLUDE\masm32.inc
include \MASM32\INCLUDE\gdi32.inc
include \MASM32\INCLUDE\user32.inc
include \MASM32\INCLUDE\kernel32.inc
includelib \MASM32\LIB\masm32.lib
includelib \MASM32\LIB\gdi32.lib
includelib \MASM32\LIB\user32.lib
includelib \MASM32\LIB\kernel32.lib

;раздел, где объ€вл€ютс€ все константы
.const

;раздел, где объ€вл€ютс€ переменные, уже имеющие какое-то значение
.data

;раздел, где объ€вл€ютс€ переменные, еще не имеющие значени€
.data?

.code
start: ;с этого слова начинаетс€ код программы
invoke ExitProcess,0
end start ;с этого слова заканчиваетс€ код программы