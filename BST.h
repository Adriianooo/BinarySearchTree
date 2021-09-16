#include <string>

struct Node {
	int data;
	Node* left;
	Node* right;
};

struct BinarySearchTree {
	int count;
	Node* root;
};

BinarySearchTree* Create(); //Criar uma �rvore

Node* NewNode(int value); //Criar um novo n�

Node* insert(BinarySearchTree* tree, Node* root, int value); //Inserir um novo n� na �rvore
 
bool Search(Node* root, int data); //Verificar se o elemento do n� pertence a �rvore

int Height(Node* root); //Verificar a altura do n�

void InOrder(Node* root); //Imprimir a lista

Node* Delete(Node* root, int data); //Deletar um n� da lista 







