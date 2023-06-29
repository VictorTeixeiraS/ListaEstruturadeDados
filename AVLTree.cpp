#include <iostream>
#include <algorithm>

// Definição da estrutura de um nó da árvore AVL
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

// Função para criar um novo nó da árvore
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Erro ao alocar memória!" << std::endl;
        return nullptr;
    }

    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    newNode->height = 1; // Inicialmente, a altura de um nó é definida como 1
    return newNode;
}

// Função para obter a altura de um nó
int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Função para obter o fator de balanceamento de um nó
int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Função para calcular a altura de um nó
void calculateHeight(Node* node) {
    if (node == nullptr) {
        return;
    }
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

// Função para inserir um nó na árvore AVL

Node* insertNode(Node* root, int data) {
    // Passo 1: Inserção do nó na árvore (implementação básica sem balanceamento)
    if (root == nullptr) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    } else {
        // Nós com valores iguais não são permitidos na árvore AVL
        std::cout << "Valor duplicado. Não é possível inserir o nó." << std::endl;
        return root;
    }

    // Passo 2: Atualização da altura do nó atual
    calculateHeight(root);

    // Retorno do nó atualizado
    return root;
}

// Função para calcular o fator de balanceamento da raiz de uma árvore AVL
int calculateRootBalanceFactor(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return getBalanceFactor(root);
}
void displayTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";
    displayTree(root->left);
    displayTree(root->right);
}

int main() {
    // Exemplo de uso
    Node* root = nullptr;

    // Inserção dos nós na árvore AVL - Questão 10
    
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 6);
    root = insertNode(root, 7);


     std::cout << "Árvore AVL resultante: ";
    displayTree(root);
    std::cout << std::endl;

    int balanceFactor = calculateRootBalanceFactor(root);
    std::cout << "Fator de balanceamento da raiz: " << balanceFactor << std::endl;

    return 0;
}
