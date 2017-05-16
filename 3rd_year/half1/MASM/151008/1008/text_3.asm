; #########################################################################

      .386
      .model flat, stdcall
      option casemap :none   ; case sensitive

; #########################################################################

    ; ------------------------------
    ; Build this app in console mode.
    ; ------------------------------

      include \masm32\include\windows.inc

      include \masm32\include\user32.inc
      include \masm32\include\kernel32.inc
      include \masm32\include\masm32.inc

      includelib \masm32\lib\user32.lib
      includelib \masm32\lib\kernel32.lib
      includelib \masm32\lib\masm32.lib

      Main   PROTO
    ;  strlen PROTO  :DWORD

; #########################################################################

    .data
        msg1        db "Type something > ",0
        msg2        db "You typed > ",0
        msg3        db "input String >",0
        buffer      db 11 dup(0)
        result      db "length = ",0
        szformat    db "%u",0
        InputBuffer db 128 dup (?)

; #########################################################################

    .code

    start:
      invoke Main
      invoke ExitProcess,0

; #########################################################################
strlen  proc arg:DWORD
;-- preppare
    push    ebp
    mov     ebp, esp
    mov     ebx, [ebp+8]
    xor     ecx, ecx
;-- cicle of testing
leb0:
    mov     al, [ebx]
    add     al,0
    jz      leb1        ;-- exit if end 
;--  go to the next character
    inc     ebx
    inc     ecx 
    jmp     leb0
;--  exit
leb1:
    mov     eax, ecx
    pop     ebp
    ret     4
    
strlen  endp

;strlen  PROTO: DWORD

Main proc

    

  ; ----------------
  ; using procedures
  ; ----------------
    invoke ClearScreen

    invoke locate,4,2

    invoke StdOut,ADDR msg1
 
    invoke StdIn,ADDR InputBuffer,LENGTHOF InputBuffer

    invoke locate,4,4 
    invoke StdOut,ADDR msg2
    invoke StdOut,ADDR InputBuffer
    
    ;push    OFFSET InputBuffer
    ;call    strlen
    invoke  strlen, OFFSET InputBuffer
    invoke wsprintf,addr buffer,addr szformat,eax
    
    invoke locate,4,6 
    invoke StdOut,ADDR result
    invoke StdOut,ADDR buffer
    
    invoke locate,4,8
    invoke StdIn,ADDR InputBuffer,LENGTHOF InputBuffer
 
    ret

Main endp

; #########################################################################

    end start