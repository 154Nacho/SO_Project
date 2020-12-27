// Exercício 5 do Guião 2 de SO

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */

int main() {

	pid_t pid;
	int status;

	for (int i = 0; i < 10; i++) {

		if ((pid = fork()) == 0) {
			printf("[processo %d] pid: %d\n", i, getpid());
			printf("pai: %d\n", getppid());
		} 

		else {
			pid_t finished_pid = wait(&status);
			if (WIFEXITED(status)) {
				printf("[pai] procces %d exited. exit code: %d\n", finished_pid, WEXITSTATUS(status));
			} else {
				printf("[pai] process %d exited.\n", finished_pid);
			}
			_exit(0);
		}

	}

	return 0;

} 