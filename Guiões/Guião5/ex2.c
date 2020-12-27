// Resolução do Exercício 2 do Guião 5 de SO

#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {

	// criar pipe
	int pipe_fd[2];
	if (pipe(pipe_fd) < 0) {
		perror("pipe");
		_exit(1);
	}

	// criar o processo filho 
	int pid = -1;

	if ((pid = fork()) == 0) {
		// Herda os descritores do pipe
		// Fechamos os descritores que não são utilizados
		close(pipe_fd[1]);
		// Temos extremidade de leitura do pipe
		char buffer[10];
		int bytes = 0;
		while ((bytes = read(pipe_fd[0], buffer, 10)) > 0) {
			write(1, buffer, bytes);
		}
		close(pipe_fd[0]);
		_exit(0);
	}

	else {
		close(pipe_fd[0]);
		// Temos extremidade de escrita do pipe
		char* str = "teste";
		//sleep(15);
		for(int i = 0; i < 3; i++) {
			write(pipe_fd[1], str, strlen(str) + 1);
		}
		close(pipe_fd[1]);
		wait(NULL);
	}


	// comunicação pai -> filho



	return 0;

}