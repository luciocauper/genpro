#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"processo.h"

#define pai(i) (((i)-1)/2)
#define esq(i) (2*(i)+1)
#define dir(i) (2*(i)+2)

//adaptar o int n para um processo
typedef struct{
	int n;
	int nmax;
	processo *v;
} heap;

heap* criar(int nmax);
void heap_libera(heap *h);
int heap_vazia (heap *h);

void troca (heap *h, int i, int j);
void sobe (heap *h, int i);
void desce (heap *h, int i);

void heap_insere (heap *h, processo valor);
int heap_retira (heap *h);
void mostrar(heap *h);
