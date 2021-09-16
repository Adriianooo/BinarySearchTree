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
	cout << "Digite um n�mero: \n1-Inserir um n� na �rvore\n2-Imprimir a �rvore\n3-Altura da �rvore\n4-Remover um n� da �rvore\n5-Pesquisar um n� na �rvore \n6-Sair" << "\n";
	cin >> resposta;
	while (resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 5 && resposta && 6) {
		cout << "N�mero inv�lido." << "\n";
		cout << "Digite um n�mero: \n1-Inserir um n� na �rvore\n2-Imprimir a �rvore\n3- Altura da �rvore\n4-Remover um n� da �rvore\n5-Pesquisar um n� na �rvore \n6-Sair" << "\n";
		cin >> resposta;
	}
	if (resposta == 1) {
		int number;
		cout << "Digite o n� que deseja inserir na �rvore: ";
		cin >> number;
		root = insert(tree, root, number);
		cout << "N� inserido: " << number << "\n";
		root = menuInterativo(tree, root);
	}
	else if (resposta == 2) {
		cout << "�rvore em ordem: " << "\n";
		InOrder(root);
		root = menuInterativo(tree, root);
	}
	else if (resposta == 3) {
		cout << "Altura da �rvore: " << Height(root) << "\n";
		root = menuInterativo(tree, root);
	}
	else if (resposta == 4) {
		int number;
		cout << "Digite o n� que deseja remover da �rvore: ";
		cin >> number;
		while (Search(root, number) == false) {
			cout << "N� n�o existente na �rvore." << "\n";
			cout << "Digite o n� que deseja remover da �rvore: ";
			cin >> number;
		}
		root = Delete(root, number);
		cout << "�rvore depois do n� ser removido: " << "\n";
		InOrder(root);
		root = menuInterativo(tree, root);
	}
	else if (resposta == 5) {
		int number;
		cout << "Digite o n�mero que deseja pesquisar: ";
		cin >> number;

		if (Search(root, number) == true) {
			cout << "N�mero encontrado" << "\n";
			root = menuInterativo(tree, root);
		}
		else {
			cout << "N�mero n�o encontrado." << "\n";
			root = menuInterativo(tree, root);
		}
	}
	else {
		cout << "Programa encerrado.";
	}
	return root;
}