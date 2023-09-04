/************************************************************************************
 * Nome: pilha encadeada (Loja de camisas)                                          *
 * Descricao: Implementacao de pilha encadeada. Esse codigo possui                  *
 *           as principais operacoes da pilha, como:                                *
 *           criar pilha,                                                           *
 *           inserirElemento/push (inseri no top da pilha)                          *
 *           mostrar (apresenta todas as informações dos elementos da lista)        *
 *           removerElemento/pop (remove pelo top)                                  *
 *           excluirpilha(apagar todos os elementos e a pilha)                      *
 *           main (fazer aplicação com funções anteriores)                          *
 * Autor: Alejandro Estevan e Rafael Santiago                                       *
 * Ultima alteracao: 9/06/2023                                                      *
 ***********************************************************************************/

/*Include das bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5


typedef struct lojaP LojaP;
typedef struct camisaP CamisaP;

struct lojaP
{
    CamisaP *estoque[TAM];
    int top;
};

struct camisaP
{
    char color[20];
    float price;
    int quantity;
};



/* Nome: Estoque
 * Parametro: void 
 * Retorno: endereço do espaço de memoria reservado pelo malloc
 * Descricao: Função responsavel pela criacao da lista e inicializção
 */
LojaP *estoquePilha(){
    LojaP *new = (LojaP *)malloc(sizeof(LojaP));
    if (new == NULL)
    {
        printf("Estoque vazio\n");
        return NULL;
    }
    new->top = -1;
    return new;
}
/* Nome: addEstoqueFinal
 * Parametros: camisasEstoque, color, price, quantity 
 * Descricao: Função criada para inserir um elemento no final da lista
 */
int push(LojaP *lojaPi, char *color, float price, int quantity)
{
    if (lojaPi->top == TAM - 1)
    {
        printf("Estoque cheio\n");
        return 0;
    }

    CamisaP *new = (CamisaP *)malloc(sizeof(CamisaP));
    if (new == NULL)
    {
        printf("Sem espaço\n");
        return 0;
    }

    strcpy(new->color, color);
    new->price = price;
    new->quantity = quantity;

    lojaPi->top++;
    lojaPi->estoque[lojaPi->top] = new;

    return 1;
}
/* Nome: imprimir
 * Parametro: camisasEstoque
 * Descricao: Função criada para apresentar todos elementos presentes na lista
 */
void imprimirP(LojaP *lojaPi)
{
    if (lojaPi->top == -1)
    {
        printf("Lista vazia\n");
        return;
    }

    for (int i = lojaPi->top; i >= 0; i--)
    {
        CamisaP *p = lojaPi->estoque[i];
        printf("Cor: %s\nPreco: %.2f\nQuantidade: %d\n\n", p->color, p->price, p->quantity);
    }
}
/* Nome: tamanhoLista
 * Parametro: camisasEstoque
 * Descricao: Função criada para apresentar a quantidade elementos presentes na lista
 */

CamisaP *pop(LojaP *lojaPi)
{
    if (lojaPi->top == -1)
    {
        printf("Estoque vazio\n");
        return NULL;
    }

    CamisaP *aux = lojaPi->estoque[lojaPi->top];
    lojaPi->top--;

    return aux;
}
/* Nome: excluir
 * Parametro: camisasEstoque 
 * Descricao: Função responsavel pela exclusao do estoque
 */
LojaP *excluir(LojaP *lojaPi)
{
    while (lojaPi->top != -1)
    {
        CamisaP *aux = pop(lojaPi);
        free(aux);
    }
    free(lojaPi);
    return NULL;
}

/* Nome: buscarCor
 * Parametro: camisasEstoque color
 * Descricao: Funcao criada para buscar um elemento na lista
 */

/* Nome: atualizar
 * Parametros: camisasEstoque, busca, quantidade 
 * Descricao: Função responsavel por atualizar a quantidade
 */
