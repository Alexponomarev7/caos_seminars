        .intel_syntax noprefix
        .text
        .global vector_sum
vector_sum:
        push    ebp
        push    esi
        push    edi
        push    ebx
        mov     ebp, esp
        mov     ecx, [ebp+20]
        mov     esi, [ebp+24]
        mov     edi, [ebp+28]
        mov     ebx, [ebp+32]
        mov     eax, 0
Loop:
        movaps  xmm0, [esi+eax*4]
        movaps  xmm1, [edi+eax*4]
        addps   xmm0, xmm1
        movaps  [ebx+eax*4], xmm0
        add     eax, 4
        cmp     eax, ecx
        jl      Loop
        pop     ebx
        pop     edi
                                                              1,1           Top
