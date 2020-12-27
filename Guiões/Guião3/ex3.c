// Exercício 3 do Guião 3 de SO 

#include <unistd.h> /* chamdas ao sistema : defs e decls essenciais. */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char const * argv[]) {

	for (int i = 0; i < argc; i++) {

		write(1, argv[i],strlen(argv[i]));
		write(1, "\n", 1);

	}

	return 0;

}