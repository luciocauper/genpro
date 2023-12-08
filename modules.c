#include "heap.h"
#include "avp.h"
#include "processo.h"
//implementacao da arvore e do heap

/*
	aqui segue a implementação do heap
*/

heap* criar(int nmax){
	heap *h = (heap *) malloc(sizeof(heap));
	h->n = 0;
	h->nmax = nmax;
	h->v = (int *) malloc(h->nmax * sizeof(int));
	return h;
}

void heap_libera(heap *h){
	free(h->v);
	free(h);
}

int heap_vazia (heap *h){
	if(h->n == 0) return 0;
	else return 1;
}

void sobe (heap *h, int i){
	int pai;
	while(i>0){ //enquanto não estiver na raiz
		pai = pai(i);
		if((h->v[pai])> (h->v[i]))
			break;
		troca(h, pai, i);
		i = pai;
	}
}

void troca (heap *h, int i, int j){
	int temp = h->v[i];
	h->v[i] = h->v[j];
	h->v[j] = temp;
}

void desce (heap *h, int i){
	int aux = esq(i);
	int filho_dir;
	while(aux < h->n){
		filho_dir = dir(i);
		if((filho_dir < h->n) && (h->v[filho_dir] > h->v[aux]))
			aux = filho_dir;
		if(h->v[aux] < h->v[i])
			break;	
		troca(h,i,aux);
		i = aux;
		aux = esq(i);	
	}
}

void heap_insere(heap *h, int valor){
	h->v[h->n++] = valor;
	sobe(h, h->n-1);	
}

int heap_retira (heap *h){
	int topo = h->v[0]; //remove o elemento do topo
	h->v[0] = h->v[--(h->n)];
	desce(h,0);
	return topo;
}

void mostrar(heap *h){
	int i=0;
	puts("-----------ELEMENTOS-----------");
	for(int i=0;i<h->n;i++)
		printf("%d -", h->v[i]);
}

/*
	aqui segue a implementação da arvore vermelho e preta
*/

Tno *rotacao_simples_esquerda(Tno *a) {
    Tno *aux;
    aux = a->dir;
    a->dir = aux->esq;
    aux->esq = a;
    a = aux;
    return a;
}

Tno *rotacao_simples_direita(Tno *a) {
    Tno *aux;
    aux = a->esq;
    a->esq = aux->dir;
    aux->dir = a;
    a = aux;
    return a;
}

Tno *criarTno(int elemento) {
    Tno *dado = (Tno *)malloc(sizeof(Tno));
    dado->elemento = elemento;
    dado->esq = NULL;
    dado->dir = NULL;
    dado->cor = vermelho;
    return dado;
}

Tno *inserir(Tno *a, int valor) {
    Tno *dado = criarTno(valor);
    a = incluir_no(a, dado);
    if (a != NULL) {
        a->cor = preto;
    }
    return a;
}

Tno *incluir_no(Tno *a, Tno *dado) {
    if (a == NULL) {
        return dado;
    } else {
        if (a->elemento > dado->elemento) {
            a->esq = incluir_no(a->esq, dado);
        } else {
            a->dir = incluir_no(a->dir, dado);
        }
        if (cor(a->esq) == vermelho && cor(a->dir) == vermelho) {
            trocaCor(a);
        }
    }
    return a;
}

int cor(Tno *a) {
    if (a == NULL) {
        return preto;
    } else {
        return a->cor;
    }
}

void trocaCor(Tno *a) {
    a->cor = !a->cor;
    if (a->esq != NULL) {
        a->esq->cor = !a->esq->cor;
    }
    if (a->dir != NULL) {
        a->dir->cor = !a->dir->cor;
    }
}

void imprime(Tno *a) {
    if (a == NULL) {
        return;
    }
    printf("%d [cor: %d]", a->elemento, a->cor);

    if (a->esq != NULL) {
        printf("(E:%d [cor: %d])", a->esq->elemento, a->esq->cor);
    }
    if (a->dir != NULL) {
        printf("(D:%d [cor: %d])", a->dir->elemento, a->dir->cor);
    }
    printf("\n");

    imprime(a->esq);
    imprime(a->dir);
}

/*
	aqui segue a implementação de processo
*/

void mudancaStatus(processo* p){
	if(p->status==aberto){
		p->status=concluido;
	}
	else p->status=aberto;
}
