#include "heap.h"
#include "avp.h"
#include "processo.h"
#include "pessoa.h"

//implementacao da arvore e do heap

/*
	aqui segue a implementa��o do heap
*/

heap* criar(int nmax){
	heap *h = (heap *) malloc(sizeof(heap));
	h->n = 0;
	h->nmax = nmax;
	h->v = (processo *) malloc(h->nmax * sizeof(processo));
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
	while(i>0){ //enquanto n�o estiver na raiz
		pai = pai(i);
		if((h->v[pai].id)> (h->v[i].id))
			break;
		troca(h, pai, i);
		i = pai;
	}
}

void troca (heap *h, int i, int j){
	int temp = h->v[i].id;
	h->v[i].id = h->v[j].id;
	h->v[j].id = temp;
}

void desce (heap *h, int i){
	int aux = esq(i);
	int filho_dir;
	while(aux < h->n){
		filho_dir = dir(i);
		if((filho_dir < h->n) && (h->v[filho_dir].id > h->v[aux].id))
			aux = filho_dir;
		if(h->v[aux].id < h->v[i].id)
			break;	
		troca(h,i,aux);
		i = aux;
		aux = esq(i);	
	}
}

void heap_insere(heap *h, processo valor){
	h->v[h->n++] = valor;
	sobe(h, h->n-1);	
}

int heap_retira (heap *h){
	int topo = h->v[0].id; //remove o elemento do topo
	h->v[0] = h->v[--(h->n)];
	desce(h,0);
	return topo;
}

void mostrar(heap *h){
	int i=0;
	puts("-----------ELEMENTOS-----------");
	for(int i=0;i<h->n;i++)
		printf("ID=%d, Desc=%s, Prioridade=%d, Status=%d\n",
               h->v[i].id, h->v[i].desc, h->v[i].prioridade, h->v[i].status);
}

/*
	aqui segue a implementa��o da arvore vermelho e preta
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

Tno *criarTno(processo elemento) {
    Tno *dado = (Tno *)malloc(sizeof(Tno));
    dado->elemento = elemento;
    dado->esq = NULL;
    dado->dir = NULL;
    dado->cor = vermelho;
    return dado;
}

Tno *inserir(Tno *a, processo valor) {
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
        if (a->elemento.id > dado->elemento.id) {
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
    imprimirProcesso(a->elemento);
    printf("\ncor: %d",a->cor);

    if (a->esq != NULL) {
        printf("(E:%d [cor: %d])", a->esq->elemento.id, a->esq->cor);
    }
    if (a->dir != NULL) {
        printf("(D:%d [cor: %d])", a->dir->elemento.id, a->dir->cor);
    }
    printf("\n");

    imprime(a->esq);
    imprime(a->dir);
}

Tno* procurar(Tno* raiz, int id) {
    if (raiz == NULL || raiz->elemento.id == id) {
        return raiz;
    }
    if (id < raiz->elemento.id) {
        return procurar(raiz->esq, id);
    }
    else if (id > raiz->elemento.id) {
        return procurar(raiz->dir, id);
    }
    return NULL;
}


/*
	aqui segue a implementa��o de processo
*/

void mudancaStatus(processo* p){
	if(p->status==aberto){
		p->status=concluido;
	}
	else p->status=aberto;
}

processo* criarProcesso(int id, const char* desc, int prioridade){
    processo* novoProcesso = (processo*)malloc(sizeof(processo));
    novoProcesso->id=id;
    strncpy(novoProcesso->desc, desc, sizeof(novoProcesso->desc));
    novoProcesso->prioridade=prioridade;
    novoProcesso->status=aberto;
    return novoProcesso;
}

void addProcesso(Pessoa* lista,int id, processo b){
    while (id!=lista->id){
        lista=lista->prox;
    }
    lista->arvore = inserir(lista->arvore,b);
    
}

void imprimirProcesso(processo p){
    printf("Id:%d\nDescricao:%s\nStatus:%d\nPrioridade:%d",p.id,p.desc,p.status,p.prioridade);
}
/*
    abaixo a implemetação de pessoas
*/

Pessoa criarPessoa(int id, const char* nome) {
    Pessoa novaPessoa;
    novaPessoa.id = id;
    strncpy(novaPessoa.nome, nome, sizeof(novaPessoa.nome));
    novaPessoa.arvore = NULL; 
    novaPessoa.prox = NULL;  
    return novaPessoa;
}

Pessoa* inserirNoInicio(Pessoa* lista, int id, const char* nome) {
    Pessoa* novaPessoa = (Pessoa*)malloc(sizeof(Pessoa));
    if (novaPessoa == NULL) {
        exit(EXIT_FAILURE);
    }
    *novaPessoa = criarPessoa(id, nome);
    novaPessoa->prox = lista;
    return novaPessoa;
}

void imprimirPessoa(Pessoa* lista){
    while (lista!=NULL){
        printf("Nome: %s, ID: %d",lista->nome,lista->id);
        imprimir(lista->arvore);
        lista = lista->prox;
    }
}