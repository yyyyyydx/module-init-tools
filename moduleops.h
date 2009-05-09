#ifndef MODINITTOOLS_MODULEOPS_H
#define MODINITTOOLS_MODULEOPS_H
#include <stdio.h>

/* All the icky stuff to do with manipulating 64 and 32-bit modules
   belongs here. */
struct kernel_symbol32 {
	char value[4];
	char name[64 - 4];
};

struct kernel_symbol64 {
	char value[8];
	char name[64 - 8];
};

struct module_ops
{
	struct string_table *(*load_strings)(struct elf_file *module,
		const char *secname, struct string_table *tbl);
	struct string_table *(*load_symbols)(struct elf_file *module);
	struct string_table *(*load_dep_syms)(const char *pathname,
		struct elf_file *module, struct string_table **types);
	void (*fetch_tables)(struct elf_file *module,
		struct module_tables *tables);
	char *(*get_aliases)(struct elf_file *module, unsigned long *size);
	char *(*get_modinfo)(struct elf_file *module, unsigned long *size);
};

extern struct module_ops mod_ops32, mod_ops64;

#endif /* MODINITTOOLS_MODULEOPS_H */
