#include <iostream>
#include <vector>

// Definição da estrutura de um nó da árvore binária
struct Node {
    int data;
    Node* left;
    Node* right;
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
    return newNode;
}

// Função para inserir um nó na árvore binária de busca
Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Função de percurso em ordem (in-order traversal) para obter os elementos em ordem crescente
void inOrderTraversal(Node* root, std::vector<int>& sortedList) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left, sortedList);
    sortedList.push_back(root->data);
    inOrderTraversal(root->right, sortedList);
}

// Função de ordenação por ABB
std::vector<int> abbSort(std::vector<int>& list) {
    Node* root = nullptr;

    // Inserção dos elementos da lista na ABB
    for (int data : list) {
        root = insertNode(root, data);
    }

    // Realização do percurso em ordem para obter os elementos ordenados
    std::vector<int> sortedList;
    inOrderTraversal(root, sortedList);

    return sortedList;
}

int main() {
    // Exemplo de uso
    std::vector<int> list = {4, 2, 6, 1, 3, 5};
    std::vector<int> sortedList = abbSort(list);

    std::cout << "Lista Ordenada: ";
    for (int data : sortedList) {
        std::cout << data << " ";
    }
    std::cout << std::endl;

    return 0;
}
