// Exercício 5 do Guião 1 de SO 

#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, 0_* */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXBUFFER 1000

ssize_t readln (int fd, char *line, ssize_t size) {
  ssize_t res = 0;
  char local[MAXBUFFER];
  int j = 0;

  while((res = read(fd, local, size)) > 0) {
    for (int i = 0; i < res; i++) {
      if (((char *) local)[i] != '\n') {
        line[j] = local[i];
        j++;
      } else return j;
    }
  }
  return j;
}

int main () {
  char buffer[MAXBUFFER];
  int fd = 0;
  ssize_t tam = MAXBUFFER;
  ssize_t result;
  int line_count = 0;

  while (( result = readln (fd, buffer, tam)) > 0) {
    line_count++;
    printf ("  %d,%s\n", line_count, buffer);
    memset (buffer, 0, result);
  }
  return 0;
}
