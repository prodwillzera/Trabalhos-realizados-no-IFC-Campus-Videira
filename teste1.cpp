#include <stdio.h>

int main(){
    int cortes = 0;
    int comprimidos = 0;

    printf("Voce fez %d cortes.\n", cortes);
    printf("Voce tomou %d comprimidos.\n", comprimidos);

    printf("Digite quantos cortes voce fez:\n");
    scanf("%d", &cortes);

    printf("Digite quantos comprimidos voce tomou:\n");
    scanf("%d", &comprimidos);

    printf("Agora voce tem um total de %d cortes.\n", cortes);
    printf("Voce tomou um total de %d comprimidos.\n", comprimidos);

    return 0;
}