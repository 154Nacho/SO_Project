// Exercício 3 do Guião 2 de SO

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */

int main() {

	pid_t pid;
	int status;
	int i;

	for (i = 0; i < 10; i++) {

		if ((pid = fork()) == 0) {
			printf("[Filho %d] Pid Filho: %d, Pid Pai: %d\n", i, getpid(), getppid());
			_exit(i+1);
		}

		else {
			pid_t finished_pid = wait(&status);
			printf("[Pai] Process %d exited. exit code %d\n", finished_pid, WEXITSTATUS(status));
		}

	}

	return 0;

}