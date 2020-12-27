// Exercício 4 do Guião 3 de SO 

#include <unistd.h> /* chamdas ao sistema : defs e decls essenciais. */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const * argv[]) {

	char * exec_args[] = {"ex3","arg1","arg2","arg3",NULL}; // o "ex3" pode ter outro nome que não o nome do executável! Vai funcionar, mas regra geral é o nome do executável. Experimentar "outro_programa".

	int ret = execv("./ex3", exec_args);

	return ret;

}