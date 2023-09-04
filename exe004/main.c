#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n1,n2,soma;
    float div, pro;
    printf("A soma, o produto e o quociente\n");
    printf("Digite o primeiro numero: ");
    scanf("%d",&n1);
    printf("Digite o segundo numero: ");
    scanf("%d",&n2);
   
    soma = n1 + n2;
    div = n1 / n2;
    pro = n1 * n2;

    printf("\nA soma dos valores foi:%d \nO qupciente dos valores foi:%.2f \nO produto dos valores foi: %.2f", soma, div, pro );


    return 0;
}
