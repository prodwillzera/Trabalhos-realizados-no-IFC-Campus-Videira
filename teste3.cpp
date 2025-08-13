#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, soma, sub, mult, div;

    printf("Digite o valor A:\n");
    scanf("%d", &A);

    printf("Digite o valor B:\n");
    scanf("%d", &B);

    soma = A+B;
    sub = A-B;
    mult = A*B;
    div = A/B;

    system("pause");

    printf("\nResultados:\n");
    printf("Resultado da soma e %d\n", soma);
    printf("\nResultado da subtracao e %d\n", sub);
    printf("\nResultado da multiplicacao e %d\n", mult);
    printf("\nResultado da divisao e %d\n", div);



    return 0;
}
