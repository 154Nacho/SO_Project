// Exercício 3 do Guião 1 de SO 

#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, 0_* */
#include <stdlib.h>
#include <stdio.h>

ssize_t readln(int fd, char* line, size_t size) {

	ssize_t res = 0;
	ssize_t i = 0; /* ssize_t é um unsigned int */

	while ((res = read(fd, &line[i], size)) > 0 && ((char*)line)[i] != '\n') {
		i += res;
	}

	return i;

}

int main(int argc, char* argv[]) {

	char buffer[100];
	int fd1 = open("orig.txt", O_RDONLY);
	int tam = 1;
	readln(fd1, buffer, tam);
	printf("%s\n", buffer);
	close(fd1);
	return 0;

}