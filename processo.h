//arquivo processo.h

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef enum prioridade {baixo,medio,alto};

typedef enum status {aberto,concluido};

typedef struct processo{
	int id;
	char desc[250];
	int prioridade;
	int status;
}processo;

void mudancaStatus(processo *p);
