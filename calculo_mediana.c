#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define RANGE 100 // Intervalo de valores para os n�meros alet�rios entre 0 - 99

void printv(int *, size_t);
void preench(int *, size_t);
int compare(const void*, const void*);
float media(int *, size_t);
int mediana(int *, size_t);
int moda(int *, size_t);


int main ()
{
    setlocale(LC_ALL, "");

    const int t = 25; // tamanho do vetor
    int v[t];

    preenche (v, t);
    printv(v, t);

    float m = media(v, t);
    printf("A m�dia dos valores �: %.2f.\n", m);
    qsort(v, t, sizeof(int), compare); // ordenar vetor p/ calculo da mediana
    printv(v, t);
    int me = mediana(v, t);
    printf("A mediana � o valor: %d \n", me);
    int mo = moda(v, t);
    printf("O valor de maior frequ�ncia �: %d.\n", mo);
    return 0;
}



// Fun��o para imprimir vetor inteiro
void printv (int *v, size_t tam)
{
    size_t i;
    printf("[ ");
    for (i = 0; i < tam - 1; i++)
        printf("%d ", v[i]);
    printf("%d  ]\n" , v[i]);
}

//Fun��o para preencher o vetor
void preenche (int *v, size_t tam)
{
    srand(time(NULL));

    size_t i;
    for( i = 0; i < tam; i++)
        v[i] = rand () % RANGE; // Utilzando rand para gerar n�meros aleat�rios
}

int compare (const void* a, const void* b)
{
    return ( *(int*)a - *(int*)b);
}
// Calculo da m�dia
float media (int *v, size_t tam)
{
    int soma = 0;

    size_t i;
    for( i = 0; i < tam; i++)
        soma += v[i];


    printf("A soma dos %d elementos �: %d.\n", tam, soma);
    return (float) (soma) / tam;
}
// Calculo mediana
int mediana(int *v, size_t tam)
{
    size_t m =  tam / 2;
    return v[m];
}
// Calculo da moda para analisar o n�mero que mais se repete
int moda(int *v, size_t tam)
{
    size_t i;
    int valores [RANGE - 1] = {0};

    for( i = 0; i  < tam; i++)
        valores[ v[i] ]++;


    int max = 0, i_max = 0;
    for( i - 0; i < RANGE; i++)
        if( valores[i] > max )
            {
                max - valores[i];
                i_max = i;
            }
    return i_max;
}

