/************************************************************************************
 * Nome: lista de vetor (Loja de camisas)                                           *
 * Descricao: Implementacao de lista de vetor. Esse codigo possui                   *
 *           as principais operacoes da lista, como:                                *
 *           criar lista,                                                           *
 *           inserirElementoInicio (inseri no início lista)                         *
 *           inserirElementoID (inseri na posição indicada da lista)                *
 *           inserirElementoFinal (inseri no final da lista),                       *
 *           listarElemento (apresenta todas as informações dos elementos da lista) *
 *           removerElemento (remove pela posição)                                  *
 *           removerElementoNome (remove pelo nome)                                 *
 *           excluirLista (apagar todos os elementos e a lista)                     *
 *           buscarElemento (encontrar e retorna o elemnto pesquisado),             *
 *           atualizar (alterar os campos de um elemnto da lista),                  *
 *           main (fazer aplicação com funções anteriores)                          *
 * Autor: Alejandro Estevan e Rafael Santiago                                       *
 * Ultima alteracao: 14/05/2023                                                     *
 ***********************************************************************************/

/*Include das bibliotecas*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAM 5

 
typedef struct{
    char color[20];  
    float price; 
    int quantity;
} Camisa;

typedef struct{
    int id;
    Camisa *elements;
} Loja;

/* Nome: Estoque
 * Parametro: void 
 * Retorno: endereço do espaço de memoria reservado pelo malloc
 * Descricao: Função responsavel pela criacao da lista e inicializção
 */
Loja* estoque(){
    //solicitando espaco na memoria
    Loja *new = (Loja*)malloc(sizeof(Loja));

    //Verificação de espaço
    if(new == NULL){
        printf("Sem espaco\n");
        return NULL;
    }

    //Preparando os dados iniciais 
    new->id = 0; 
    new->elements = (Camisa*)malloc(TAM*sizeof(Camisa));
    
    //verificação
    if(new->elements == NULL){
        printf("Sem espaco\n");
        free(new);
        return NULL;
    }

    
    return new;
}
/* Nome: addEstoqueInicio
 * Parametros: camisasEstoque, color, price, quantity 
 * Descricao: Função criada para inserir um elemento no inicio da lista
 */
int addEstoqueIninio(Loja *loja, char *color, float price, int quantity){
    int i;

    //verificação
    if(loja == NULL){
        printf("Sem estoque\n");
        return 0;
    }

    
    if(loja->id < TAM){
        
        for(i = loja->id; i > 0; --i){
            strcpy(loja->elements[i].color, loja->elements[i-1].color);
            loja->elements[i].price = loja->elements[i-1].price;
            loja->elements[i].quantity = loja->elements[i-1].quantity;
        }
        strcpy(loja->elements[0].color, color);
        loja->elements[0].price = price;
        loja->elements[0].quantity = quantity;
        ++(loja->id);
    }else{
        printf("Espaco esgotado\n");
        return 0;
    }
    return 1;
}
/* Nome: addEstoqueID
 * Parametros: camisasEstoque, color, price, quantity , posicao
 * Descricao: Função criada para inserir um elemento pelo ID da lista
 */
int addEstoqueID(Loja *loja, char *color, float price, int quantity, int posicao) {
    int i ;

    //verificação
    if(loja == NULL){
        printf("Sem estoque\n");
        return 0;
    }

    
    if(loja->id < TAM){
       
        if(posicao < loja->id){
            
            for(  i = loja->id; i > posicao ; --i){
                strcpy(loja->elements[i].color, loja->elements[i-1].color);
                loja->elements[i].price = loja->elements[i-1].price;
                loja->elements[i].quantity = loja->elements[i-1].quantity;
            }
           
            strcpy(loja->elements[posicao].color, color);
            loja->elements[posicao].price = price;
            loja->elements[posicao].quantity = quantity;
            
            ++(loja->id);
        }else{
            printf("Fora de Posicao\n");
            return 0;
        }
    }else{
        printf("Espaco esgotado\n");
        return 0;
    }

    return 1;
}
/* Nome: addEstoqueFinal
 * Parametros: camisasEstoque, color, price, quantity 
 * Descricao: Função criada para inserir um elemento no final da lista
 */
