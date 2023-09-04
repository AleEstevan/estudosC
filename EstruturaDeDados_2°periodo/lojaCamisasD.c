/************************************************************************************
 * Nome: lista duplamente encadeada (Loja de camisas)                             *
 * Descricao: Implementacao de lista encadeada. Esse codigo possui                  *
 *           as principais operacoes da lista, como:                                *
 *           criar lista,                                                           *
 *           inserirElemento (inseri no final da lista),                            *
 *           inserirElementoID (inseri na posição indicada da lista)                *
 *           inserirElementoInicio (inseri no início lista)                         *
 *           listarElemento (apresenta todas as informações dos elementos da lista) *
 *           removerElemento (remove pela posição)                                  *
 *           removerElementoNome (remove pelo nome)                                 *
 *           excluirLista (apagar todos os elementos e a lista)                     *
 *           buscarElemento (encontrar e retorna o elemnto pesquisado),             *
 *           tamanho (retorna a quantidade de elementos da lista)                   *
 *           atualizar (alterar os campos de um elemnto da lista),                  *
 *           main (fazer aplicação com funções anteriores)                          *
 * Autor: Alejandro Estevan e Rafael Santiago                                       *
 * Ultima alteracao: 15/05/2023                                                     *
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
    Camisa *back;
};
/* Nome: Estoque
 * Parametro: void 
 * Retorno: endereço do espaço de memoria reservado pelo malloc
 * Descricao: Função responsavel pela criacao da lista e inicializção
 */
