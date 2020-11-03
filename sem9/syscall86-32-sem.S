#include <asm/unistd_32.h>

    .intel_syntax noprefix
    .text
    .global _start
_start:
	mov eax, __NR_brk
	mov ebx, 0
	int 0x80
	
	mov edi, eax
	
	add edi, 4096
	
	mov eax, __NR_brk
	mov ebx, edi
	int 0x80

	sub edi, 4096

	mov eax, __NR_read
	mov ebx, 0
	mov ecx, edi
	mov edx, 4096
	int 0x80

	// total read
	mov esi, eax

	mov eax, __NR_write
	mov ebx, 1
	mov ecx, edi
	mov edx, esi
	int 0x80

	// free
	sub edi, 4096
	mov eax, __NR_brk
	mov ebx, edi
	int 0x80

	mov eax, __NR_exit
	mov ebx, 0
	int 0x80
	
