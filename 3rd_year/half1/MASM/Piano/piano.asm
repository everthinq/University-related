.386
.model flat,stdcall
option casemap:none

WinMain proto :DWORD,:DWORD,:DWORD,:DWORD

include \masm32\include\windows.inc
include \masm32\include\user32.inc
include \masm32\include\kernel32.inc
include \masm32\include\gdi32.inc
includelib \masm32\lib\user32.lib
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\gdi32.lib

;////////////////////////////////////
RGB macro red,green,blue
        xor eax,eax
        mov ah,blue
        shl eax,8
        mov ah,green
        mov al,red
endm
;////////////////////////////////////
.data
ClassName db "SimpleWinClass",0
AppName  db "Piano",0

Note_1 db"1 - Do7",0
Note_2 db"q - Do6",0
Note_3 db"a - Do5",0
Note_4 db"z - Do4",0
Note_5 db"2 - Re6",0
Note_6 db"w - Re5",0
Note_7 db"s - Re4",0
Note_8 db"x - Re3",0
Note_9 db"3 - Mi6",0
Note_10 db"e - Mi5",0
Note_11 db"d - Mi4",0
Note_12 db"c - Mi3",0
Note_13 db"4 - Fa6",0
Note_14 db"r - Fa5",0
Note_15 db"f - Fa4",0
Note_16 db"v - Fa3",0
Note_17 db"5 - Sol'6",0
Note_18 db"t - Sol'5",0
Note_19 db"g - Sol'4",0
Note_20 db"b - Sol'3",0
Note_21 db"6 - Lya6",0
Note_22 db"y - Lya5",0
Note_23 db"h - Lya4",0
Note_24 db"n - Lya3",0
Note_25 db"7 - Si6",0
Note_26 db"u - Si5",0
Note_27 db"j - Si4",0
Note_28 db"m - Si3",0

FontName db "Times New Roman",0

char WPARAM 255 dup(0)

count DWORD 0
.data?
hInstance HINSTANCE ?
CommandLine LPSTR ?




.code
start:
	invoke GetModuleHandle, NULL
	mov    hInstance,eax
	invoke GetCommandLine
	mov CommandLine,eax
	invoke WinMain, hInstance,NULL,CommandLine, SW_SHOWDEFAULT
	invoke ExitProcess,eax
WinMain proc hInst:HINSTANCE,hPrevInst:HINSTANCE,CmdLine:LPSTR,CmdShow:DWORD
	LOCAL wc:WNDCLASSEX
	LOCAL msg:MSG
	LOCAL hwnd:HWND
	mov   wc.cbSize,SIZEOF WNDCLASSEX
	mov   wc.style, CS_HREDRAW or CS_VREDRAW
	mov   wc.lpfnWndProc, OFFSET WndProc
	mov   wc.cbClsExtra,NULL
	mov   wc.cbWndExtra,NULL
	push  hInst
	pop   wc.hInstance
	mov   wc.hbrBackground,COLOR_WINDOW+1
	mov   wc.lpszMenuName,NULL
	mov   wc.lpszClassName,OFFSET ClassName
	invoke LoadIcon,hInst,500
	mov   wc.hIcon,eax
	mov   wc.hIconSm,eax
	invoke LoadCursor,NULL,IDC_ARROW
	mov   wc.hCursor,eax
	invoke RegisterClassEx, addr wc
	INVOKE CreateWindowEx,NULL,ADDR ClassName,ADDR AppName,\
           WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,\
           CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,\
           hInst,NULL
	mov   hwnd,eax
	INVOKE ShowWindow, hwnd,SW_SHOWNORMAL
	INVOKE UpdateWindow, hwnd
	.WHILE TRUE
                INVOKE GetMessage, ADDR msg,NULL,0,0
                .BREAK .IF (!eax)
                INVOKE TranslateMessage, ADDR msg
                INVOKE DispatchMessage, ADDR msg
	.ENDW
	mov     eax,msg.wParam
	ret
