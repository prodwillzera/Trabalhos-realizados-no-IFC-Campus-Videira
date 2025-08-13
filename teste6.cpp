#include <stdio.h>
#include <stdlib.h>

int main()
{
    float m;

    printf("Insira a nota:\n");
    scanf("%f", &m);
    system("pause");
    if(m>=7.0){
        printf("Aprovado(a)!\n");
    }else{
        printf("Reprovado(a)!\n");
    }
    return 0;
}

//if(<condicao>){
//  <bloco_de_comandos1>
//}
//else{
//  <bloco_de_comando2>
//}