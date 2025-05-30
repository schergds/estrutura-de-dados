#include <stdio.h>
#include <time.h>
#include "lista.h"

int main(){
    Celula *listaA = NULL;
    Celula *listaB = NULL;
    srand(time(NULL));

    for(int i = 0; i <= 21; i++){
        listaA = inserir(rand() % 100, listaA);
        listaB = inserir(rand() % 100, listaB);
    }

    printf("***** Lista A *****\n");
    exibir(listaA);
    printf("***** Lista B *****\n");
    exibir(listaB);
    printf("***** Numeros presentes nas duas listas *****\n");
    exibirNumerosIguais(listaA, listaB);
    printf("***** Lista A sem numeros pares *****\n");
    deletarPares(listaA);
    exibir(listaA);
    printf("***** Uniao das duas listas *****\n");
    Celula *listaC = unirListas(listaA, listaB);
    exibir(listaC);
    printf("***** Ordenar a uniao *****\n");
    ordenar(listaC);
    exibir(listaC);
    printf("***** Apagar a lista *****\n");
    listaC = deletarLista(listaC);
    if(listaC == NULL){
        printf("Lista apagada com sucesso.");
    }
    return 0;
}
