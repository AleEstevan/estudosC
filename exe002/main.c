#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int n1, n2, ant, suc;

    printf("Digite um numero para saber seu sucessor e antecessor");
    scanf("%d",&n1);

   n2 = n1;

   ant = n1 - 1;
   suc = n2 + 1;

     printf("O antecessor de %d: %d \nO sucessor de %d: %d ", n1, ant, n2, suc);
    return 0;
}
