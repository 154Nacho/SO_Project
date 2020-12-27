// Resolução do Exercício 3 do Guião 4

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char * argv[]) {

	int input_fd = open("/etc/passwd", O_RDONLY);
	// verificar se abriu corretamente
	int output_fd = open("saida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// verificar se abriu corretamente
	int error_fd = open("erros.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// 0 => teclado
	// 1 => ecrã
	// 2 => ecrã
	// input_fd e 0 => /etc/passwd
	// output_fd e 1 => saida.txt
	// error_fd e 2 => erros.txt 

	int original_stdin = dup(0);
	int original_stdout = dup(1);
	int original_stderr = dup(2);

	// original_stdin => teclado 
	// original_stdout => ecrã
	// original_stderr => ecrã

	int stdin_fd = dup2(input_fd,0); 
	int stdout_fd = dup2(output_fd,1);
	int stderr_fd = dup2(error_fd,2);
	// input_fd e 0 => /etc/passwd
	// output_fd e 1 => saida.txt
	// error_fd e 2 => erros.txt 

	close(input_fd);
	close(output_fd);
	close(error_fd);
	// 0 => /etc/passwd
	// 1 => saida.txt
	// 2 => erros.txt

	if (execlp("wc","wc",NULL) < 0) {
		_exit(1);
	}
 
	return 0;

}