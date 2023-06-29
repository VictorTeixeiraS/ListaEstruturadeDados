# Questão 1 - Calcular a altura de uma árvore binária (Arquivo: onetofour.cpp)

Este código em C++ implementa uma função para calcular a altura de uma árvore binária. A altura de uma árvore binária é definida como a maior distância entre a raiz da árvore e qualquer uma das suas folhas.

## Estrutura da Árvore Binária

A árvore binária é representada por uma estrutura de nó `Node`. Cada nó contém um campo `data` para armazenar o valor do nó e dois ponteiros `left` e `right` que apontam para os nós filhos esquerdo e direito, respectivamente. A estrutura do nó é definida da seguinte forma:

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};

```

## Função createNode
A função createNode é responsável por criar um novo nó da árvore com o valor especificado. Ela aloca memória para o novo nó, verifica se a alocação foi bem-sucedida e, em caso positivo, inicializa os campos data, left e right do nó. Em caso de falha na alocação de memória, a função exibe uma mensagem de erro e retorna nullptr. A assinatura da função é a seguinte:

```cpp
Node* createNode(int data);

```

## Função `height`
A função `height` é responsável por calcular a altura da árvore binária. Ela recebe como parâmetro o ponteiro para a raiz da árvore e retorna um inteiro representando a altura da árvore. A função utiliza a abordagem recursiva para calcular a altura. A altura de uma árvore é igual a 1 + a altura máxima entre a subárvore esquerda e a subárvore direita. A função `height` é implementada da seguinte forma:

```cpp
int height(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return std::max(leftHeight, rightHeight) + 1;
    }
}

```

# Questão 2 - Calcular a quantidade de nós de uma árvore binária (Arquivo: onetofour.cpp)

## Função `countNodes`
A função `countNodes` é responsável por contar a quantidade de nós em uma árvore binária. Ela recebe como parâmetro o ponteiro para a raiz da árvore e retorna um inteiro representando a quantidade de nós. A função utiliza a abordagem recursiva para percorrer a árvore e contar os nós. Se o nó atual for nulo (indicando uma folha da árvore), a função retorna 0. Caso contrário, a função retorna a quantidade total de nós na subárvore esquerda, mais a quantidade total de nós na subárvore direita, mais 1 para contar o próprio nó. A função `countNodes` é implementada da seguinte forma:

```cpp
int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}
    
```

# Questão 3 - Calcular a quantidade de folhas de uma árvore binária (Arquivo: onetofour.cpp)

## Função `countLeaves`

A função `countLeaves` é responsável por calcular o número de folhas em uma árvore binária. Ela recebe como parâmetro o ponteiro para a raiz da árvore e retorna um inteiro representando o número de folhas. A função utiliza a abordagem recursiva para percorrer a árvore e contar as folhas. A função `countLeaves` é implementada da seguinte forma:

```cpp
int countLeaves(Node* root) {
    if (root == nullptr) {
        return 0;
    } else if (root->left == nullptr && root->right == nullptr) {
        return 1;
    } else {
        return countLeaves(root->left) + countLeaves(root->right);
    }
}
        
