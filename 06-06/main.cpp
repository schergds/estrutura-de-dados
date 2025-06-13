#include <iostream>
#include <cstdlib>
#include "arvore.h"

using namespace std;

int main() {
    Arvore *arvore = NULL;
    arvore = inserir(50, arvore);
    arvore = inserir(35, arvore);
    arvore = inserir(40, arvore);
    arvore = inserir(60, arvore);

    cout << "Total de elementos: " << contar(arvore) << endl;
    cout << "Elementos ordenados: ";
    exibirOrdenado(arvore);
    cout << endl;

    cout << "Soma dos elementos: " << somar(arvore) << endl;
    cout << "Total de números pares: " << contarPares(arvore) << endl;
    cout << "Total de folhas: " << contarFolhas(arvore) << endl;
    cout << "Folhas: ";
    exibirFolhas(arvore);
    cout << endl;

    return 0;
}