/*
    Escreva uma função que recebe uma lista duplamente encadeada não circular e a transforme em lista duplamente encadeada circular,
    SEM ALOCAR NOVOS ELEMENTOS, NEM LIBERAR MEMÓRIA DOS EXISTENTES.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elementoduplo
{
    int dado;
    struct elementoduplo *proximo;
    struct elementoduplo *anterior;
} ElementoDuplo;

typedef struct listadupla
{
    ElementoDuplo *inicio;
    int tamanho;
} ListaDupla;

ListaDupla inicializaListaDupla()
{
    ListaDupla *l;
    l = (ListaDupla *)malloc(sizeof(ListaDupla));
    l->inicio = NULL;
    l->tamanho = 0;
    return *l;
}

void colocaDado(int d, ListaDupla *l, int pos)
{

    ElementoDuplo *andarilho = l->inicio;
    ElementoDuplo *anterior = NULL;

    ElementoDuplo *novoDado;
    novoDado = (ElementoDuplo *)malloc(sizeof(ElementoDuplo));
    novoDado->dado = d;

    // inserção no início da lista
    if (pos == 0)
    {
        novoDado->proximo = l->inicio;
        novoDado->anterior = NULL;
        l->inicio = novoDado;
    }
    else
    {
        // inserção no final da lista
        if (pos == l->tamanho)
        {
            while (andarilho->proximo != NULL)
            {
                andarilho = andarilho->proximo;
            }
            andarilho->proximo = novoDado;
            novoDado->anterior = andarilho;
            novoDado->proximo = NULL;
        }
        else
        {
            // outros casos
            int i = 0;
            while (i < pos)
            {
                anterior = andarilho;
                andarilho = andarilho->proximo;
                i++;
            }

            novoDado->anterior = anterior;
            anterior->proximo = novoDado;
            novoDado->proximo = andarilho;
            andarilho->anterior = novoDado;
        }
    }

    l->tamanho++;
}

void imprimeListaDupla(ListaDupla *l)
{
    ElementoDuplo *iterador;
    iterador = l->inicio;

    if (iterador == NULL)
    {
        printf("Lista vazia!");
    }
    else
    {
        while (iterador != NULL)
        {
            printf("%i ", iterador->dado);
            iterador = iterador->proximo;
        }
    }
    printf("\nO tamanho da lista dupla e: %i \n", l->tamanho);
    printf("\n");
}

void imprimeListaCircular(ListaDupla *l)
{
    if ((l->tamanho == 0) || (l == NULL))
        return;
    ElementoDuplo *iterador = l->inicio;
    //imprime o primeiro
    printf("%d ", iterador->dado);
    iterador = iterador->proximo;
    while (iterador != l->inicio)
    {
        printf("%d ", iterador->dado);
        iterador = iterador->proximo;
    }

    printf("\nO tamanho da lista circular e: %i \n", l->tamanho);
    printf("\n");
}

void convert_to_circular(ListaDupla *l){
    // l->inicio->anterior = l->fim
    // l->fim->proximo = l->inicio

    ElementoDuplo *andarilho = l->inicio;
    ElementoDuplo *anterior = NULL;

    int i = 0;
    while (i < l->tamanho)
    {
        anterior = andarilho;
        andarilho = andarilho->proximo;
        i++;
    }
    l->inicio->anterior = andarilho;
    anterior->proximo = l->inicio;
}

int main()
{
    ListaDupla l = inicializaListaDupla();
    colocaDado(1, &l, 0);
    colocaDado(2, &l, 1);
    colocaDado(3, &l, 2);
    colocaDado(4, &l, 3);
    
    imprimeListaDupla(&l);

    convert_to_circular(&l);
    imprimeListaCircular(&l);
    
    return 0;
}