```
A função `countLeaves` verifica se o nó atual é nulo. Se for nulo, isso significa que não há folhas e a função retorna 0. Caso contrário, a função verifica se o nó atual é uma folha, ou seja, não possui filhos esquerdo e direito. Se for uma folha, a função retorna 1. Caso contrário, a função recursivamente calcula o número de folhas na subárvore esquerda e na subárvore direita, somando os resultados.
 
# Questão 4 - Comparar Árvores Binárias (Arquivo: onetofour.cpp)



## Função `areTreesEqual`

A função `areTreesEqual` é responsável por comparar se duas árvores binárias são iguais. Ela recebe como parâmetros os ponteiros para as raízes das duas árvores e retorna um valor booleano: `true` se as árvores forem iguais e `false` caso contrário. A função utiliza uma abordagem recursiva para realizar a comparação.

A função `areTreesEqual` implementa os seguintes passos:

1. Verifica se ambas as árvores são nulas. Se forem, as árvores são consideradas iguais e a função retorna `true`.
2. Verifica se apenas uma das árvores é nula. Nesse caso, as árvores são consideradas diferentes e a função retorna `false`.
3. Verifica se os valores dos nós atuais nas duas árvores são diferentes. Se forem, as árvores são consideradas diferentes e a função retorna `false`.
4. Caso contrário, a função chama recursivamente a si mesma para comparar as subárvores esquerda e direita das duas árvores.

# Questão 5 - Percurso Pós-ordem de uma Árvore Binária (Arquivo: preAndPostOrder.cpp)

Este código em C++ implementa uma função que recebe os percursos pré-ordem e em-ordem de uma árvore binária T e retorna o percurso pós-ordem de T.

## Função `getPostorderTraversal`

A função `getPostorderTraversal` é responsável por construir a árvore binária a partir dos percursos pré-ordem e em-ordem e retornar o percurso pós-ordem. Ela recebe como parâmetros dois vetores `preorder` e `inorder` contendo os percursos pré-ordem e em-ordem, respectivamente, e retorna um vetor contendo o percurso pós-ordem.

A função `getPostorderTraversal` implementa os seguintes passos:

1. Cria um mapeamento dos valores e índices do percurso em-ordem usando um `std::unordered_map`.
2. Chama a função `buildTree` para construir a árvore binária a partir dos percursos pré-ordem e em-ordem, passando também o índice inicial e final dos percursos em-ordem.
3. Inicializa um vetor `postorder` vazio para armazenar o percurso pós-ordem.
4. Utiliza um percurso pós-ordem iterativo usando uma pilha para percorrer a árvore binária e adicionar os valores dos nós ao vetor `postorder`.
5. Retorna o vetor `postorder` contendo o percurso pós-ordem da árvore.

# Questão 6 - Pior caso para a altura de uma ABB (Arquivo: AABSorting.cpp)

## Pior Caso

O pior caso para a altura de uma ABB ocorre quando a árvore está desbalanceada, ou seja, quando ela é linear, com todos os nós em apenas um ramo. Essa situação é conhecida como uma Árvore Binária de Busca degenerada.

Em uma Árvore Binária de Busca degenerada, a altura da árvore é igual ao número de nós menos um. Isso significa que a altura cresce linearmente com o número de nós da árvore.

Um exemplo do pior caso é quando os elementos são inseridos em ordem crescente na ABB. A cada inserção, o novo elemento é adicionado como o filho direito do último nó inserido, resultando em uma árvore linear. Nesse caso, a altura da árvore é igual ao número de nós menos um, o que leva a uma complexidade de O(n) para as operações de busca, inserção e exclusão.


# Questão 7 - Ordenação por Árvore Binária de Busca (ABB)

## Algoritmo

O algoritmo de ordenação por ABB segue os seguintes passos:

1. Cria-se uma ABB vazia.
2. Insere-se os elementos da lista a ser ordenada na ABB. Para cada elemento, insere-o como uma nova folha na árvore, seguindo as regras de uma ABB.
3. Realiza-se um percurso em ordem (in-order traversal) na árvore. Isso visitará os nós em ordem crescente.
4. Durante o percurso em ordem, armazena-se os elementos visitados em uma nova lista, que será a lista ordenada.
5. Retorna-se a lista ordenada.


# Questão 8 - Inserção em Árvore AVL (Arquivo: AVLTree.cpp)


## Funcionamento do algoritmo

A função `insertNode` recebe a raiz da árvore e o valor do nó a ser inserido. O algoritmo segue os seguintes passos:

1. Verifica se a raiz é nula. Se for, cria um novo nó com o valor fornecido e retorna como a nova raiz.
2. Compara o valor do nó a ser inserido com o valor da raiz atual.
3. Se o valor for menor que o valor da raiz, chama recursivamente a função `insertNode` para a subárvore esquerda e atribui o retorno à subárvore esquerda da raiz atual.
4. Se o valor for maior que o valor da raiz, chama recursivamente a função `insertNode` para a subárvore direita e atribui o retorno à subárvore direita da raiz atual.
5. Se o valor for igual ao valor da raiz, exibe uma mensagem de erro informando que valores duplicados não são permitidos.
6. Após a inserção do novo nó, chama a função `calculateHeight` para atualizar a altura do nó atual e dos seus ancestrais.
7. Retorna a raiz atualizada.

# Questão 9 - Fator de Balanceamento em Árvore AVL 

Em uma árvore AVL, o fator de balanceamento é definido como a diferença entre as alturas das subárvores esquerda e direita de um nó. O fator de balanceamento deve estar dentro do intervalo [-1, 1] para que a árvore seja considerada balanceada. 

Desta forma, é impossível ter um fator de balanceamento igual a +3 em uma árvore AVL. Vamos justificar isso:

Para entender o motivo, vamos analisar como a árvore AVL é balanceada após uma inserção. Quando um novo nó é inserido em uma árvore AVL, são realizadas rotações e ajustes para manter o balanceamento. As rotações podem ocorrer em diferentes níveis da árvore, mas o fator de balanceamento de cada nó é sempre recalculado para garantir que esteja dentro do intervalo permitido.

Durante uma rotação, o fator de balanceamento de um nó pode mudar no máximo para 2. Por exemplo, se um nó tem um fator de balanceamento de -1 antes de uma rotação, após a rotação ele pode ter um fator de balanceamento de +1 ou 0.

Vamos considerar uma situação onde um nó tem um fator de balanceamento +2. Nesse caso, após uma rotação, esse nó pode ter um fator de balanceamento de +1 ou 0. Em nenhum caso o fator de balanceamento será +3.

Portanto, em uma árvore AVL corretamente implementada, não é possível ter um fator de balanceamento igual a +3.
