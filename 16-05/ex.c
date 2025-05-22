#include<stdio.h>
#include"lista.h"

int main(){

    Celula *lista = NULL;

    lista = inserir(6,lista);
    lista = inserir(10,lista);
    lista = inserir(7,lista);
    lista = inserir(8,lista);
    lista = inserir(2,lista);
    lista = inserir(9,lista);
    lista = inserir(1,lista);

    int quant = conta(lista);
    printf("Lista contem %d elementos\n", quant);
    exibir(lista);


    int orde = estaOrdenadaOuNao(lista);
    if (orde == 1){
        printf("Esta ordenada");
    } else{
        printf("Nao esta");
    }


    printf("\nMostrando lista ordenada\n");
    lista = ordenar(lista);
    exibir(lista);

    orde = estaOrdenadaOuNao(lista);
    if (orde == 1){
        printf("Esta ordenada");
    } else{
        printf("Nao esta");
    }


    printf("\nBuscando o numero 7 na lista\n");
    estaNaLista(lista,7);

    printf("\nOcorrencia de 2\n");
    quant = ocorrenciaDeNumero(lista,2);
    printf("%d",quant);


    printf("\nMEDIA\n");
    float m = media(lista);
    printf("%.2f",m);

    return 0;
}