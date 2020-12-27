// Resolução do Exercício 1 do Guião 4

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

	char buffer[10];
	int bytes = 0;

	while((bytes = read(0, &buffer, 10)) > 0) {
		write(1, &buffer, bytes);
		write(2, &buffer , bytes);
	} 


	return 0;

}