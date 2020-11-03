        .intel_syntax noprefix
        .text
        .global calc
calc:
        push        ebp
        mov         ebp, esp
        sub         esp, 8
        movsd       xmm0, [ebp+16]
        addsd       xmm0, [ebp+8]
        cvtsi2sd    xmm1, [ebp+32]
        addsd       xmm1, [ebp+24]
        divsd       xmm0, xmm1
        movsd       [ebp-8], xmm0
        fld         qword ptr [ebp-8]
        leave
        ret
