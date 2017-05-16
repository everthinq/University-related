.586
.MODEL  FLAT,  STDCALL
.data
arg1	db	03
arg2	db 	07
sum		db	0
.code
my_add	proc
	mov		al, arg1
	mov		bl, arg2
	add		al,bl
my_add	endp
start:
	call	my_add
	end 	start