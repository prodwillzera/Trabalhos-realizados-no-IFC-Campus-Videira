#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dado = 10;
    printf("Dado antes do incremento: %d.\n", dado);

    system("pause");

    dado++;
    printf("Depois do incremento: %d.\n", dado);// mais 1
    dado--;
    printf("Depois do incremento: %d.\n", dado);// menos 1
    dado+= 3;
    printf("Depois do incremento em 3: %d.\n", dado);//adiciona 3
    dado-= 2;
    printf("Depois do incremento em 2: %d.\n", dado);//tira 2
    dado*= 10;
    printf("Depois do incremento em 10: %d.\n", dado);//mult por 10
    dado/= 5;
    printf("Depois do incremento: %d.\n", dado);//div por 5
    //tudo por ordem nao pelo valor dado inicial que e 10.
    return 0;
}
