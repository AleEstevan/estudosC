#include <stdio.h>

int main(int argc, char const *argv[])
{   
    float raio, pi,a;
    printf("     Descubra a area do circulo atras do raio\n\n\n");
    printf("Digite o raio do circulo");
    scanf("%f",&raio);

    pi = 3.14;

    a =  pi * pow(raio,2);
    
    printf("A area do circulo e: %.1f",a);

    return 0;
}