/*
* Lista de opções do menu.
*/
void opcoesM(){
    printf("\t***************************");
    printf("\n\t******LOJA DE CAMISAS******\n");
    printf("\t***************************\n\n");
    printf("[0]- Criar lista\n");      
    printf("[1]- Adicionar cor no final(cor,valor,quantidade)\n");       
    printf("[2]- Mostrar camisas\n");      
    printf("[3]- Remover camisa(cor)\n");       
    printf("[4]- Excluir lista\n");
}
int main(){
    /*Ponteiro para a lista*/
    LojaP *camisasP;
    LojaP *excluirp;

    //variaveis dos parametros
    char color[20];
    float price;
    int quantity;
    int posicao;
    int tamanho;
    //variaveis do programa
    int opcoes;
    char returnMenu;
    char excluirL;
    int atualValor;
    int valorAtualizado;

opcoesM();
    do
    {
        printf("\t DIGITE O NUMERO E CONFIRME: ");
        scanf("%d", &opcoes);
        switch (opcoes)
        {
        case 0:
            printf("Lista Criada\n");
            camisasP = estoquePilha();
            returnMenu = 's';
            break;
        case 1:
            printf("Adicionar camisa no início (cor, valor, quantidade)\n");
            printf("Cor: ");
            scanf("%s", color);
            printf("Preco: ");
            scanf("%f", &price);
            printf("Quantidade: ");
            scanf("%d", &quantity);
            push(camisasP, color, price, quantity);
            printf("Voltar para o menu\n");
            scanf(" %c", &returnMenu);
            break;
        case 2:
            imprimirP(camisasP);
            printf("voltar para o menu\n");
            scanf(" %c", &returnMenu);
            break;
        case 3:
            {
                CamisaP *excluirp = pop(camisasP);
                if (excluirp != NULL)
                {
                    printf("Camisa removida\n");
                    free(excluirp);
                }
                else
                {
                    printf("Estoque vazio\n");
                }
                printf("Voltar para o menu\n");
                scanf(" %c", &returnMenu);
            }
            break;
        case 4:
            printf("Excluir lista\n");
            printf("Tem certeza? ");
            scanf(" %c", &excluirL);
            if (excluirL == 's')
            {
                camisasP = excluir(camisasP);
            }
            printf("Voltar para o menu\n");
            scanf(" %c", &returnMenu);
            break;
        default:
            printf("Valor inválido\n");
            break;
        }
    } while (returnMenu == 's');

    //programa
    // opcoesM();
    // do{
    //     printf("\t DIGITE O NUMERO E CONFIRME: ");
    //     scanf("%d",&opcoes);
    //      switch (opcoes)
    //     {  
    //         case 0:
    //                 printf("Lista Criada\n");
    //                 camisasP = estoquePilha();
    //                 returnMenu = 's';
    //         break;
    //         case 1:
    //                 printf("Adicionar camisa no incio(cor,valor,quantidade)\n");
    //                 printf("Cor: ");
    //                 scanf("%s",&color);
    //                 printf("Preco: ");
    //                 scanf("%f",&price);
    //                 printf("Quantidade: ");
    //                 scanf("%d",&quantity);
    //                 push(camisasP,color,price,quantity);
    //                 printf("Voltar para o menu\n");
    //                 scanf("%s",&returnMenu); 
    //         break;
    //         case 2:
    //                 imprimirP(camisasP);
    //                 printf("voltar para o menu\n");
    //                 scanf("%s",&returnMenu); 
    //         break;

    //         case 3:
    //                if (!ehvazio(camisasP))
    //                {
    //                 printf("Remover camisa(cor)\n");
    //                 excluirp = pop(camisasP);
    //                }
                   
    //         break;
    //         case 4:
    //                 printf("Excluir lista\n");
    //                 printf("tem certeza? ");
    //                 scanf("%s", &excluirL);
    //                 if(excluirL == 's'){
    //                     camisasP = excluir(camisasP);
    //                 }
    //                     printf("voltar para o menu\n");
    //                     scanf("%s",&returnMenu);
    //         break;
    //         case 5:
    //                 printf(seeTop(camisasP));
    //         break;
    //         default:
    //                 printf("valor invalido\n");
    //         break;
    //     }
    // }while(returnMenu == 's');      


}