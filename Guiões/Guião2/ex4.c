// Exercício 4 do Guião 2 de SO

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */

int main() {

	pid_t pid, finished_pid;
	int status;
	int i;

	for (i = 0; i < 10; i++) {

		if ((pid = fork()) == 0) {
			printf("[Process #%d] Pid: %d, Pai: %d\n", i+1, getpid(), getppid());
			_exit(i+1);
		}

	}
	
	sleep(2);

	for (i = 0; i < 10; i++) {

		finished_pid = wait(&status);

		if (WIFEXITED(status)) {
			printf("[Pai] process %d finished. exit code %d\n", finished_pid, WEXITSTATUS(status));
		}

		else {
			printf("[Pai] process %d exited\n", finished_pid);
		}

	}

}