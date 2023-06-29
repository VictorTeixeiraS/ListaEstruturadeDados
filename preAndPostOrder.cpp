#include <iostream>
#include <vector>
#include <unordered_map>

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

// Função para construir a árvore binária a partir dos percursos pré-ordem e em-ordem
Node* buildTree(std::vector<int>& preorder, std::vector<int>& inorder, int& preorderIndex, int inorderStart, int inorderEnd, std::unordered_map<int, int>& inorderMap) {
    if (inorderStart > inorderEnd) {
        return nullptr;
    }

    int rootData = preorder[preorderIndex];
    Node* root = createNode(rootData);
    preorderIndex++;

    if (inorderStart == inorderEnd) {
        return root;
    }

    int inorderIndex = inorderMap[rootData];

    root->left = buildTree(preorder, inorder, preorderIndex, inorderStart, inorderIndex - 1, inorderMap);
    root->right = buildTree(preorder, inorder, preorderIndex, inorderIndex + 1, inorderEnd, inorderMap);

    return root;
}

// Função para construir a árvore binária a partir dos percursos pré-ordem e em-ordem e retornar o percurso pós-ordem
std::vector<int> getPostorderTraversal(std::vector<int>& preorder, std::vector<int>& inorder) {
    std::unordered_map<int, int> inorderMap;
    int n = inorder.size();

    // Mapeamento dos valores e índices do percurso em-ordem
    for (int i = 0; i < n; i++) {
        inorderMap[inorder[i]] = i;
    }

    int preorderIndex = 0;
    Node* root = buildTree(preorder, inorder, preorderIndex, 0, n - 1, inorderMap);

    std::vector<int> postorder;
    std::vector<Node*> stack;
    Node* curr = root;
    Node* lastVisited = nullptr;

    while (curr || !stack.empty()) {
        if (curr) {
            stack.push_back(curr);
            curr = curr->left;
        } else {
            Node* topNode = stack.back();

            if (topNode->right && topNode->right != lastVisited) {
                curr = topNode->right;
            } else {
                stack.pop_back();
                postorder.push_back(topNode->data);
                lastVisited = topNode;
            }
        }
    }

    return postorder;
}

int main() {
    // Exemplo de uso
    std::vector<int> preorder = {1, 2, 4, 5, 3, 6};
    std::vector<int> inorder = {4, 2, 5, 1, 6, 3};

    std::vector<int> postorder = getPostorderTraversal(preorder, inorder);

    std::cout << "Percurso pós-ordem: ";
    for (int data : postorder) {
        std::cout << data << " ";
    }
    std::cout << std::endl;

    return 0;
}
