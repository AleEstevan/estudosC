/************************************************************************************
 * Nome: fila encadeada (Loja de camisas)                                           *
 * Descricao: Implementacao de fila encadeada. Esse codigo possui                   *
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

typedef struct loja Loja;
typedef struct camisa Camisa;


struct loja 
{
    Camisa *first;
    Camisa *last;
};
struct camisa
{
    char color[20];
    float price;
    int quantity;
    Camisa *next;
};
/* Nome: filaEstoque
 * Parametro: void 
 * Descricao: Função responsavel pela criacao da fila
 */
Loja* FilaEstoque() {
    Loja *new = (Loja*)malloc(sizeof(Loja));
    // verificação
    if (new == NULL) {
		printf("Estoque vazio\n");
		return NULL;
	}
    //Dados inicias
    new->first = NULL;
    new->last = NULL; 

    return new;
}
/* Nome: enqueue
 * Parametros: loja, color, price, quantity 
 * Descricao: Função criada para inserir um elemento na fila
 */
int enqueue(Loja *loja, char *color, float price, int quantity) {
    Camisa *new = (Camisa*)malloc(TAM*sizeof(Camisa));
    //verificação
    if (new == NULL) {
        printf("Sem espaço\n");
        return 0;
    }

    strcpy(new->color, color);
    new->price = price;
    new->quantity = quantity;
    new->next = NULL;
    
    if (loja->first == NULL) {
        loja->first = new;
        loja->last = new;
        return 1;
    }

    loja->last->next = new;
    loja->last = new;  
}
/* Nome: imprimir
 * Parametro: loja
 * Descricao: Função criada para apresentar todos elementos presentes na fila
 */
void imprimir(Loja *loja) {
    Camisa *p;
    //verificação
    if (loja == NULL) {
        printf("Lista nao criada\n");
        return ;
    }
    //verificação
    if (loja->first == NULL) {
        printf("Lista vazia\n");
        return ;
    }
    for (p = loja->first; p != NULL; p = p->next) {
        printf("Cor: %s\nPreco: %.2f\nQuantidade: %d\n", p->color, p->price, p->quantity);
        printf("\n");
    }
}
/* Nome: remover da fila
 * Parametro: loja, cor
 * Descricao: Função criada para remover da fila
 */
Camisa* dequeue(Loja *loja, char *color) {
    Camisa *p;

    // verificação
    if (loja == NULL) {
        printf("Sem estoque\n");
        return NULL;
    }

    // verificação
    if (loja->first == NULL) {
        printf("Estoque vazio\n");
        return NULL;
    }
    if(loja->first == loja->last){
        p = loja->first;
        loja->first = NULL;
        loja->last = NULL;
        return p;
    }
    
    p = loja->first;
    loja->first = loja->first->next;
    return p;

}
/* Nome: excluir
 * Parametro: loja
 * Descricao: Função responsavel pela exclusao do estoque
 */
Loja* excluir(Loja* loja){
    Loja *aux;
    while(loja->first != NULL){
        aux = loja->first;
        loja->first = loja->first->next;
        free(aux);
    }
    free(loja);
    return NULL;
}
void opcoesM(){
    printf("\t***************************");
    printf("\n\t******LOJA DE CAMISAS******\n");
    printf("\t***************************\n\n");
    printf("[0]- Criar fila\n");      
    printf("[1]- Adicionar cor na fila(cor,valor,quantidade)\n");       
    printf("[2]- Mostrar camisas\n");      
    printf("[3]- Remover camisa da fila\n");       
    printf("[4]- Excluir fila\n");
}
int main(){
    /*Ponteiro para a lista*/
    Loja *camisas;
    Camisa *excluirFila;
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
    do{
        printf("\t DIGITE O NUMERO E CONFIRME: ");
        scanf("%d",&opcoes);
         switch (opcoes)
        {  
            case 0:
                    printf("Fila Criada\n");
                    camisas = FilaEstoque();
                    returnMenu = 's';
            break;              
            case 1: 
                    printf("Adicionar camisa na fila(cor,valor,quantidade)\n");
                    printf("Cor: ");
                    scanf("%s",&color);
                    printf("Preco: ");
                    scanf("%f",&price);
                    printf("Quantidade: ");
                    scanf("%d",&quantity);
                    enqueue(camisas,color,price,quantity);
                    printf("Voltar para o menu(s/n)\n");
                    scanf("%s",&returnMenu); 
            break;
            case 2:
                    imprimir(camisas);
                    printf("Voltar para o menu(s/n)\n");
                    scanf("%s",&returnMenu); 
            break;
            case 3:
                    printf("Remover camisa(cor)\n");
                    excluirFila = dequeue(camisas,color);
                    free(excluirFila);
                    printf("Voltar para o menu(s/n)\n");
                    scanf("%s",&returnMenu); 
            break;
            case 4:
                    printf("Excluir fila\n");
                    printf("tem certeza? ");
                    scanf("%s", &excluirL);
                    if(excluirL == 's'){
                        camisas = excluir(camisas);
                    }
                    printf("Voltar para o menu(s/n)\n");
                    scanf("%s",&returnMenu); 
            break;
            default:
                    printf("valor invalido\n");
            break;
        }
    }while(returnMenu == 's');       
}