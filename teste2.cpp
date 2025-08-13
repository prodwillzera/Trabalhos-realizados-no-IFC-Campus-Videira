#include <stdio.h>
#include <stdlib.h>
#define texto "Entrada e saida de dados."

int main(){
    printf("%s\n", texto);

    int idade = 0;
    float altura = 0.0;
    char nome[50] = "";

    printf("Digite a sua idade:\n");
    scanf("%d", &idade);
    printf("Digite a sua altura:\n");
    scanf("%f", &altura);
    printf("Digite o seu nome:\n");
    scanf("%s", nome);

    system("pause");

    printf("\n\n\nDados informados:\n");
    printf("Sua idade e: %d anos.\n", idade);
    printf("Sua altura e: %.2f metros.\n", altura);
    printf("Seu nome e: %s.\n", nome);

    return 0;
}