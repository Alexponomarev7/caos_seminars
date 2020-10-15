        .text
        .global main
main:
        // r4 - stdin, r5 - stdout
        // r6 - symbol, r7 = '0', r8 = '9'
        push    {r4,r5,r7,r8,lr}
        ldr     r4, .Lexterns
        ldr     r4, [r4]
        ldr     r5, .Lexterns+4
        ldr     r5, [r5]
        mov     r7, #48
        mov     r8, #57
.LoopBegin:
        mov     r0, r4
        bl      fgetc
        cmp     r0, #0
        blt     .LoopEnd
        cmp     r0, r7
        blt     .LoopBegin
        cmp     r0, r8
        bgt     .LoopBegin
        mov     r1, r5
        bl      fputc
        b       .LoopBegin
.LoopEnd:
        pop     {r4,r5,r7,r8,lr}
        bx      lr
.Lexterns:
        .word   stdin
        .word   stdout
