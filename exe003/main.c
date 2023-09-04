#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x, y,res,rest;
    

    printf("Digite dois numeros inteiros para saber seu quociente e resto da divisao\n");
    scanf("%d",&x);
    scanf("%d",&y);

    res = x % y;
    rest = x / y;
    printf("O resto da divisao: %d\nO quociente: %d",res,rest);

    return 0;
}