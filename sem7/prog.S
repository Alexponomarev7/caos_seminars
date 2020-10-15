		.global summ
        .intel_syntax noprefix
        .text
summ:
        // Prologue
        push    ebx

        mov     ecx, N
.Loop:
        // R[N-1] = A[N-1] + B[N-1]
        mov     ebx, ecx
        dec     ebx  // ebx = N-1
        mov     edx, A
        mov     eax, [edx + 4*ebx]
        mov     edx, B
        add     eax, [edx + 4*ebx]  // += B[N-1]
        mov     edx, R
        mov     [edx + 4*ebx], eax // R[N-1] = %eax
        loop    .Loop

        // Epilogue
        pop     ebx
        ret

        .global everyday795
everyday795:
        // prologue
        push    ebp
        mov     ebp, esp
        push    ebx

        sub     esp, 4 // for local temp variable
        sub     esp, 8 // for scanf arguments
        // &Temp = esp+8
        mov     eax, esp
        add     eax, 8
        mov     [esp+4], eax
        mov     ecx, offset scanf_format_string
        mov     [esp+0], ecx
        call    scanf
        mov     ebx, [esp+8]
        imul    ebx, [ebp+8]
        add     ebx, [ebp+12]
        mov     ecx, printf_format_string_ptr
        mov     [esp+0], ecx
        mov     [esp+4], ebx
        call    printf
        add     esp, 8

        // epilogue
        add     esp, 4
        pop     ebx
        pop     ebp
        ret

scanf_format_string:
        .string "%d"
printf_format_string_ptr:
        .long   printf_format_string

        .data
printf_format_string:
        .string "%d\n"

