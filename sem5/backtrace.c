#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <backtrace.h>

char* addr2name(void* addr)
{
   	FILE* f = fopen("./test_bt", "r");
	Elf64_Ehdr header;
	fread(&header, sizeof(header), 1, f);

	// reading section name header
	Elf64_Off header_name_off = header.e_shoff + header.e_shstrndx * header.e_shentsize;
	fseek(f, header_name_off, SEEK_SET);

	Elf64_Shdr name_header;
	fread(&name_header, sizeof(name_header), 1, f);

	Elf64_Off symtab_off, strtab_off;
	Elf64_Xword symtab_size;

	int is_found = 0;
	for (Elf64_Half i = 0; i < header.e_shnum; ++i) {
		fseek(f, header.e_shoff + i * header.e_shentsize, SEEK_SET);
		Elf64_Shdr section;
		fread(&section, sizeof(section), 1, f);

		char buffer[32];
		memset(buffer, 0, sizeof(buffer));

		fseek(f, name_header.sh_offset + section.sh_name, SEEK_SET);
		fgets(buffer, sizeof(buffer), f);
		printf("%s\n",buffer);
		if (!strcmp(buffer, ".symtab")) {
			symtab_off = section.sh_offset;
			symtab_size = section.sh_size / section.sh_entsize;
			//printf("FOUND!");
			is_found++;	
		}

		if (!strcmp(buffer, ".strtab")) {
			strtab_off = section.sh_offset;
			is_found++;
		}
	}
	assert(is_found == 2);
	
	for (Elf64_Xword i = 0; i < symtab_size; ++i) {
		fseek(f, symtab_off + i * sizeof(Elf64_Sym), SEEK_SET);

		Elf64_Sym sym;
		fread(&sym, sizeof(sym), 1, f);
	
		fseek(f, strtab_off + sym.st_name, SEEK_SET);
		
		char buffer[32];
		memset(buffer, 0, sizeof(buffer));

		printf("%s\n", buffer);
	
		fgets(buffer, sizeof(buffer), f);

		if (sym.st_value <= (Elf64_Addr)addr && (Elf64_Addr)addr < sym.st_value + sym.st_size) {
			char* addr_name = (char*)malloc(32);
			strcpy(addr_name, buffer); 
			return addr_name;
		}

		//if (!strcmp("addr2name", buffer)) {
		//	printf("%p %p\n", &addr2name, sym.st_value);
		//	diff = sym.st_value - (Elf64_Addr)&addr2name;
		//} 
	}


	return NULL;
}

int backtrace(void* backtrace[], int limit)
{
    void** rbp = 0;
    void** prev_rbp = 0;
    asm volatile("movq %%rbp, %0;" : "=r" (rbp));

    backtrace[0] = *(rbp + 1);

    size_t pos = 1;
    while (pos < limit) {
        rbp = (void**)(*rbp);
    if (rbp <= prev_rbp) break;
    prev_rbp = rbp;
        backtrace[pos++] = *(rbp + 1);
    }

    return pos;
}

void print_backtrace()
{
	void** trace = malloc(1024);
	int count = backtrace(trace, 1024);

	for (int i = 0; i < count - 1; ++i) {
		printf("%p %s\n", trace[i], addr2name(trace[i]));
	}
}

void bar() {
	print_backtrace();
}

void foo() {
	bar();
}

int main() {
	foo();
	return 0;
}

