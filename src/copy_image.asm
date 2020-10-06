; converted from 4ColorDemo

GLOBAL _copy_image_gddram

; from 48 to 63
DEFINE SYNC_LINE_NUM "#55"

DEFINE PRC_CNT "[BR:8Ah]"
DEFINE LCD_CTRL "[20FEh]"
DEFINE LCD_DATA "[20FFh]"

WRITE_1 MACRO OFFSET
    LD [IX], [BR:OFFSET]
    ENDM

WRITE_16 MACRO START
    WRITE_1 START * 10h + 0
    WRITE_1 START * 10h + 1
    WRITE_1 START * 10h + 2
    WRITE_1 START * 10h + 3
    WRITE_1 START * 10h + 4
    WRITE_1 START * 10h + 5
    WRITE_1 START * 10h + 6
    WRITE_1 START * 10h + 7
    WRITE_1 START * 10h + 8
    WRITE_1 START * 10h + 9
    WRITE_1 START * 10h + 10
    WRITE_1 START * 10h + 11
    WRITE_1 START * 10h + 12
    WRITE_1 START * 10h + 13
    WRITE_1 START * 10h + 14
    WRITE_1 START * 10h + 15
    ENDM

DOROW MACRO
    INC H
    LD EP, #00
    LD LCD_CTRL, H
    LD LCD_CTRL, L
    LD EP, A
    ENDM

DEFSECT ".copy_image_gddram", CODE
SECT ".copy_image_gddram"

_copy_image_gddram:
    
waitsyncloop:
    CP PRC_CNT, SYNC_LINE_NUM
    JRL NZ, waitsyncloop
    
    LD BR, A
    LD A, B
    
    LD IX, #20FFh
    LD HL, #0B010h
    
    LD LCD_CTRL, H
    LD LCD_CTRL, L
    
    LD EP, A
    
    WRITE_16 0
    WRITE_16 1
    WRITE_16 2
    WRITE_16 3
    WRITE_16 4
    WRITE_16 5
    
    DOROW
    
    WRITE_16 6
    WRITE_16 7
    WRITE_16 8
    WRITE_16 9
    WRITE_16 10
    WRITE_16 11

    DOROW
    
    WRITE_16 12
    WRITE_16 13
    WRITE_16 14
    WRITE_16 15
    
    INC BR
    
    WRITE_16 0
    WRITE_16 1
    
    DOROW
    
    WRITE_16 2
    WRITE_16 3
    WRITE_16 4
    WRITE_16 5
    WRITE_16 6
    WRITE_16 7
    
    DOROW
    
    WRITE_16 8
    WRITE_16 9
    WRITE_16 10
    WRITE_16 11
    WRITE_16 12
    WRITE_16 13
    
    DOROW
    
    WRITE_16 14
    WRITE_16 15
    
    INC BR
    
    WRITE_16 0
    WRITE_16 1
    WRITE_16 2
    WRITE_16 3
    
    DOROW
    
    WRITE_16 4
    WRITE_16 5
    WRITE_16 6
    WRITE_16 7
    WRITE_16 8
    WRITE_16 9
    
    DOROW
    
    WRITE_16 10
    WRITE_16 11
    WRITE_16 12
    WRITE_16 13
    WRITE_16 14
    WRITE_16 15
    
    LD BR, #20h
    LD EP, #00h
    
    RET

