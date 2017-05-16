.386

.model flat, stdcall 
option casemap :none 

;����������� ���������,����������� ���
include \MASM32\INCLUDE\windows.inc
include \MASM32\INCLUDE\masm32.inc
include \MASM32\INCLUDE\gdi32.inc
include \MASM32\INCLUDE\user32.inc
include \MASM32\INCLUDE\kernel32.inc
includelib \MASM32\LIB\masm32.lib
includelib \MASM32\LIB\gdi32.lib
includelib \MASM32\LIB\user32.lib
includelib \MASM32\LIB\kernel32.lib

;������, ��� ����������� ��� ���������
.const
	ARR_LEN EQU 10
;������, ��� ����������� ����������, ��� ������� �����-�� ��������
.data
	ar_a    db  1,2,3,4,5,6,7,8,9,0,1,2,3,4,5
	ar_b    db  5,4,3,2,1,0,9,8,7,6,5,4,3,2,1
	ar_c    db  ARR_LEN dup(0)
	line_end  db  13,10,0
	mes_h   db  "Problem_1 ",0  
	mes_i   db  "index  : ",0
	mes_a   db  "array A: ",0
	mes_b   db  "array B: ",0
	mes_c   db  "array C: ",0
	format  db  "%2u",0
	delim   db  ",  ",0
	buffer  db  100 dup (?)
;������, ��� ����������� ����������, ��� �� ������� ��������
.data?

.code

	;-- ����� ����� �� �����
		;-- EAX - ����� ��� ������
	dig_out   PROC
		invoke wsprintf,addr buffer,addr format,eax
		invoke StdOut,ADDR buffer
		ret
	dig_out   ENDP

	;-- ����� �� ����� �������
		;-- BX - ����� ������ �������
	arr_out   PROC
		mov	  ECX, ARR_LEN
	cikl_out:
		mov	  AL, [EBX]
		push  EBX
		push  ECX
		invoke wsprintf,addr buffer,addr format,eax
		invoke StdOut,ADDR buffer
		invoke StdOut,ADDR delim
		pop	  ECX
		pop	  EBX
		inc   BX
		loop  cikl_out
		ret
	arr_out   ENDP

	;-- ����� �� ����� ��������� �������
	index_out   PROC
		mov	  ECX, ARR_LEN
		mov   AL, 0
	cikl_index:
		push  EAX
		push  ECX
		invoke wsprintf,addr buffer,addr format,eax
		invoke StdOut,ADDR buffer
		invoke StdOut,ADDR delim
		pop	  ECX
		pop	  EAX
		inc   AL
		loop  cikl_index
		ret
	index_out   ENDP

	start: 
	;-- ���������� ���������� � �����
		xor	  eax,eax
		mov   ECX, ARR_LEN
		mov	  EBX, OFFSET ar_a
		mov	  ESI, OFFSET ar_b
		add   ESI, ARR_LEN-1
		mov   EDI, OFFSET ar_c 
	
	;-- ���� ����������
	cikl_calc:
		mov	  AL, [EBX]
		add   AL, [ESI]
		mov   [EDI], AL
		inc   EBX
		dec   ESI
		inc   EDI
		loop  cikl_calc
	
	;-- ����� �� ����� ��������� ���������
		invoke ClearScreen
		invoke locate, 0, 2
		invoke StdOut,ADDR mes_h
		invoke StdOut,ADDR line_end
		invoke StdOut,ADDR line_end
	
	;-- ����� �� ����� �������
		invoke StdOut,ADDR mes_i
		call   index_out
		invoke StdOut,ADDR line_end

;-- ����� �� ����� �
		invoke StdOut,ADDR mes_a
		mov	   EBX, OFFSET ar_a
		call   arr_out
		invoke StdOut,ADDR line_end
;-- ����� �� ����� �
		invoke StdOut,ADDR mes_b
		mov	   EBX, OFFSET ar_b
		call   arr_out
		invoke StdOut,ADDR line_end
;-- ����� �� ����� �
		invoke StdOut,ADDR mes_c
		mov	   EBX, OFFSET ar_c
		call   arr_out
		invoke StdOut,ADDR line_end
;-- �� �������� �������
		invoke StdIn,ADDR buffer,LENGTHOF buffer
	invoke ExitProcess,0
end start ;� ����� ����� ������������� ��� ���������