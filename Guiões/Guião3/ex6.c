// Exercício 5 do Guião 3 de SO 

#include <unistd.h> /* chamdas ao sistema : defs e decls essenciais. */
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

//retorna -1 se o fork falhar; caso contrário, retorna o valor do comando executado
int mysystem(char* command) {

	pid_t pid;
	int exec_ret;
	int status;
	int return_value;

	// First part: parsing
	char* exec_args[20];
	char* string;
	int i;

	string = strtok(command, " ");

	for (i = 0; string != NULL; i++) {
		exec_args[i] = string;
		string = strtok(NULL, " ");
	}

	exec_args[i] = NULL;

	// Second part: fork + exec

	// código do filho
	if ((pid = fork()) == 0) {
			exec_ret = execvp(exec_args[0], exec_args);
			_exit(exec_ret);
	}

	// código do pai
	if (pid != -1) {
		pid_t terminated_pid = wait(&status);

		if (WIFEXITED(status)) {
			return_value = WEXITSTATUS(status);
		}
		else {
			return_value = -1;
		}
	}
	else {
		return_value = -1;
	}

	return return_value;
}


int main(int argc, char** argv) {
	
	int ret;
	char comando[128];

	strcat(comando, argv[1]);
	for (int i = 2; i < argc; i++) {
		strcat(comando, " ");
		strcat(comando, argv[i]);
	}

	printf("Vou executar o comando %s\n", comando);
	ret = mysystem(comando);
	printf("Valor de retorno: %d\n", ret);

	return 0;
}