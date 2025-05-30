#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox;
}Celula;

Celula *inserir(int dado, Celula *lista){
    for(Celula *p = lista; p != NULL; p = p->prox){
        if(p->dado == dado){
            return lista;
        }
    }

    Celula *novo = (Celula*)malloc(sizeof(Celula));
    novo->dado = dado;
    novo->prox = NULL;

    if (!lista){
        return novo;
    }

    Celula *p;
    for(p = lista; p->prox != NULL; p = p->prox);

    p->prox = novo;
    return lista;
}

void exibir(Celula *lista){
    for(Celula *p = lista; p!=NULL; p= p->prox){
        printf("%d\n",p->dado);
    }
}

void exibirNumerosIguais(Celula *listaA, Celula *listaB){
    for(Celula *p1 = listaA; p1 != NULL; p1 = p1->prox){
        for(Celula *p2 = listaB; p2 != NULL; p2 = p2->prox){
            if(p1->dado == p2->dado){
                printf("%d\n", p1->dado);
            }
        }
    }
}

Celula *deletar(int dado, Celula *lista){
    Celula *p, *pR;
    for(p = lista, pR = NULL; p != NULL; pR = p, p = p->prox){
        if(dado == p->dado){
            if(p == lista){
                lista = lista->prox;
                free(p);
                return lista;
            }
            if(!p->prox){
                pR->prox = NULL;
                free(p);
                return lista;
            }
            pR->prox = p->prox;
            free(p);
            return lista;
        }
    }
    return lista;
}

void deletarPares(Celula *lista) {
    for(Celula *p = lista; p;) {
        if (p->dado % 2 == 0) {
            lista = deletar(p->dado, lista);
            p = lista;
        }
        else{
            p = p->prox;
        }
    }
}

Celula *deletarLista(Celula *lista){
    while(lista){
        Celula *temp = lista;
        lista = lista->prox;
        free(temp);
    }
    return NULL;
}

Celula *unirListas(Celula *listaA, Celula *listaB){
    Celula *listaC = NULL;
    for(Celula *p = listaA; p!=NULL; p= p->prox){
        int numero = p->dado;
        listaC = inserir(numero, listaC);
    }
    for(Celula *p = listaB; p!=NULL; p= p->prox){
        int numero = p->dado;
        listaC = inserir(numero, listaC);
    }
    return listaC;
}

Celula *ordenar(Celula *lista) {
    int testeParada;
    Celula *p;
    Celula *q;

    do {
        testeParada = 0;
        for (p = lista; p != NULL && p->prox != NULL; p = p->prox) {
            q = p->prox;
            if (p->dado > q->dado) {
                int temp = p->dado;
                p->dado = q->dado;
                q->dado = temp;
                testeParada = 1;
            }
        }
    } while (testeParada != 0);

    return lista;
}

