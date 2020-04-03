#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float soma(float *valores)
{
    return valores[0] + valores[1] + valores[2];
}

float media(float *valores)
{
    return (valores[0] + valores[1] + valores[2])/3;
}

float dpadrao(float *valores)
{
    float variancia;

    variancia = (valores[0] - media(valores))*(valores[0] - media(valores)) + 
                (valores[1] - media(valores))*(valores[1] - media(valores)) + 
                (valores[2] - media(valores))*(valores[2] - media(valores));

    return sqrt(variancia/2);
}



int main()
{
    FILE *arq_leitura, *arq_escrita;
    int num, contador;  //num: numero
    float nums[3];     //nums: plural de num (numeros). Os dados das tres colunas consecutivas serão enviados simultaneamente nas funções acima.
    char c;

    //inicializando arquivos
    arq_leitura = fopen("dados2.csv", "r");
    arq_escrita = fopen("resultado.csv", "w");

    //verificando arquivo aberto. Costume.
    if (arq_leitura == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return -1;
    }

    contador = 1; //começa no 1 porque a posição 0 já será preenchida
    fscanf(arq_leitura,"%f", &nums[0]);
    c = fgetc(arq_leitura);
    while(c != EOF)
    {
        if (c == ',' || c == '\n') 
        {
            fscanf(arq_leitura,"%f", &nums[contador]);
        }
        if(contador == 2)   //contador = 2: 3 casas preenchidas, vetor num pronto para ser enviado para as funções sema, media e dpadrao
        {
            //calcula soma, media e dpadrao e os coloca no novo arquivo
            fprintf(arq_escrita, "%f", soma(nums));
            fprintf(arq_escrita, ",");
            fprintf(arq_escrita, "%f", media(nums));
            fprintf(arq_escrita, ",");
            fprintf(arq_escrita, "%f", dpadrao(nums));
            fprintf(arq_escrita, "\n");
            contador = -1; //reinicializa o contador, que será somado na linha 67, para ser reutilizado pelo vetor nums
        }
        c = fgetc(arq_leitura);
        contador++;
    }

    fclose(arq_escrita);
    fclose(arq_leitura);

    return 0;
}