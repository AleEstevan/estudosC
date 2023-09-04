#include <stdio.h> 
#include <stdlib.h>


int phi (int n){
    if (n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return phi(n - 1) + phi(n - 2); 
    } 
}
int main()
{
    int n = 6;
    int result = phi(n);

    printf("O fibonacci de %d e: %d\n", n, result);
    return 0;
}
