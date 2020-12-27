// Exercício 2 do Guião 3 de SO 

#include <unistd.h> /* chamdas ao sistema : defs e decls essenciais. */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const * argv[]) {

	int pid = -1;

	if ((pid = fork()) == 0) {

		//execl("/bin/ls", "ls", "-l", NULL);
		//execlp ("ls", "ls", "-l", NULL);

		char * exec_args[] = {"ls","-l",NULL};
		if (execv("/bin/ls", exec_args) < 0) {
			perror("exec");
		}
		//execvp("ls", exec_args);

	}

	else {

		wait(NULL);
		printf("Terminou.\n");

	}

	return 0;

}