.386                           ; 32-������ �����
.model flat, stdcall           ; ���������� � exe-���� � ������������ ������ API
option casemap :none           ; ������������ ��������� � �������� ��������

include <\masm32\include\kernel32.inc>    ; ���������� ���� ���������� �������

includelib <\masm32\lib\kernel32.lib>     ; ���������� ���� ���������

.data                          ; �������� ������� ������ (� ��������� ���������� �������)

     ; ����� ����� �� ���� �������� ����������

.code                          ; �������� ������� ���� (� ��������� ���������� �������)

     ; ����� ����� �� ���� �������� ��������

start:                         ; ���� ������������ ������� �������� ����������

    invoke Beep, 3951, 200     ; ��
    invoke Beep, 4186, 200     ; ��
    invoke Beep, 3951, 200     ; ��
    invoke Beep, 3136, 200     ; ����
    invoke Beep, 2637, 200     ; ��
    invoke Beep, 3951, 200     ; ��

    invoke Beep, 3136, 200     ; ����
    invoke Beep, 3951, 200     ; ��
    invoke Beep, 1975, 200     ; ��
    invoke Beep, 3951, 200     ; ��
    invoke Beep, 3136, 200     ; ����
    invoke Beep, 3951, 200     ; ��

    invoke Beep, 3440, 200     ; ��
    invoke Beep, 3951, 200     ; ��
    invoke Beep, 3440, 200     ; ��
    invoke Beep, 3015, 200     ; ��
    invoke Beep, 2489, 200     ; ��-����
    invoke Beep, 3440, 200     ; ��

    invoke Beep, 3015, 200     ; ��
    invoke Beep, 3440, 200     ; ��
    invoke Beep, 1975, 200     ; ��
    invoke Beep, 3440, 200     ; ��
    invoke Beep, 3015, 200     ; ��
    invoke Beep, 3440, 200     ; ��

    invoke Beep, 3136, 200     ; ����
    invoke Beep, 3440, 200     ; ��
    invoke Beep, 3136, 200     ; ����
    invoke Beep, 2637, 200     ; ��
    invoke Beep, 1975, 200     ; ��
    invoke Beep, 3136, 200     ; ����

    invoke Beep, 3015, 200     ; ��
    invoke Beep, 3136, 200     ; ����
    invoke Beep, 3015, 200     ; ��
    invoke Beep, 2098, 200     ; ��
    invoke Beep, 1720, 200     ; ��
    invoke Beep, 3015, 200     ; ��

    invoke Beep, 2637, 200     ; ��
    invoke Beep, 3015, 200     ; ��
    invoke Beep, 2637, 200     ; ��
    invoke Beep, 2217, 200     ; ��-���� (2217,40)
    invoke Beep, 1568, 200     ; ����
    invoke Beep, 2637, 200     ; ��

    invoke Beep, 2489, 250     ; ��-����
    invoke Beep, 1975, 250     ; ��
    invoke Beep, 3729, 250     ; ��-���� (3729,20)
    invoke Beep, 1975, 250     ; ��
    invoke Beep, 3951, 250     ; ��
    invoke Beep, 1975, 250     ; ��

    invoke ExitProcess, 0      ; �������� Windows � ���������� ���������

end start                      ; ��������� ������� ����