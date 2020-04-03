#include <stdio.h>
#include <math.h>

double soma(double *lista, int N)
{
    int i;
    double resultado = 0;

    for(i=0; i<N; i++)
    {
        resultado += lista[i];
    }

    return resultado;
}

double media(double *lista, int N)
{
    int i;

    double resultado;

    for(i=0; i<N; i++)
    {
        resultado += (1/double(N))*lista[i];
    }

    return resultado;
}

double dpadrao(double *lista, int N)
{
    int i;
    double resultado, variancia;
    double mean;

    resultado = variancia = 0;
    mean = media(lista, N);

    for(i=0; i<N; i++)
    {
        variancia += pow(lista[i] - mean,2);
    }

    resultado = sqrt(variancia/(N-1));
}


int main()
{
    int N, i;
    double n[100];

    printf("Insira o tamanho da lista:\n");
    scanf("%d", &N);

    printf("\nInsira os números da lista:\n");

    for(i=0; i<N; i++)
    {
        scanf("%lf", &n[i]);
    }

    printf("\nSoma: %f", soma(n, N));
    printf("\nMedia: %f", media(n, N));
    printf("\nDpadrao: %f", dpadrao(n, N));
    printf("\n");

    return 0;
}