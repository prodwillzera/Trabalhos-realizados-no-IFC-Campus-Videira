#include <stdio.h>

int main()
{
    int a;
    printf("Digite um valor:\n");
    scanf("%i",&a);

    if(a %2 == 0){
        printf("O valor %i eh par.", a);
    }
    else {
        printf("O valor %i eh impar.", a);
    }
    return 0;
}
