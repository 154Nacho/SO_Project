#define FILENAME "file pessoas"

typedef struct Person
{
	char name[200];
	int age;
} Person;


// Cria uma nova pessoa
int new_person (const char* name, int age);

// Muda a idade de uma pessoa
void person_change_age (const char* name, int age);

// Muda a idade de uma pessoa
void person_change_age_v2 (long pos, int age);

// Imprime a idade duma pessoa
void list_person (const char* name);

// Imprime a idade de todas as pessoas
void list_all ();