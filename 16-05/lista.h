#include<stdlib.h>

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

int conta(Celula *lista){
    int i = 0;
    for(Celula *p = lista; p!=NULL; p= p->prox){
        printf("%d\n",p->dado);
        i++;
    }
    return i;
}

void estaNaLista(Celula *lista, int n){
    for(Celula *p = lista; p!=NULL; p= p->prox){
        if(p->dado == n){
            printf("Sim o numero %d esta na lista\n", p->dado);
        }
    }
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

int estaOrdenadaOuNao(Celula *lista) {
    Celula *l = lista;
    while (l->prox != NULL) {
        if (l->dado > l->prox->dado) {
            return 0;
        }
        l = l->prox;
    }
    return 1;
}

int ocorrenciaDeNumero(Celula *lista, int n){
    int i = 0;
    for(Celula *p = lista; p!=NULL; p= p->prox){
        if(p->dado == n){
            i++;
        }
    }
    return i;
}

float media(Celula *lista){
    float total = 0.0;
    for(Celula *p = lista; p != NULL; p = p->prox){
        total += p->dado;
    }
    int quant = conta(lista);
    float media = total / quant;

    return media;
}
