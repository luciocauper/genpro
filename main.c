#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h" // Supondo que voc� tenha arquivos header para as fun��es utilizadas
#include "processo.h"
#include "avp.h"
#include "heap.h"

int main() {
    int op, id = 1; // Inicializando id como 0
    char nome[50];
    Pessoa user, *lista = NULL;
    processo pro;

    do {
        system("cls");
        printf("=== SISTEMA DE GERENCIAMENTO DE PROCESSOS===\n");
        printf("1. Cadastrar usu�rio\n");
        printf("2. Abrir um pedido\n");
        printf("3. Listar os dados de todos os usu�rios\n");
        printf("4. Listar servi�os de um usu�rio\n");
        printf("5. Mudar informa��es de um usu�rio\n");
        printf("6. Mudar informa��es de um pedido\n");
        printf("7. Alterar status de um pedido\n");
        printf("0. SAIR DO SISTEMA\n\n");
        printf("Comando: ");
        scanf("%d", &op);

        switch (op) {
            case 1: {
                printf("Insira o seu nome: ");
                scanf("%s", nome);
                if(lista!=NULL){
                    id = lista->id+1;
                    //user = criarPessoa(id,nome);
                    lista = inserirNoInicio(lista,user.id,user.nome);
                }

                break;
            }
            case 2: {
                printf("\n\n=====Abrir um pedido=====\n");
                char desc[250];

                printf("Id do processo: "); // Atribuir o ID do processo
                scanf("%d", &id);

                printf("Descri��o do processo: ");
                scanf("%s", desc);
                break;
            }
            case 4:{
                printf("Informe o ID do usuario: ");
                int op4;
                scanf("%d",&op4);
                Pessoa *aux = lista;
                while (op4!=aux->id){
                    aux=aux->prox;
                    if (op4==aux->id){
                        imprimirPessoa(aux);
                    }
                }
                
                break;
            }
            case 5:{
                printf("Informe o ID do usuario: ");
                int op5;
                scanf("%d",&op5);
                Pessoa *aux=lista;
                while (op5!=aux->id){
                    aux=aux->prox;
                    if (op5==aux->id){
                        printf("Nome atual: %s", aux->nome);
                        printf("Qual o novo nome?\n");
                        scanf("%s", nome);
                        *aux->nome=nome;
                        lista=aux;
                    }
                    
                }
                break;

            }
            case 7:{
                int userid, pedid;
                printf("Insira o ID do usu�rio e ID do pedido");
                printf("Usuario-id: ");
                scanf("%d",&userid);
                printf("Pedido-id: ");
                scanf("%d",&pedid);
                Pessoa *aux = lista;
                while (aux->id!=userid){
                    aux=aux->prox;
                    if (aux->id==userid){
                        Tno* no=procurar(aux->arvore,pedid);
                        mudancaStatus(no->elemento.status);
                    }
                    
                }
                

                break;
            }

            case 0: {
                printf("Saindo do sistema...\n");
                exit(0);
            }
            default: {
                printf("Op��o inv�lida. Tente novamente.\n");
            }
        }
    } while (op != 0);

    return 0;
}

