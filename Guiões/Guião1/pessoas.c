#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#include "pessoas.h"

#define BUFFER_SIZE 1024
#define FILE_SIZE 10*1024*1024

int new_person (const char* name, int age)
{
	int fd = open (FILENAME, O_CREAT | O_WRONLY, 0600);

	Person new;
	strcpy (new.name, name);
	new.age = age;

	lseek (fd, 0, SEEK_END);
	write (fd, &new, sizeof(Person));

	int seek = lseek (fd, 0, SEEK_CUR);

	close (fd);

	return (seek / sizeof(Person));
}

void person_change_age (const char* name, int age)
{
	int fd = open (FILENAME, O_RDWR, 0600);
	Person aux;

	while (read (fd, &aux, sizeof(Person)) > 0)
	{
		if (strcmp(aux.name, name) == 0)
		{
			aux.age = age;
			lseek (fd, -sizeof(Person), SEEK_CUR);
			write (fd, &aux, sizeof(Person));
			break;
		}
	}

	close (fd);
}

void person_change_age_v2 (long pos, int age)
{
	int fd = open (FILENAME, O_RDWR, 0600);
	Person aux;

	lseek (fd, (pos-1) * sizeof(Person), SEEK_SET);
	read (fd, &aux, sizeof(Person));
	lseek (fd, -sizeof(Person), SEEK_CUR);

	aux.age = age;
	write (fd, &aux, sizeof(Person));

	close (fd);
}


void list_person (const char* name)
{
	int fd = open (FILENAME, O_RDONLY, 0600);
	Person aux;

	while (read (fd, &aux, sizeof(Person)) > 0)
	{
		if (strcmp(aux.name, name) == 0)
			printf("%s tem %d anos\n", aux.name, aux.age);
	}

	close (fd);

}

void list_all ()
{
	int fd = open (FILENAME, O_RDONLY, 0600);
	Person aux;

	while (read (fd, &aux, sizeof(Person)) > 0)
	{
		printf("%s tem %d anos\n", aux.name, aux.age);
	}

	close (fd);
}

int main(int argc, char const *argv[])
{
	if (strcmp(argv[1], "-i") == 0)
	{
		int reg = new_person (argv[2], atoi(argv[3]));
		printf("registo %d\n", reg);
	}
	else if (strcmp(argv[1], "-u") == 0)
	{
		person_change_age (argv[2], atoi(argv[3]));
	}
	else if (strcmp(argv[1], "-l") == 0)
	{
		list_person (argv[2]);
	}
	else if (strcmp(argv[1], "-U") == 0)
	{
		person_change_age_v2 (atoi(argv[2]), atoi(argv[3]));
	}
	else if (strcmp(argv[1], "-la") == 0)
	{
		list_all ();
	}


	return 0;
}