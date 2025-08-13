#include <stdio.h>
int main(){
    int v[5];
    int i;
    for(i=0;i<5;i++){
        printf("Inisira um dado:\n");
        scanf("%i", &v[i]);
    }

    printf("Dados inseridos:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }
}