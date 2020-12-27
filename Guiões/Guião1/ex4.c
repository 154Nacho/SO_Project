// Exercício 4 do Guião 1 de SO 

#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, 0_* */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define max 100

ssize_t readln (int fd, char *line, size_t nbyte) {
  ssize_t res = 0;
  ssize_t i = 0;
  char buffer[max];
  int a;
  int flag = 0;
  while ((res = read (fd, &buffer[i], nbyte)) > 0 && flag == 0) {
    i += res;
    for (a = 0; a<i && flag == 0; a++) if (buffer[a] == '\n') flag = 1;
  }
  for (i = 0; i < a; i++) line[i] = buffer[i];
  line[i] = '\0';
  return i;
}

int main() {
  char buffer[100];
	int fd1 = open("wtf.txt", O_RDONLY);
	int tam = 100;
	readln (fd1, buffer, tam);
	printf ("%s", buffer);
	close (fd1);
	return 0;
}
