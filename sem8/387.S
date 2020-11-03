        .intel_syntax noprefix
        .text
        .global calc
calc:
        push    ebp
        mov     ebp, esp
        fld     qword ptr [ebp+16]
        fadd    qword ptr [ebp+8]
        fild    dword ptr [ebp+32]
        fadd    qword ptr [ebp+24]
        pop     ebp
        fdivp   st(1), st
        ret
