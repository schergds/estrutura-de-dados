typedef struct no{
    int dado;
    struct no *esq;
    struct no *dir;
}Arvore;

Arvore *inserir(int n, Arvore *raiz){
    if(raiz){
        if(n < raiz->dado){
            raiz->esq = inserir(n, raiz->esq);
        
        }
        else{
            raiz->dir = inserir(n, raiz->dir);
        }
        return raiz;
    }
    else{
        Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
        novo->dado = n;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
}

void exibirOrdenado(Arvore *raiz){
    if(raiz){
        exibirOrdenado(raiz->esq);
        cout << raiz->dado << "\t";
        exibirOrdenado(raiz->dir);
    }
}

int contar(Arvore *raiz){
    if(raiz){
        return contar(raiz->esq) + contar(raiz->dir) + 1;
    }
    return 0;
}

int somar(Arvore *raiz){
    if(raiz){
        return raiz->dado + somar(raiz->esq) + somar(raiz->dir);
    }
    return 0;
}

int contarPares(Arvore *raiz){
    if(raiz){
        if(raiz->dado % 2 == 0){
            return 1 + contarPares(raiz->esq) + contarPares(raiz->dir);
        }
        else{
            return 0 + contarPares(raiz->esq) + contarPares(raiz->dir);
        }
    }
    return 0;
}

int contarFolhas(Arvore *raiz){
    if(!raiz){
        return 0;
    }
    if(!raiz->esq && !raiz->dir){
        return 1;
    }
    return 0 + contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
}

void exibirFolhas(Arvore *raiz){
    if(!raiz){
        return;
    }
    if(!raiz->esq && !raiz->dir){
        cout << raiz->dado << "\t";
        return;
    }
    exibirFolhas(raiz->esq);
    exibirFolhas(raiz->dir);
}

bool localizar(int valor, Arvore *raiz){
    if(raiz){
        if(raiz->dado == valor){
            return true;
        }
        if(valor < raiz->dado){
            return localizar(valor, raiz->esq);
        }
        else{
            return localizar(valor, raiz->dir);
        }
    }
    return false;
}