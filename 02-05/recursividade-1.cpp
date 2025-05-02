//exibir números entre 0 e um numero informado de forma recursiva

#include <iostream>
using namespace std;

void exibirCrescente(int i) {
    if (i >= 0) {
        //chamada recursiva com a transformação da variável de controle
        exibirCrescente(i - 1);
        //este código será executado na volta da recursão - desempilhamento
        cout << i << "\n";
    }
}

int main() {
    int numero;
    numero = 900;

    exibirCrescente(numero);


    return 1;
}