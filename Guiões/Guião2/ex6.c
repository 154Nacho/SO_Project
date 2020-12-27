// Exercício 5 do Guião 2 de SO

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */

int main(int argc, char* argv[]) {

	/* Criação da matriz com muitas mais colunas do que linhas */

	if (argc < 2) {
		printf("Usage: program <needle>\n");
		exit(-1);
	}

	pid_t pid;
	int needle = atoi(argv[1]);
	int rows = 10;
	int cols = 10000;
	int rand_max = 10000;
	int status;
	int matrix[rows][cols];

	printf("Generating numbers from 0 to %d...", rand_max);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = rand() % rand_max;
		}
	}

	printf("Done.\n");

	/* Resolução do exercício. */

	for(int i = 0; i < rows; i++) {

		if((pid = fork()) == 0) {

			printf("[Pid %d] row %d\n", getpid(), i);

			// Start searching for the given number in row #i;
			for(int j = 0; j < cols;j++) {
				if (matrix[i][j] == needle) {
					_exit(1);
				}
			}

			_exit(0);

		}

	}

	for(int i = 0; i < rows; i++) {

		pid_t terminated_pid = wait(&status);

		if(WEXITSTATUS(status)) {

			if(WEXITSTATUS(status) > 0) {
				printf("[pai] process %d exited. found number.\n", terminated_pid);
			}

			else {
				printf("[pai] process %d exited. nothing found.\n", terminated_pid);
			}

		}

		else {
			printf("[pai] process %d exited. something went wrong\n", terminated_pid);
		}

	}

	return 0;

}