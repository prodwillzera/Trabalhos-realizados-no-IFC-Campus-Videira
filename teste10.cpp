#include <stdio.h>

int main()
{
    int a;

    for (a=1; a <= 10; a++)
    {
        if(a==5){
            continue; //ignora o 5
        }
        printf("%d ", a);
    }
    for (a=0; a < 10; a++)
    {
        printf("%d ", a);
        if(a==5){
            break; // ignora tudo e fecha o sistema
        }
    }
    return 0;
}
