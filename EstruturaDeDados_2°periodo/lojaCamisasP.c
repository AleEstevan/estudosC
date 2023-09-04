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
    CamisaP *top;
};
struct camisaP
{
    char color[20];
    float price;
    int quantity;
    CamisaP *next;
};
/* Nome: estoquePilha
 * Parametro: void 
 * Descricao: Função responsavel pela criacao da pilha
 */
LojaP* estoquePilha() {
    LojaP *new = (LojaP*)malloc(sizeof(LojaP));
    // verificação
    if (new == NULL) {
		printf("Estoque vazio\n");
		return NULL;
	}
    //Dados inicias
    new->top = NULL; 

    return new;
}
/* Nome: push
 * Parametros: lojaPi, color, price, quantity 
 * Descricao: Função criada para inserir um elemento na pilha
 */
int push(LojaP *lojaPi, char *color, float price, int quantity) {
    CamisaP *new = (CamisaP*)malloc(TAM*sizeof(CamisaP));
    //verificação
    if (new == NULL) {
        printf("Sem espaço\n");
        return 0;
    }

    strcpy(new->color, color);
    new->price = price;
    new->quantity = quantity;
    new->next = NULL;
    
    new->next = lojaPi->top;
    lojaPi->top = new;

    return 1;

}
/* Nome: imprimirP
 * Parametro: lojaP
 * Descricao: Função criada para apresentar todos elementos presentes na lista
 */
void imprimirP(LojaP *lojaPi) {
    CamisaP *p;
    //verificação
    if (lojaPi == NULL) {
        printf("Lista nao criada\n");
        return ;
    }
    //verificação
    if (lojaPi->top == NULL) {
        printf("Lista vazia\n");
        return ;
    }
    for (p = lojaPi->top; p != NULL; p = p->next) {
        printf("Cor: %s\nPreco: %.2f\nQuantidade: %d\n", p->color, p->price, p->quantity);
        printf("\n");
    }
}
CamisaP* pop(LojaP *lojaPi) {
    CamisaP *aux;
    // verificação
    

    aux = lojaPi->top;
    lojaPi->top = lojaPi->top->next; 
    return aux ;
}
/* Nome: excluir
 * Parametro: lojaP
 * Descricao: Função responsavel pela exclusao do estoque
 */
LojaP* excluir(LojaP* lojaPi){
    LojaP *aux;
    while(lojaPi->top != NULL){
        aux = lojaPi->top;
        lojaPi->top = lojaPi->top->next;
        free(aux);
    }
    free(lojaPi);
    return NULL;
}
/* Nome: seetop
 * Parametro: lojaPi
 * Descricao: Função responsavel pela demostração do topo
 */
int seeTop(LojaP* lojaPi){
    CamisaP *aux;
    // verificação
   if (!ehvazio(lojaPi))
   {
   return lojaPi->top->color;
   } 
}
/* Nome: eHvazio
 * Parametro: lojaPi
 * Descricao: Função responsavel pela verificação de espaço
 */
int ehvazio(LojaP *lojaPi){

    if (lojaPi == NULL) {
        printf("Sem estoque\n");
        return 0;
    }

    // verificação
    if (lojaPi->top == NULL) {
        printf("Estoque vazio\n");
        return NULL;
    }

    return 0;

}
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
    /*Ponteiro para a pilha*/
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

    //programa
    opcoesM();
    do{
        printf("\t DIGITE O NUMERO E CONFIRME: ");
        scanf("%d",&opcoes);
         switch (opcoes)
        {  
            case 0:
                    printf("Pilha Criada\n");
                    camisasP = estoquePilha();
                    returnMenu = 's';
            break;
            case 1:
                    printf("Adicionar camisa na pilha(cor,valor,quantidade)\n");
                    printf("Cor: ");
                    scanf("%s",&color);
                    printf("Preco: ");
                    scanf("%f",&price);
                    printf("Quantidade: ");
                    scanf("%d",&quantity);
                    push(camisasP,color,price,quantity);
                    printf("Voltar para o menu\n");
                    scanf("%s",&returnMenu); 
            break;
            case 2:
                    imprimirP(camisasP);
                    printf("voltar para o menu\n");
                    scanf("%s",&returnMenu); 
            break;

            case 3:
                   if (!ehvazio(camisasP))
                   {
                    printf("Remover camisa\n");
                    excluirp = pop(camisasP);
                    free(excluirp);
                   }
            break;
            case 4:
                    printf("Excluir pilha\n");
                    printf("tem certeza? ");
                    scanf("%s", &excluirL);
                    if(excluirL == 's'){
                        camisasP = excluir(camisasP);
                    }
                        printf("voltar para o menu\n");
                        scanf("%s",&returnMenu);
            break;
            default:
                    printf("valor invalido\n");
            break;
        }
    }while(returnMenu == 's');       
}