//arquivo processo.h

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef enum {baixo,medio,alto} prioridade;

typedef enum {aberto,concluido} status;

typedef struct processo{
	int id;
	char desc[250];
	int prioridade;
	int status;
}processo;

void mudancaStatus(processo *p);