WinMain endp
WndProc proc hWnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
	LOCAL hdc:HDC
	LOCAL ps:PAINTSTRUCT
	LOCAL hfont:HFONT

	.IF uMsg==WM_DESTROY
		invoke PostQuitMessage,NULL		
	.ELSEIF uMsg==WM_CHAR
		mov ebx,count
		push wParam 
		pop  char[ebx]
	;============DO====================
		.if char[ebx]==49
			invoke Beep, 4186, 150 ;До7	
				.elseif char[ebx]=='q'
					invoke Beep, 2093, 150 ;До6
						.elseif char[ebx]=='a'
							invoke Beep, 1046, 150 ;До5
								.elseif char[ebx]=='z'
									invoke Beep, 554, 150 ;До4
	;================RE================
		.elseif char[ebx]==50   
			invoke Beep, 2489, 150 ;Рэ6
				.elseif char[ebx]=='w'  
					invoke Beep, 1244, 150 ;Рэ5
						.elseif char[ebx]=='s'   
							invoke Beep, 622, 150 ;Рэ4
								.elseif char[ebx]=='x'   
									invoke Beep, 311, 150 ;Рэ3
	;===================MI=============	
		.elseif char[ebx]==51
			invoke Beep, 2637, 150 ;Ми6
				.elseif char[ebx]=='e'
					invoke Beep, 1318, 150 ;Ми5
						.elseif char[ebx]=='d'
							invoke Beep,659 , 150 ;Ми4
								.elseif char[ebx]=='c'
									invoke Beep, 329, 150 ;Ми3
	;===================FA====================
		.elseif char[ebx]==52
			invoke Beep, 2959, 150  ; фа6
				.elseif char[ebx]=='r'
					invoke Beep, 1479, 150  ; фа5
						.elseif char[ebx]=='f'
							invoke Beep, 739, 150  ; фа4
								.elseif char[ebx]=='v'
									invoke Beep, 369, 150  ; фа3
	;==========================SOL'===========
		.elseif char[ebx]==53
			invoke Beep, 3322, 150   ;соль6
				.elseif char[ebx]=='t'
					invoke Beep, 1661, 150   ;соль5
						.elseif char[ebx]=='g'
							invoke Beep, 830, 150   ;соль4
								.elseif char[ebx]=='b'
									invoke Beep, 415, 150   ;соль4
	;=======================LYA================
		.elseif char[ebx]==54							
			invoke Beep, 3520, 150   ; ля6
				.elseif char[ebx]=='y'							
					invoke Beep, 1864, 150   ; ля5
						.elseif char[ebx]=='h'							
							invoke Beep,880 , 150   ; ля4
								.elseif char[ebx]=='n'							
									invoke Beep, 440, 150   ; ля5
	;========================SI===============
		.elseif char[ebx]==55					
			invoke Beep, 3951, 150     ; си6
				.elseif char[ebx]=='u'					
					invoke Beep,1975 , 150     ; си5
						.elseif char[ebx]=='j'					
							invoke Beep,987, 150   ; си4
								.elseif char[ebx]=='m'					
									invoke Beep,493, 150  ; си3

			
		.endif
		inc count	
		invoke InvalidateRect, hWnd,NULL,TRUE
	.ELSEIF uMsg==WM_PAINT
		invoke BeginPaint,hWnd, ADDR ps
			mov    hdc,eax
			invoke CreateFont,15,15,0,100,0,0,0,0,OEM_CHARSET,\
                            OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,\
                            DEFAULT_QUALITY,DEFAULT_PITCH or FF_SCRIPT,\
                            ADDR FontName
			invoke SelectObject, hdc, eax
			mov    hfont,eax
			RGB    0,200,0
			invoke SetTextColor,hdc,eax
		    invoke TextOut,hdc,10,20,offset DWORD ptr Note_1,SIZEOF Note_1
			invoke TextOut,hdc,10,60,offset DWORD ptr Note_2,SIZEOF Note_2
			invoke TextOut,hdc,10,100,offset DWORD ptr Note_3,SIZEOF Note_3
			invoke TextOut,hdc,10,140,offset DWORD ptr Note_4,SIZEOF Note_4
			
			RGB    200,0,0
			invoke SetTextColor,hdc,eax
			invoke TextOut,hdc,200,20,offset DWORD ptr Note_5,SIZEOF Note_5
			invoke TextOut,hdc,200,60,offset DWORD ptr Note_6,SIZEOF Note_6
			invoke TextOut,hdc,200,100,offset DWORD ptr Note_7,SIZEOF Note_7
			invoke TextOut,hdc,200,140,offset DWORD ptr Note_8,SIZEOF Note_8
			
			RGB    0,0,200
			invoke SetTextColor,hdc,eax
			invoke TextOut,hdc,400,20,offset DWORD ptr Note_9,SIZEOF Note_9
			invoke TextOut,hdc,400,60,offset DWORD ptr Note_10,SIZEOF Note_10
			invoke TextOut,hdc,400,100,offset DWORD ptr Note_11,SIZEOF Note_11
			invoke TextOut,hdc,400,140,offset DWORD ptr Note_12,SIZEOF Note_12
			
			RGB    100,100,0
			invoke SetTextColor,hdc,eax
			invoke TextOut,hdc,600,20,offset DWORD ptr Note_13,SIZEOF Note_13
			invoke TextOut,hdc,600,60,offset DWORD ptr Note_14,SIZEOF Note_14
			invoke TextOut,hdc,600,100,offset DWORD ptr Note_15,SIZEOF Note_15
			invoke TextOut,hdc,600,140,offset DWORD ptr Note_16,SIZEOF Note_16
			
			RGB    0,100,100
			invoke SetTextColor,hdc,eax
			invoke TextOut,hdc,10,280,offset DWORD ptr Note_17,SIZEOF Note_17
			invoke TextOut,hdc,10,320,offset DWORD ptr Note_18,SIZEOF Note_18
			invoke TextOut,hdc,10,360,offset DWORD ptr Note_19,SIZEOF Note_19
			invoke TextOut,hdc,10,400,offset DWORD ptr Note_20,SIZEOF Note_20
			
			RGB    100,0,100
			invoke SetTextColor,hdc,eax
			invoke TextOut,hdc,200,280,offset DWORD ptr Note_21,SIZEOF Note_21
			invoke TextOut,hdc,200,320,offset DWORD ptr Note_22,SIZEOF Note_22
			invoke TextOut,hdc,200,360,offset DWORD ptr Note_23,SIZEOF Note_23
			invoke TextOut,hdc,200,400,offset DWORD ptr Note_24,SIZEOF Note_24
			
			RGB    50,50,50
			invoke SetTextColor,hdc,eax
			invoke TextOut,hdc,400,280,offset DWORD ptr Note_25,SIZEOF Note_25
			invoke TextOut,hdc,400,320,offset DWORD ptr Note_26,SIZEOF Note_26
			invoke TextOut,hdc,400,360,offset DWORD ptr Note_27,SIZEOF Note_27
			invoke TextOut,hdc,400,400,offset DWORD ptr Note_28,SIZEOF Note_28
		invoke SelectObject,hdc, hfont
		invoke EndPaint,hWnd, ADDR ps
	.ELSE
		invoke DefWindowProc,hWnd,uMsg,wParam,lParam
		ret
	.ENDIF
	xor    eax,eax
	ret
WndProc endp
end start
