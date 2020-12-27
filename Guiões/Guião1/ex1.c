// Exercício 1 do Guião 1 de SO

#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, 0_* */
#include <string.h>

#define max 1

int main() {

	int fd1,fd2;
	ssize_t res;
	char byte[max];

	char origem[] = "orig.txt";
	char dest[] = "dest.txt";

	fd1 = open(origem, O_RDONLY); //0777

	/*if (fd1 == -1) {
        printf ("Value of errno: %d\n", errno);
        printf ("Error opening the file: %s\n", strerror(errno));
        return -1:
    }*/

    fd2 = open(dest, O_CREAT|O_TRUNC|O_WRONLY, 0777);

    while ((res = read(fd1,byte,max)) != 0) {
    	write(fd2,byte,max);
    }

    close(fd1);
    close(fd2);

    return 0;

}