#include <stdio.h>

int main(int argc, char const *argv[])
{
    float cm, pol, convert;

    printf("Digite um numero em cm e descubra a polegada: ");
    scanf("%f",&cm);

    pol = 0.39;
    convert  = cm * pol ;
    




    printf("\nas polegadas sao: %.1f",convert);
    return 0;
    
}
