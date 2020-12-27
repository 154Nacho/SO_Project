// Resolução do Exercício 4 do Guião 4

#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

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
	
 	int res = 0;
	int commandindex = 1;
	char command [1024];
	int input_fd;
	int output_fd;

	setbuf(stdout,NULL);

	// redirecionar stdin
	if (strcmp(argv[commandindex], "-i") == 0) {
		int input_fd = open(argv[commandindex+1], O_RDONLY);
		dup2(input_fd,0);
		close(input_fd);

		commandindex += 2;
	}

	// redirecionar stdout
	if (strcmp(argv[commandindex],"-o") == 0) {
		int output_fd = open(argv[commandindex+1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
		dup2(output_fd,1);
		close(output_fd);

		commandindex += 2;
	}

	// parsing commands
	bzero(command,1024);  //  mete a variável command a zero
	while (commandindex < argc) {
		strcat(command, argv[commandindex]);
		strcat(command, " ");
		commandindex++;
	}

	//printf("%s\n", command);

	// execute mysystem
	mysystem(command);


	return 0;
}