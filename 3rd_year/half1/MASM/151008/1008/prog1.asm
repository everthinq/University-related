;модуль PROG1.ASM
.386
.model flat, stdcall 

proc1   PROTO	;прототип внешней функции

.data
	opx    dd    4
	opy    dd    6
	opz    dd    ?
	
.code
start:
	call    proc1
	mov     opz, eax
	ret

end    start
