#include <iostream>

using namespace std;

bool primo(int n) {
	if (n <= 1) return false;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void mostrarPrimos(int n){
	if(n > 0){
		mostrarPrimos(n - 1);

		if(primo(n)){
			cout << n << " é primo.\n";
		}
		else {
			cout << n << " não é primo.\n";
		}
	}
}

int contarPrimos(int n){
	if(n > 0){
		if(primo(n)){
			return 1 + contarPrimos(n - 1);
		}
		else {
			return 0 + contarPrimos(n - 1);
		}
	}
	return 0;
}

int main(){
	int numero;
	cout << "Digite um número inteiro: " << endl;
	cin >> numero;
	mostrarPrimos(numero);
	cout << "Quantidade de números primos no intervalo 1 - " << numero << ": " << contarPrimos(numero) << endl;
}