#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nota;
    float notas;

    printf("Coloque a sua nota: \n");
    scanf("%f", &nota);

    system("pause");

    notas = 6 - nota;

    if(nota >= 6.0){
        printf("aprovado com %.2f", nota);
    }
    else if (nota <= 6.0){
        printf("reprovado com %.2f, faltando %.2f ponto", nota,notas);
    }
    else{
        printf("operacao invalida");
    }

    return 0;
}
