#include <stdio.h>

int main()
{
    int a = 1; //caso coloque um valor 
    //acima do pedido ele ira imprimir pelo menos uma vez 

    do
    {
        printf("%d ",a);
        a++;
    } while (a <=100);
    
    return 0;
}
