// Exercício 1 do Guião 2 de SO

#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */
#include <stdio.h>

int main() {

	pid_t pid;
	int status;

	if ((pid = fork()) == 0) {
		printf("Filho: %d\n", getpid());
		printf("Pai: %d\n", getppid());
		_exit(0);
	}

	else {
		pid_t child = wait(&status);
		printf("Pai: %d\n", getpid());
		printf("Filho: %d\n", pid);
	}

	return 0;

}