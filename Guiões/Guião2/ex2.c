// Exercício 2 do Guião 2 de SO

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */

int main() {

	pid_t pid;
	int status;

	if ((pid = fork()) == 0) {
		printf("Filho: %d, Pai: %d\n", getpid(), getppid());
		_exit(0);
	}

	else {
		pid_t child = wait(&status);
		printf("Pai: %d, Pai do Pai: %d, Filho: %d\n", getpid(), getppid(), pid);
	}

	return 0;

}