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

;������, ��� ����������� ����������, ��� ������� �����-�� ��������
.data

;������, ��� ����������� ����������, ��� �� ������� ��������
.data?

.code
start: ;� ����� ����� ���������� ��� ���������
invoke ExitProcess,0
end start ;� ����� ����� ������������� ��� ���������