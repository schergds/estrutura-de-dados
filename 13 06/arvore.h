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
        std::cout << raiz->dado << "\t";
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
        std::cout << raiz->dado << "\t";
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

void exibirArvore(int nivel, Arvore *raiz){
    if(raiz){
        exibirArvore(nivel + 1, raiz->dir);

        for(int i = 0; i < nivel; i++){
            std::cout << " ";
        }
        std::cout << "(" << nivel << ")" << raiz->dado << std::endl;

        exibirArvore(nivel + 1, raiz->esq);
    }
}

int localizarNivel(int dado, Arvore *raiz){
    if(raiz){
        if(dado == raiz->dado){
            return 0;
        }
        if(dado < raiz->dado){
            int respostaEmpilhamento = localizarNivel(dado, raiz->esq);
            if(respostaEmpilhamento == -1){
                return -1;
            }
            return 1 + respostaEmpilhamento;
        }
        else{
            int respostaEmpilhamento = localizarNivel(dado, raiz->dir);
            if(respostaEmpilhamento == -1){
                return -1;
            }
            return 1 + respostaEmpilhamento;
        }
    }
    return -1;
}

Arvore *podar(Arvore *raiz){
    if(raiz){
        if(!raiz->esq && !raiz->dir){
            free(raiz);
            return NULL;
        }
        raiz->esq = podar(raiz->esq);
        raiz->dir = podar(raiz->dir);
        return raiz;
    }
    return NULL;
}

Arvore *limpar(Arvore *raiz){
    if(raiz){
        raiz->esq = limpar(raiz->esq);
        raiz->dir = limpar(raiz->dir);
        free(raiz);
    }
    return NULL;
}

Arvore *remover(int dado, Arvore *raiz) {
    if (raiz) {
        if (dado == raiz->dado) {//localizei o dado e remover
            //verificar se eh folha
            if (!raiz->esq && !raiz->dir) {
                free(raiz);
                return NULL;
            }
            //verificar se ha um filho somente
            if ((raiz->esq && !raiz->dir) || (raiz->dir && !raiz->esq)) {
                Arvore *tmp;
                if (raiz->esq) {
                    tmp = raiz->esq;    
                }
                if (raiz->dir) {
                    tmp = raiz->dir;    
                }
                free(raiz);
                return tmp;
            }
            //se estou neste ponto eh porque o nodo tem dois filhos e o filho da esquerda serah o novo pai
            Arvore *novoPai = raiz->esq;
            Arvore *tmp = novoPai->dir;
            novoPai->dir = raiz->dir;
            free(raiz);
 
            Arvore *p;
            for (p = novoPai->dir; p->esq; p = p->esq);
           
            p->esq = tmp;
            return novoPai;
        }
        if (dado < raiz->dado) {
            raiz->esq = remover(dado, raiz->esq);
        } else {
            raiz->dir = remover(dado, raiz->dir);
        }
        return raiz;
    }
    return NULL;
}