// Exercício 1 do Guião 3 de SO 

#include <unistd.h> /* chamdas ao sistema : defs e decls essenciais. */

int main(int argc, char const * argv[]) {

	execl("/bin/ls", "ls", "-l", NULL);
	execlp ("ls", "ls", "-l", NULL);

	char * exec_args[] = {"ls","-l",NULL};
	execv("/bin/ls", exec_args);
	execvp("ls", exec_args);

	return 0;

}