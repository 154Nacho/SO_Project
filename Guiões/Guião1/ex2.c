// Exercício 2 do Guião 1 de SO

#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, 0_* */
#include <stdlib.h>

#define max 100

int main() {

	char byte;
	ssize_t res;

	while ((res = read(0,&byte,1)) != 0) {
		write(1,&byte,res);
	}

	return 0;

}