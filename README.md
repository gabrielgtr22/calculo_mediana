# calculo_mediana
Projeto desenvolvido para teste técnico com objetivo de extrair a mediana de uma lista com mais de 1 milhão de números.

![image](https://user-images.githubusercontent.com/87664995/129911719-1303bea9-2ed9-49d2-b102-d9daabf13c20.png)

Proposta: Receber uma lista com mais de um milhão de elementos e  extrair a mediana.
Linguagem: C
-------------------------------------------------------------------------------------------------------------------------------------
## Testes 

Para simular o funcionamento do programa, foi utilizando um vetor de tamanho 25 que pode ser alterado no campo `const int t = 25;`
Caso você queira aumentar o tamanho do vetor simulando listas de 100,1000,10000, 100000, é possível.
A escolha do tamanho do vetor tem como objetivo mostrar a mediana com fácil visualização conforme abaixo: 

![image](https://user-images.githubusercontent.com/87664995/129912626-12d1dd22-f5d8-4292-9920-e6615289d9cf.png)

Com valores mais altos o tempo para exucação pode demorar, segue o exemplo com 100.000 `const int t = 100000;` :

![image](https://user-images.githubusercontent.com/87664995/129913545-b102df89-a32c-4e9d-a7ed-0c4abc3ec69f.png)

O valor de `RANGE 100` é utilizado para determinar um intervalo de variação de 0-99, para que não haja números muito grande na simulação. 

## Função -  Média
```c
float media (int *v, size_t tam)
{
    int soma = 0;

    size_t i;
    for( i = 0; i < tam; i++)
        soma += v[i];


    printf("A soma dos %d elementos é: %d.\n", tam, soma);
    return (float) (soma) / tam;
}
```
é possível tirar a prova real da média utilizando o valor que é fornecido pela `soma` → ` printf("A soma dos %d elementos é: %d.\n", tam, soma);`

## Função - Mediana
```c

int mediana(int *v, size_t tam)
{
    size_t m =  tam / 2;
    return v[m];
}
```

Não é possível calcular a media em vetores desordenados, por isso foi utilizado na funação `main` o elemento `qsort`  
Ele está incluindo na biblioteca padrão do C `#include <stdlib.h>`

## Função  - Moda

```c
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
```

A função moda foi utilziada para apresentar o número que aparece com maior frequência no vetor. 

## Bugs

Caso você encontre um bug, comente no repositório! 
