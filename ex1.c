#include <stdio.h>
#include <math.h>
//#define N 10              desafio 1 -> apagar N na linha 9

int main()
{
    double n[N];
    double soma, media, dpadrao, variancia = 0;
    int i, N;

    printf("Entre com a quantidade de numeros a ser inserida:");
    scanf("%d", &N);

    printf("Insira %d números inteiros:\n", N);

    for (i=0; i<N; i++)
    {
        scanf("%lf", &n[i]);
        soma += n[i];
        media += n[i]*(1/double(N));
    }

    for(i=0; i<N; i++)
    {
        variancia += (n[i] - media)*(n[i] - media);
    }

    dpadrao = sqrt(variancia/(N-1));

    printf("\nSoma: %f", soma);
    printf("\nMedia: %f", media);
    printf("\nDpadrao: %f", dpadrao);
    printf("\n");

    return 0;
}