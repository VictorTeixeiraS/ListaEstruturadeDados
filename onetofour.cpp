#include <iostream>
#include <algorithm>

// Definição da estrutura de um nó da árvore binária
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Função auxiliar para criar um novo nó
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

// Função para calcular a altura da árvore binária
int getHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return std::max(leftHeight, rightHeight) + 1;
}

// Função para contar o número de nós
int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

// Função para calcular o número de folhas na árvore binária
int countLeaves(Node* root) {
    if (root == nullptr) {
        return 0;
    } else if (root->left == nullptr && root->right == nullptr) {
        return 1;
    } else {
        return countLeaves(root->left) + countLeaves(root->right);
    }
}

// Função para comparar duas árvores binárias
bool areTreesEqual(Node* root, Node* root2) {
    // Se ambas as árvores são nulas, são iguais
    if (root == nullptr && root2 == nullptr) {
        return true;
    }

    // Se apenas uma árvore é nula, elas não são iguais
    if (root == nullptr || root2 == nullptr) {
        return false;
    }

    // Verifica se o valor dos nós é igual
    if (root->data != root2->data) {
        return false;
        }

    // Compara as subárvores recursivamente
    return areTreesEqual(root->left, root2->left) && areTreesEqual(root->right, root2->right);
}

int main() {
    // Exemplo de uso
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);

    std::cout << "A altura da árvore é: " << getHeight(root) << std::endl;

    int numNodes = countNodes(root);
    std::cout << "Quantidade de nós da árvore: " << numNodes << std::endl;

    int numLeaves = countLeaves(root);
    std::cout << "Número de folhas na árvore: " << numLeaves << std::endl;

    bool equalTrees = areTreesEqual(root, root2);
    std::cout << "As árvores são iguais? " << (equalTrees ? "Sim" : "Não") << std::endl;


    // Liberando memória
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