Loja* estoque() {
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
/* Nome: addEstoqueFinal
 * Parametros: loja, color, price, quantity 
 * Descricao: Função criada para inserir um elemento no final da lista
 */
int addEstoqueFinal(Loja *loja, char *color, float price, int quantity) {

    Camisa *new = (Camisa*)malloc(TAM*sizeof(Camisa));
    //verificação
    if (new == NULL){
		printf("espaco vazio\n");
		return 0;
	}

	strcpy(new->color, color);
	new->price = price;
	new->quantity = quantity;
	new->next = NULL;
	new->back = NULL;
	
	if(loja->first == NULL){
		loja->first = new;
		loja->last = new;
		return 1;
	}
	loja->last->next = new;
	new->back = loja->last;
	loja->last = new;
	
	return 1;
}
/* Nome: addEstoqueID
 * Parametros: loja, color, price, quantity , posicao
 * Descricao: Função criada para inserir um elemento pelo ID da lista
 */
int addEstoqueID(Loja *loja, char *color, float price, int quantity, int posicao) {
    Camisa *new = (Camisa*)malloc(sizeof(Camisa));
    //verificação
    if (new == NULL) {
        printf("Sem espaço\n");
        return 0;
    } 
    strcpy(new->color, color);
    new->price = price;
    new->quantity = quantity;
    new->back = NULL;
    new->next = NULL;

    if (loja->first == NULL) { 
        loja->first = new;
        loja->last = new;
        return 1;
    }
    
    if (posicao <= 1) { 
        new->next = loja->first;
        loja->first->back = new;
        loja->first = new;
        return 1;
    }
    
    Camisa *p = loja->first;
    int position = 1;
    
    while (p->next != NULL && position < posicao - 1) {
        p = p->next;
        position++;
    }
    
    new->next = p->next;
    if (p->next != NULL) {
        p->next->back = new;
    }
    p->next = new;
    new->back = p;

    if (new->next == NULL) {
        loja->last = new;
    }
    return 1;
}
/* Nome: addEstoqueInicio
 * Parametros: loja, color, price, quantity 
 * Descricao: Função criada para inserir um elemento no inicio da lista
 */
int addEstoqueIninio(Loja *loja, char *color, float price, int quantity) {
    Camisa *new = (Camisa*)malloc(sizeof(Camisa));
    // verificação
    if (new == NULL) {
        printf("Sem espaço\n");
        return 0;
    } 
    strcpy(new->color, color);
    new->price = price;
    new->quantity = quantity;
    new->back = NULL;
    new->next = NULL;

    if (loja->first == NULL) {
        loja->first = new;
        loja->last = new;
        return 1;
    }

    new->next = loja->first;
    loja->first->back = new;
    loja->first = new;
    return 1;
}
/* Nome: imprimir
 * Parametro: loja
 * Descricao: Função criada para apresentar todos elementos presentes na lista
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
/* Nome: imprimIrnverso
 * Parametro: loja
 * Descricao: Função criada para apresentar inverso todos elementos presentes na lista
 */
void imprimirInverso(Loja *loja){
	Camisa *p;
	if(loja == NULL){
		printf("Sem lista");
		return ;
	}
	
	if(loja->first == NULL){
		printf("Lista vazia");
		return ;
	}
	
	for (p = loja->last; p!=NULL; p = p->back) {
        printf("Cor: %s\nPreco: %.2f\nQuantidade: %d\n", p->color, p->price, p->quantity);
        printf("\n");
    }
	printf("\n");
}
/* Nome: tamanhoLista
 * Parametro: loja
 * Descricao: Função criada para apresentar a quantidade elementos presentes na lista
 */
int tamanhoLista(Loja *loja) {
    Camisa *p;
    int tamanho = 0;
    //verificação
    if (loja == NULL) {
        printf("Sem estoque\n");
        return 0;
    }
    //verificação
    if (loja->first == NULL) {
        printf("Estoque vazio\n");
        return 0;
    }
    p = loja->first;
    while (p != NULL) {
        tamanho++;
        p = p->next;
    }
    printf("Camisas adicionadas: %d\n", tamanho);
    return tamanho;
}
/* Nome: removerCor
 * Parametro: camisasEstoque, cor
 * Descricao: Função criada para remover uma cor do estoque
 */
int removerCor(Loja *loja, char *color) {
    Camisa *p, *aux;

    // verificação
    if (loja == NULL) {
        printf("Sem estoque\n");
        return 0;
    }

    // verificação
    if (loja->first == NULL) {
        printf("Estoque vazio\n");
        return 0;
    }

    if (strcmp(loja->first->color, color) == 0) {
        p = loja->first;
        loja->first = loja->first->next;
        if (loja->first != NULL) {
            loja->first->back = NULL;
        } else {
            loja->last = NULL;
        }
        free(p);
        return 1;
    }

    for (p = loja->first; p != NULL; p = p->next) {
        if (strcmp(p->color, color) == 0) {
            aux = p;
            p->back->next = p->next;
            if (p->next != NULL) {
                p->next->back = p->back;
            } else {
                loja->last = p->back;
            }
            free(aux);
            return 1;
        }
    }

    return 0;
}
/* Nome: removerPosicao
 * Parametro: camisasEstoque, posião
 * Descricao: Função responsavel por remover pela posição
 */
int removerPosicao(Loja *loja, int posicao) {
    Camisa *p, *aux;
    int i;
    // verificação
    if (loja == NULL) {
        printf("Sem estoque\n");
        return 0;
    }
    // verificação
    if (loja->first == NULL) {
        printf("Estoque vazio\n");
        return 0;
    }
    if (posicao == 1) {
        p = loja->first;
        loja->first = loja->first->next;
        if (loja->first != NULL) {
            loja->first->back = NULL;
        } else {
            loja->last = NULL;
        }
        free(p);
        return 1;
    }
    p = loja->first;
    for (i = 1; i < posicao-1 && p != NULL; i++) {
        p = p->next;
    }
    // verificação
    if (p == NULL || p->next == NULL) {
        printf("Posicao invalida\n");
        return 0;
    }
    aux = p->next;
    p->next = aux->next;
    if (aux->next != NULL) {
        aux->next->back = p;
    } else {
        loja->last = p;
    }
    free(aux);
    return 1;
}

/* Nome: excluir
 * Parametro: camisasEstoque 
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
/* Nome: buscarCor
 * Parametro: camisasEstoque color
 * Descricao: Funcao criada para buscar um elemento na lista
 */
Camisa *buscarCor(Loja *loja, char *color) {
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

    for (p = loja->first; p != NULL; p = p->next) {
        if (strcmp(p->color, color) == 0) {
            return p;
        }
    }

    return NULL;
}
/* Nome: atualizar
 * Parametros: camisasEstoque, busca, quantidade 
 * Descricao: Função responsavel por atualizar a quantidade
 */
int atualizar(Loja *loja, int busca, int quantity ){
    Camisa *p;
    //verificação
    if(loja == NULL){
        printf("sem estoque\n");
        return 0;
    }
    //verificação
    if(loja->first == NULL){
        printf("Estoque vazio\n");
        return 0;
    }
    for(p = loja->first; p != NULL; p = p->next){
        if(p->quantity == busca){
            p->quantity = quantity;
            return 1;
        }
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
    printf("[1]- Adicionar camisa no incio(cor,valor,quantidade)\n");
    printf("[2]- Adicionar camisa em ordem selecionada(cor,valor,quantidade,posicao)\n");      
    printf("[3]- Adicionar cor no final(cor,valor,quantidade)\n");       
    printf("[4]- Mostrar estoque de camisas\n");  
    printf("[5]- Mostrar estoque de camisas ao inverso\n");    
    printf("[6]- Atualizar quantidade\n");       
    printf("[7]- Saber quantidade de camisas\n");        
    printf("[8]- Buscar cor de camisas\n");        
    printf("[9]- Remover camisa(cor)\n");       
    printf("[10]- Remover camisa(ordem desejada\n");
    printf("[11]- Excluir lista\n");
    printf("[12]- Sair do programa\n");
}
int main(){
    /*Ponteiro para a lista*/
    Loja *camisas;
    Camisa *pesquisa;

    //variaveis dos parametros
    char color[20];
    float price;
    int quantity;
    int posicao;
    int tamanho;
    //variaveis do programa
    int opcoes;
    char excluirL;
    int atualValor;
    int valorAtualizado;

    //programa
    opcoesM();
    do{
        printf("\t DIGITE O NUMERO E CONFIRME: ");
        scanf("%d",&opcoes);
         switch (opcoes)
        {  
            case 0:
                    printf("Lista Criada\n");
                    camisas = estoque();
            break;
            case 1:
                    printf("Adicionar camisa no incio(cor,valor,quantidade)\n");
                    printf("Cor: ");
                    scanf("%s",&color);
                    printf("Preco: ");
                    scanf("%f",&price);
                    printf("Quantidade: ");
                    scanf("%d",&quantity);
                    addEstoqueIninio(camisas,color,price,quantity);
            break;
            case 2:
                    printf("Adicionar camisa na ordem selecionada(cor,valor,quantidade,posicao)\n");
                    printf("Cor: ");
                    scanf("%s",&color);
                    printf("Preco: ");
                    scanf("%f",&price);
                    printf("Quantidade: ");
                    scanf("%d",&quantity);
                    printf("Adiciona posicao: ");
                    scanf("%d",&posicao);
                    addEstoqueID(camisas,color,price,quantity,posicao);
            break; 
            case 3: 
                    printf("Adicionar camisa no final(cor,valor,quantidade)\n");
                    printf("Cor: ");
                    scanf("%s",&color);
                    printf("Preco: ");
                    scanf("%f",&price);
                    printf("Quantidade: ");
                    scanf("%d",&quantity);
                    addEstoqueFinal(camisas,color,price,quantity);
            break;
            case 4:
                    imprimir(camisas);
            break;
            case 5:
                    imprimirInverso(camisas);
            break;
            case 6:
                    printf("Atualizar quantidade\n");
                    printf("Digite a quantidade atual: ");
                    scanf("%d", &atualValor);
                    printf("Digite a nova quantidade: ");
                    scanf("%d", &valorAtualizado);
                    atualizar(camisas,atualValor, valorAtualizado);
            break;
            case 7:
            tamanho = tamanhoLista(camisas);
            break;
            case 8:
                    printf("Buscar cor de camisas\n"); 
                    printf("Digite cor desejada: ");
                    scanf("%s",&color);
                    pesquisa = buscarCor(camisas,color);
                    printf("\ncor: %s\n",pesquisa);
            break;
            case 9:
                    printf("Remover camisa(cor)\n");
                    printf("Digite a cor a ser removida: ");
                    scanf("%s",&color);
                    removerCor(camisas,color);
            break;
            case 10:
                    printf("Remover camisa ordem desejada\n");
                    printf("Digite a posicao da cor a ser removida: ");
                    scanf("%d", &posicao);
                    removerPosicao(camisas,posicao);
            break;
            case 11:
                    printf("Excluir lista\n");
                    printf("tem certeza? ");
                    scanf("%s", &excluirL);
                    if(excluirL == 's'){
                        camisas = excluir(camisas);
                    }
            break;
            case 12:
                    printf("programa fechado");
            break;
            default:
                    printf("valor invalido\n");
            break;
        }
    }while(opcoes != 12);       
}