// Exercício 5 do Guião 3 de SO 

#include <unistd.h> /* chamdas ao sistema : defs e decls essenciais. */
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>


int main(int argc, char ** argv) {

	pid_t pid;
	int status;

	for (int i = 1; i < argc; i++) {

		if ((pid = fork()) == 0) {
			printf("[filho] process %d a executar. A executar o comando %s\n", getpid(), argv[i]);
			execvp(argv[i], argv+i);
			_exit(0);
		}

	}

	for (int i = 0; i < argc - 1; i++) {

		pid_t terminated_pid = wait(&status);
		printf("[pai] Process %d exited with %d\n", terminated_pid, WEXITSTATUS(status));

	}

	return 0;

}