int addEstoqueFinal(Loja *loja, char *color, float price, int quantity){
    
    //verificação
    if(loja == NULL){
        printf("Sem Estoque\n");
        return 0;
    }
    
    if(loja->id < TAM){
        
        strcpy(loja->elements[loja->id].color, color);
        loja->elements[loja->id].price = price;
        loja->elements[loja->id].quantity = quantity;
       
        ++(loja->id);
    }else{
        printf("Espaco esgotado\n");
        return 0;
    }
    return 1;
}
/* Nome: imprimir
 * Parametro: camisasEstoque
 * Descricao: Função criada para apresentar todos elementos presentes na lista
 */
void imprimir(Loja *loja){
    int i;

    //verificação
    if(loja == NULL){
        printf("Sem estoque\n");
        return ;
    }

    //verificação
    if(loja->id == 0){
        printf("Estoque vazia\n");
        return ;
    }

    
    for (i = 0; i < loja->id; ++i) {
        printf("Cor: %s\nPreco: %.2f\nQuantidade: %d\n", loja->elements[i].color, loja->elements[i].price, loja->elements[i].quantity);
        printf("\n");
    }
}
/* Nome: removerPosicao
 * Parametro: camisasEstoque, posião
 * Descricao: Função responsavel por remover pela posição
 */
int removerPosicao(Loja *loja, int posicao){
    int i, j;

    //verificação
    if(loja == NULL){
        printf("Sem estoque\n");
        return 0;
    }

    
    if (posicao < loja->id){
       
        for(j = posicao; j < loja->id-1; ++j){
            strcpy(loja->elements[j].color, loja->elements[j+1].color);
            loja->elements[j].price = loja->elements[j+1].price;
            loja->elements[j].quantity = loja->elements[j+1].quantity;
        }
        
        --(loja->id);
        return 1;
    }else{
        printf("Posicao invalida\n");
    }

    return 0;
}
/* Nome: removerCor
 * Parametro: camisasEstoque, cor
 * Descricao: Função criada para remover uma cor do estoque
 */
int removerCor(Loja *loja, char *color){
    int i, j;

    //verificação
    if(loja == NULL){
        printf("Sem estoque\n");
        return 0;
    }

 
    for(i = 0; i < loja->id; ++i){
     
        if(strcmp(loja->elements[i].color, color) == 0){
         
            for(j = i; j < loja->id-1; ++j){
                strcpy(loja->elements[j].color, loja->elements[j+1].color);
                loja->elements[j].price = loja->elements[j+1].price;
                loja->elements[j].quantity= loja->elements[j+1].quantity;
            }
          
            --(loja->id);
            return 1;
        }
    }

    return 0;
}
/* Nome: excluir
 * Parametro: camisasEstoque 
 * Descricao: Função responsavel pela exclusao do estoque
 */
Loja* excluir(Loja* loja){
   
    free(loja->elements);
    
  
    free(loja);
    
    return NULL;
}
/* Nome: buscarCor
 * Parametro: camisasEstoque color
 * Descricao: Funcao criada para buscar um elemento na lista
 */
int buscarCor(Loja *loja, char *color){
    int i;

    //verificação
    if(loja == NULL){
        printf("Sem estoque\n");
        return -1;
    }

    
    for(i = 0; i < loja->id; ++i){
    
        if(strcmp(loja->elements[i].color, color) == 0){
            return i;
        }
    }

  
    return -1;
}
/* Nome: atualizarElemento
 * Parametros: lista  - ponteiro que possui o endereco lista
 *             busca  - elemento que sera buscado na lista
 *             nome   - novo nome da pessoa que sera alterado 
 *             idade  - idade da pessoa que sera alterada 
 *             altura - altura da pessoa que sera alterada 
 *             sexo   - sexo da pessoa que sera alterado 
 * Retorno: 1 - quando o valor e atualizado e 0 - caso contrario
 * Descricao: Funcao responsavel por atualizar a informacoes de uma pessoa
 *            da lista, caso a mesma esteja na lista indicada
 */
