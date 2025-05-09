#include <iostream>
#include <ctime>
#include <cstdlib>

#define TAM 10

using namespace std;

/*
Recursão -> técnica de repetição por empilhamento de processo -> o mesmo processo se chamando várias vezes
	- entender o que compõe uma repetição
		for(inicialização da variável de controle; teste de parada com a variável de controle; transformação da variável de controle)

a - inicialização da variável de controle
b - condição de parada/continuidade
c - transformação da variável de controle -> ponto de recursão
*/

void popularR(int vetor[], int n){
	if(n > 0){
		//Código antes da recursão, ou seja, no empilhamento
		vetor[n - 1] = rand() % 20;

		//Ponto de recursão - transformação da variável de controle
		popularR(vetor, n - 1);

		//Código depois da recursão, ou seja, no desempilhamento
	}
}

void exibirR(int vetor[], int n){
	if(n > 0){
		exibirR(vetor, n - 1);
		cout << vetor[n - 1] << "\n";
	}
}

int somarR(int vetor[], int n){
	if(n > 0){
		return vetor[n - 1] + somarR(vetor, n - 1);
	}
	return 0;
}

int contarElementos(int vetor[], int n){
	if(n > 0){
		return 1 + contarElementos(vetor, n - 1);
	}
	return 0;
}

int contarParesR(int vetor[], int n){
	if(n > 0){
		if(vetor[n - 1] % 2 == 0){
			return 1 + contarParesR(vetor, n - 1);
		}
		else {
			return 0 + contarParesR(vetor, n - 1);
		}
	}
	return 0;
}

int menorR(int vetor[], int n){
	if(n > 1){
		int cima = menorR(vetor, n - 1);
		if(cima < vetor[n - 1]){
			return cima;
		}
		else{
			return vetor[n - 1];
		}
	}
	return vetor[n - 1];
}

int main(){
	srand(time(NULL));
	int vetor[TAM];
	popularR(vetor, TAM);
	exibirR(vetor, TAM);
	cout << "A soma dos elementos: " << somarR(vetor, TAM) << endl;
	cout << "Quantidade de números pares: " << contarParesR(vetor, TAM) << endl;
	cout << "Menor número do vetor: " << menorR(vetor, TAM) << endl;
	cout << "Quantidade de elementos dentro do vetor: " << contarElementos(vetor, TAM) << endl;
}