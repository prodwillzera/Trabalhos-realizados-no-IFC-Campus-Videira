#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nota = 0.0;

    printf("digite sua nota:\n");
    scanf("%f", &nota);

    if(nota >= 4.00 && nota < 6.00){ //necessario fazer && com as comparacoes separadas para poder "harmonizar"
        printf("tem direito a exame!\n");
    }
    else if (nota < 4.00 && nota < 6.00) // se nao tiver o else if e else todo comando sera ignorado e nao sera impresso caso esteja escrito
    {
        printf("nao tem direito a exame!\n");
    }
    else if (nota >= 6){
        printf("nao tem direito a exame pois passou: \n");
    }
    else{
        printf("operacao invalida");
    }

    return 0;
}
