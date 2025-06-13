#include <iostream>
#include <cstdlib>
#include <ctime>
#include "arvore.h"
using namespace std;

int main(){
    srand(time(NULL));
    Arvore *arvore = NULL;
    int qtd = 10;
    int numero;

    for(;qtd > 0; qtd--){
        numero = rand() % 10000;
        cout << "Número gerado: " << numero << endl;
        arvore = inserir(numero, arvore);
    }
    exibirArvore(0, arvore);
    cout << "Digite um número para remover: ";
    int x;
    cin >> x;
    remover(x, arvore);
    exibirArvore(0, arvore); 
}