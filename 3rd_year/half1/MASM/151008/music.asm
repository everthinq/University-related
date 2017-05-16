.386                           ; 32-битный режим
.model flat, stdcall           ; компил€ци€ в exe-файл с возможностью вызова API
option casemap :none           ; неразличение прописных и строчных символов

include <\masm32\include\kernel32.inc>    ; подключаем файл прототипов функций

includelib <\masm32\lib\kernel32.lib>     ; подключаем файл библиотек

.data                          ; начинает сегмент данных (и завершает предыдущий сегмент)

     ; здесь могло бы быть описание переменных

.code                          ; начинает сегмент кода (и завершает предыдущий сегмент)

     ; здесь могло бы быть описание процедур

start:                         ; сюда операционна€ система передаст управление

    invoke Beep, 3951, 200     ; си
    invoke Beep, 4186, 200     ; до
    invoke Beep, 3951, 200     ; си
    invoke Beep, 3136, 200     ; соль
    invoke Beep, 2637, 200     ; ми
    invoke Beep, 3951, 200     ; си

    invoke Beep, 3136, 200     ; соль
    invoke Beep, 3951, 200     ; си
    invoke Beep, 1975, 200     ; си
    invoke Beep, 3951, 200     ; си
    invoke Beep, 3136, 200     ; соль
    invoke Beep, 3951, 200     ; си

    invoke Beep, 3440, 200     ; л€
    invoke Beep, 3951, 200     ; си
    invoke Beep, 3440, 200     ; л€
    invoke Beep, 3015, 200     ; фа
    invoke Beep, 2489, 200     ; ре-диез
    invoke Beep, 3440, 200     ; л€

    invoke Beep, 3015, 200     ; фа
    invoke Beep, 3440, 200     ; л€
    invoke Beep, 1975, 200     ; си
    invoke Beep, 3440, 200     ; л€
    invoke Beep, 3015, 200     ; фа
    invoke Beep, 3440, 200     ; л€

    invoke Beep, 3136, 200     ; соль
    invoke Beep, 3440, 200     ; л€
    invoke Beep, 3136, 200     ; соль
    invoke Beep, 2637, 200     ; ми
    invoke Beep, 1975, 200     ; си
    invoke Beep, 3136, 200     ; соль

    invoke Beep, 3015, 200     ; фа
    invoke Beep, 3136, 200     ; соль
    invoke Beep, 3015, 200     ; фа
    invoke Beep, 2098, 200     ; до
    invoke Beep, 1720, 200     ; л€
    invoke Beep, 3015, 200     ; фа

    invoke Beep, 2637, 200     ; ми
    invoke Beep, 3015, 200     ; фа
    invoke Beep, 2637, 200     ; ми
    invoke Beep, 2217, 200     ; до-диез (2217,40)
    invoke Beep, 1568, 200     ; соль
    invoke Beep, 2637, 200     ; ми

    invoke Beep, 2489, 250     ; ре-диез
    invoke Beep, 1975, 250     ; си
    invoke Beep, 3729, 250     ; л€-диез (3729,20)
    invoke Beep, 1975, 250     ; си
    invoke Beep, 3951, 250     ; си
    invoke Beep, 1975, 250     ; си

    invoke ExitProcess, 0      ; сообщаем Windows о завершении программы

end start                      ; завершает сегмент кода