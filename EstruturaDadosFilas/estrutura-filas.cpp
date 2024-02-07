#include <iostream>
#include <stdlib.h>
#include <string>
#include <locale.h>
#define TAM 10

using namespace std;

static void imprime_vetor(int vetor[TAM], int tamanho) {
	// Auxiliar contador
	int cont;

	cout << "\n";

	// Imprime o vetor
	for (cont = 0; cont < TAM; cont++) {
		cout << vetor[cont] << " - ";
	}
}

static void fila_construtor(int *frente, int *tras) {
	// Indica que não há ninguém na fila
	*frente = 0;
	// Indica que não há nenhum espaço entre eles dois
	*tras = -1;
}

static bool fila_vazia(int frente, int tras) {
	if (frente > tras) {
		return true;
	} else {
		return false;
	}
}

static bool fila_cheia(int tras) {
	if (tras == TAM - 1) {
		return true;
	} else {
		return false;
	}
}

static void fila_enfileirar(int fila[TAM], int valor, int *tras) {
	if (fila_cheia(*tras)) {
		cout << "Fila cheia";
	} else {
		*tras += 1;
		fila[*tras] = valor;
	}
}

static void fila_desenfileirar(int fila[TAM], int *frente, int tras) {
	if (fila_vazia(*frente, tras)) {
		cout << "Impossível desenfileirar uma lista vazia";
	} else {
		cout << "O valor " << fila[*frente] << " foi removido\n";
		fila[*frente] = 0;
		*frente += 1;
	}
}

static int fila_tamanho(int tras, int frente) {
	return (tras - frente) + 1;
}

int main() {
	setlocale(LC_ALL, "");

	int fila[TAM] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int frente, tras;
	int valor;

	fila_construtor(&frente, &tras);

	fila_enfileirar(fila, 5, &tras);
	fila_enfileirar(fila, 7 , &tras);

	fila_desenfileirar(fila, &frente, tras);
	fila_desenfileirar(fila, &frente, tras);
	fila_desenfileirar(fila, &frente, tras);

	fila_enfileirar(fila, 8, &tras);

	imprime_vetor(fila, fila_tamanho(tras, frente));

	return 0;
}