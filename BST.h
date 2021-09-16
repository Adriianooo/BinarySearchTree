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

BinarySearchTree* Create(); //Criar uma árvore

Node* NewNode(int value); //Criar um novo nó

Node* insert(BinarySearchTree* tree, Node* root, int value); //Inserir um novo nó na árvore
 
bool Search(Node* root, int data); //Verificar se o elemento do nó pertence a árvore

int Height(Node* root); //Verificar a altura do nó

void InOrder(Node* root); //Imprimir a lista

Node* Delete(Node* root, int data); //Deletar um nó da lista 







