/************************************************************************************
 * Nome: fila vetorizada(Loja de camisas)                                           *
 * Descricao: Implementacao de fila vetorizada. Esse codigo possui                   *
 *           as principais operacoes da fila, como:                                 *
 *           criar fila,                                                            *
 *           inserirElementoInicio/enqueue (inseri no início fila)                  *
 *           mostrar (apresenta todas as informações dos elementos da lista)        *
 *           removerElemento/dequeue (remove pelo inicio)                           *
 *           excluirLista (apagar todos os elementos e a lista)                     *
 *           main (fazer aplicação com funções anteriores)                          *
 * Autor: Alejandro Estevan e Rafael Santiago                                       *
 * Ultima alteracao: 9/06/2023                                                      *
 ***********************************************************************************/

/*Include das bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

#define TAM 5

typedef struct camisa Camisa;
typedef struct loja Loja;

struct camisa {
    char color[20];
    float price;
    int quantity;
};

struct loja {
    Camisa estoque[TAM];
    int first;
    int last;
};
/* Nome: filaEstoque
 * Parametro: void 
 * Descricao: Função responsavel pela criacao da fila
 */
Loja* FilaEstoque() {
    Loja *new = (Loja*)malloc(sizeof(Loja));
    if (new == NULL) {
        printf("Estoque vazio\n");
        return NULL;
    }

    new->first = -1;
    new->last = -1;

    return new;
}
/* Nome: enqueue
 * Parametros: loja, color, price, quantity 
 * Descricao: Função criada para inserir um elemento na fila
 */
int enqueue(Loja *loja, char *color, float price, int quantity) {
    if ((loja->last + 1) % TAM == loja->first) {
        printf("Sem espaço\n");
        return 0;
    }

    int new_last = (loja->last + 1) % TAM;
    strcpy(loja->estoque[new_last].color, color);
    loja->estoque[new_last].price = price;
    loja->estoque[new_last].quantity = quantity;

    if (loja->first == -1) {
        loja->first = new_last;
    }

    loja->last = new_last;

    return 1;
}
/* Nome: imprimir
 * Parametro: loja
 * Descricao: Função criada para apresentar todos elementos presentes na fila
 */
void imprimir(Loja *loja) {
    if (loja->first == -1) {
        printf("Lista vazia\n");
        return;
    }

    int i = loja->first;
    while (i != loja->last) {
        printf("Cor: %s\nPreco: %.2f\nQuantidade: %d\n\n", loja->estoque[i].color, loja->estoque[i].price, loja->estoque[i].quantity);
        i = (i + 1) % TAM;
    }

    printf("Cor: %s\nPreco: %.2f\nQuantidade: %d\n\n", loja->estoque[i].color, loja->estoque[i].price, loja->estoque[i].quantity);
}
/* Nome: remover da fila
 * Parametro: loja, cor
 * Descricao: Função criada para remover da fila
 */
Camisa dequeue(Loja *loja) {
    if (loja->first == -1) {
        printf("Estoque vazio\n");
        Camisa emptyCamisa = {"", 0.0, 0};
        return emptyCamisa;
    }

    int old_first = loja->first;
    loja->first = (loja->first + 1) % TAM;

    if (loja->first == (loja->last + 1) % TAM) {
        loja->first = -1;
        loja->last = -1;
    }

    return loja->estoque[old_first];
}
/* Nome: excluir
 * Parametro: loja
 * Descricao: Função responsavel pela exclusao do estoque
 */
Loja* excluir(Loja* loja) {
    free(loja);
    return NULL;
}

void opcoesM(){
    printf("\t***************************");
    printf("\n\t******LOJA DE CAMISAS******\n");
    printf("\t***************************\n\n");
    printf("[0]- Criar lista\n");      
    printf("[1]- Adicionar cor na fila(cor,valor,quantidade)\n");       
    printf("[2]- Mostrar camisas\n");      
    printf("[3]- Remover camisa\n");       
    printf("[4]- Excluir lista\n");
}
int main(){
    /*Ponteiro para a lista*/
    Loja *camisas;
    Camisa excluirFila;
    //variaveis dos parametros
    char color[20];
    float price;
    int quantity;
    //variaveis do programa
    int opcoes;
    char returnMenu;
    char excluirL;
    //programa
    opcoesM();
  do {
        printf("\t DIGITE O NUMERO E CONFIRME: ");
        scanf("%d", &opcoes);

        switch (opcoes) {
            case 0:
                printf("Fila Criada\n");
                camisas = FilaEstoque();
                returnMenu = 's';
                break;

            case 1:
                printf("Adicionar camisa na fila (cor, valor, quantidade)\n");
                printf("Cor: ");
                scanf("%s", color);
                printf("Preco: ");
                scanf("%f", &price);
                printf("Quantidade: ");
                scanf("%d", &quantity);
                enqueue(camisas, color, price, quantity);
                printf("Voltar para o menu\n");
                scanf(" %c", &returnMenu);
                break;

            case 2:
                printf("Mostrar camisas\n");
                imprimir(camisas);
                printf("Voltar para o menu\n");
                scanf(" %c", &returnMenu);
                break;

            case 3:
                printf("Remover camisa\n");
                excluirFila = dequeue(camisas);
                printf("Camisa removida:\n");
                printf("Voltar para o menu\n");
                scanf(" %c", &returnMenu);
                break;

            case 4:
                printf("Excluir fila\n");
                printf("Tem certeza? ");
                scanf(" %c", &excluirL);
                if (excluirL == 's') {
                    camisas = excluir(camisas);
                }
                printf("Voltar para o menu\n");
                scanf(" %c", &returnMenu);
                break;

            default:
                printf("Valor invalido\n");
                break;
        }
    } while (returnMenu == 's');

    return 0;
}







