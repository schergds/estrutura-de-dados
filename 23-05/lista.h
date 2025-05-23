typedef struct no{
    int dado;
    struct no *prox;
} Lista;

Lista *inserir(int dado, Lista *lista){
    if (lista && dado >= lista->dado) {
        if(dado != lista->dado){
            lista->prox = inserir(dado, lista->prox);
        }
        return lista;
    } else {
        Lista *novo = (Lista*)malloc(sizeof(lista));
        novo->dado = dado;
        if(lista){
            novo->prox = lista;
        } else {
            novo->prox = NULL;
        }

        return novo;
    }
}

void exibir(Lista *lista){
    if(lista){
        cout << lista->dado << endl;
        exibir(lista->prox);
    }
}

int contar(Lista *lista){
    if(lista){
        return 1 + contar(lista->prox);
    }
    return 0;
}

void localizar(Lista *lista, int dado){
    if (lista) {
        if (dado == lista->dado) {
            cout << "O elemento " << lista->dado << " está na lista." << endl;
            return;
        }
        localizar(lista->prox, dado);
    }
    else {
        cout << "O elemento " << dado << " não está na lista." << endl;
        return;
    }
}