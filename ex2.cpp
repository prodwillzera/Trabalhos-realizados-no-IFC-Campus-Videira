#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b;
    printf("Digite o valor de A.\n");
    scanf("%f", &a);
    printf("Digite o valor de B.\n");
    scanf("%f", &b);

    if(a>b){
        printf("O valor de A(%.2f) e maior que o de B(%.2f)", a,b);
    }
    else if(b>a){
        printf("O valor de B(%.2f) e maior que o de A(%.2f)", b,a);
    }
    else{
        printf("Operacao invalida");
    }
    return 0;
}
