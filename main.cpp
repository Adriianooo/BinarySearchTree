//Adriano Pinheiro Fernandes TIA: 32055161
//Lucas Andrew Lopes TIA: 32092245
#include "BST.h"
#include <string>
#include <iostream>
#include <locale.h>

using namespace std;
Node* menuInterativo(BinarySearchTree* tree, Node* root);

int main() {
	setlocale(LC_ALL, "PT-BR");
	BinarySearchTree* tree = Create();
	Node* root = NULL;
	root = menuInterativo(tree, root);
}

Node* menuInterativo(BinarySearchTree* tree, Node* root) {
	int resposta;
	cout << "Digite um número: \n1-Inserir um nó na árvore\n2-Imprimir a árvore\n3-Altura da árvore\n4-Remover um nó da árvore\n5-Pesquisar um nó na árvore \n6-Sair" << "\n";
	cin >> resposta;
	while (resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 5 && resposta && 6) {
		cout << "Número inválido." << "\n";
		cout << "Digite um número: \n1-Inserir um nó na árvore\n2-Imprimir a árvore\n3- Altura da árvore\n4-Remover um nó da árvore\n5-Pesquisar um nó na árvore \n6-Sair" << "\n";
		cin >> resposta;
	}
	if (resposta == 1) {
		int number;
		cout << "Digite o nó que deseja inserir na árvore: ";
		cin >> number;
		root = insert(tree, root, number);
		cout << "Nó inserido: " << number << "\n";
		root = menuInterativo(tree, root);
	}
	else if (resposta == 2) {
		cout << "Árvore em ordem: " << "\n";
		InOrder(root);
		root = menuInterativo(tree, root);
	}
	else if (resposta == 3) {
		cout << "Altura da árvore: " << Height(root) << "\n";
		root = menuInterativo(tree, root);
	}
	else if (resposta == 4) {
		int number;
		cout << "Digite o nó que deseja remover da árvore: ";
		cin >> number;
		while (Search(root, number) == false) {
			cout << "Nó não existente na árvore." << "\n";
			cout << "Digite o nó que deseja remover da árvore: ";
			cin >> number;
		}
		root = Delete(root, number);
		cout << "Árvore depois do nó ser removido: " << "\n";
		InOrder(root);
		root = menuInterativo(tree, root);
	}
	else if (resposta == 5) {
		int number;
		cout << "Digite o número que deseja pesquisar: ";
		cin >> number;

		if (Search(root, number) == true) {
			cout << "Número encontrado" << "\n";
			root = menuInterativo(tree, root);
		}
		else {
			cout << "Número não encontrado." << "\n";
			root = menuInterativo(tree, root);
		}
	}
	else {
		cout << "Programa encerrado.";
	}
	return root;
}