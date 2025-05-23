#include <iostream>
using namespace std;

#include "lista.h";

int main(){
    Lista *lista = NULL;
    srand(time(NULL));
    for(int i = 0; i < 50; i++){
        lista = inserir(rand() % 100, lista);
    }
    exibir(lista);
    int i = contar(lista);
    cout << "Quantidade de itens na lista: " << i << endl;
    localizar(lista, 1);
    return 1;
}