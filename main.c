#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h" // Supondo que você tenha arquivos header para as funções utilizadas
#include "processo.h"
#include "avp.h"
#include "heap.h"

int main() {
    int op, id = 0; // Inicializando id como 0
    char nome[50];
    Pessoa user, *lista = NULL;
    processo pro;

    do {
        system("cls");
        printf("=== SISTEMA DE GERENCIAMENTO DE PROCESSOS===\n");
        printf("1. Cadastrar usuário\n");
        printf("2. Abrir um pedido\n");
        printf("3. Listar os dados de todos os usuários\n");
        printf("4. Listar serviços de um usuário\n");
        printf("5. Mudar informações de um usuário\n");
        printf("6. Mudar informações de um pedido\n");
        printf("7. Alterar status de um pedido\n");
        printf("0. SAIR DO SISTEMA\n\n");
        printf("Comando: ");
        scanf("%d", &op);

        switch (op) {
            case 1: {
                printf("Insira o seu nome: ");
                scanf("%s", nome);

                // Encontrar o ID do último elemento na lista e incrementar em 1
                int novoId = 1; // Valor inicial caso a lista esteja vazia

                user = criarPessoa(novoId, nome);

                if (idJaexiste(lista, novoId)) {
                    printf("O id já existe\n");
                } else {
                    lista = inserirNoInicio(lista, user.id, user.nome);
                    printf("Usuário inserido com sucesso na lista.\n");
                }
                break;
            }
            case 2: {
                printf("\n\n=====Abrir um pedido=====\n");
                char desc[250];

                printf("Id do processo: "); // Atribuir o ID do processo
                scanf("%d", &id);

                printf("Descrição do processo: ");
                scanf("%s", desc);
                break;
            }
            case 0: {
                printf("Saindo do sistema...\n");
                exit(0);
            }
            default: {
                printf("Opção inválida. Tente novamente.\n");
            }
        }
    } while (op != 0);

    return 0;
}
