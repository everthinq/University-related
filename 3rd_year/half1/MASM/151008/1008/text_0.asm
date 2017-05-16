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

; #########################################################################

    .data
      msg1        db "Type something > ",0
      msg2        db "You typed > ",0

; #########################################################################

    .code

    start:
      invoke Main
      invoke ExitProcess,0

; #########################################################################


Main proc

    LOCAL InputBuffer[128]:BYTE

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
    invoke locate,4,8
    invoke StdIn,ADDR InputBuffer,LENGTHOF InputBuffer
 
    ret

Main endp

; #########################################################################

    end start