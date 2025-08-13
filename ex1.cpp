#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{   
    float a,b;
    int op;
    printf("Digite 1 para realizar a soma de dois valores:\nDigite 2 para realizar a raiz cubida de dois valores:\n");
    scanf("%d", &op);
    switch (op){
        case 1:
            printf("Digite o valor de A:\n");
            scanf("%f",&a);
            printf("Digite o valor de B:\n");
            scanf("%f",&b);
            printf("A soma de %.2f e %.2f sera %.2f", a,b,a+b);
            break;
        case 2:
            printf("Digite o valor de A:\n");
            scanf("%f",&a);
            printf("A raiz cubida sera %.2f\n", cbrt(a));
        default:
            printf("opcao invalida");
            break;
    }
    return 0;
}