int atualizarElemento(Loja *loja, char *busca, char *color, int quantity ){
    int i;

    //verificação
    if(loja == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    
    for(i = 0; i < loja->id; ++i){
        
        if(strcmp(loja->elements[i].color, busca) == 0){
            
           
            loja->elements[i].quantity = quantity;

            return 1;
        }
    }
    return 0;
}
void opcoesM(){
    printf("\t***************************");
    printf("\n\t******LOJA DE CAMISAS******\n");
    printf("\t***************************\n\n");
    printf("[0]- Criar lista\n");
    printf("[1]- Adicionar camisa no incio(cor,valor,quantidade)\n");
    printf("[2]- Adicionar camisa em ordem selecionada(cor,valor,quantidade,posicao)\n");      
    printf("[3]- Adicionar cor no final(cor,valor,quantidade)\n");       
    printf("[4]- Mostrar camisas\n");      
    printf("[5]- Atualizar quantidade\n");             
    printf("[6]- Buscar cor de camisas\n");        
    printf("[7]- Remover camisa(cor)\n");       
    printf("[8]- Remover camisa(ordem desejada\n");
    printf("[9]- Excluir lista\n");
}
int main(){
    /*Ponteiro usado para a criacao da lista*/
    Loja *camisas = NULL;
     //variaveis dos parametros
    char color[20];
    float price;
    int quantity;
    int posicao;
    //variaveis do programa
    int opcoes;
    char returnMenu;
    char excluirL;
    int indiceEncontrado;
    char corBuscada[20];
    int atualValor;
    int resultado;
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
                    returnMenu = 's';
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
                    printf("Voltar para o menu(s/n)\n");
                    scanf("%s",&returnMenu); 
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
                    printf("Voltar para o menu(s/n)\n");
                    scanf("%s",&returnMenu); 
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
                    printf("Voltar para o menu(s/n)\n");
                    scanf("%s",&returnMenu); 
            break;
            case 4:
                    imprimir(camisas);
                    printf("Voltar para o menu(s/n)\n");
                    scanf("%s",&returnMenu); 
            break;
            case 5:
                   printf("Atualizar quantidade\n");
                    printf("Digite a cor que deseja atualizar: ");
                    corBuscada;
                    scanf("%s", corBuscada);
                    printf("Digite a quantidade atual: ");
                    atualValor;
                    scanf("%d", &atualValor);
                    printf("Digite a nova quantidade: ");
                    valorAtualizado;
                    scanf("%d", &valorAtualizado);
                    resultado = atualizarElemento(camisas, corBuscada, atualValor, valorAtualizado);
                    if (resultado == 1) {
                        printf("Quantidade atualizada com sucesso!\n");
                    } else {
                        printf("Elemento não encontrado\n");
                    }
                    printf("Voltar para o menu(s/n)\n");
                    scanf("%s",&returnMenu); 
            break;
            case 6:
                    printf("Buscar cor de camisas\n");
                    printf("Digite a cor desejada: ");
                    scanf("%s", color);
                    indiceEncontrado = buscarCor(camisas, color);
                    if (indiceEncontrado != -1) {
                        printf("\nCor encontrada: %s\n", camisas->elements[indiceEncontrado].color);
                    } else {
                        printf("Cor não encontrada\n");
                    }
                    printf("Voltar para o menu(s/n)\n");
                    scanf("%s",&returnMenu); 
            break;
            case 7:
                    printf("Remover camisa(cor)\n");
                    printf("Digite a cor a ser removida: ");
                    scanf("%s", color);
                    removerCor(camisas,color);
                    printf("Voltar para o menu(s/n)\n");
                    scanf("%s",&returnMenu); 
            break;
            case 8:
                    printf("Remover camisa ordem desejada\n");
                    printf("Digite a posicao da cor a ser removida: ");
                    scanf("%d", &posicao);
                    removerPosicao(camisas,posicao);
                    printf("Voltar para o menu(s/n)\n");
                    scanf("%s",&returnMenu); 
            break;
            case 9:
                    printf("Excluir lista\n");
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