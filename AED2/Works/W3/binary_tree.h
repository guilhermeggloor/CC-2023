#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Definição da struct para representar um nó no arquivo
struct s_arq_no
{
    int32_t chave:30;
    uint32_t esq:1;
    uint32_t dir:1;
};

// Definição da estrutura do nó da árvore
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

// Função para criar um novo nó
Node *createNode(int key);

// Função para inserir um nó na árvore
Node *insertNode(Node *root, int key);

// Função para buscar um nó com valor x na árvore
Node *search(Node *root, int x);

// Função para encontrar o nó com a menor chave na árvore
Node *findMin(Node *root);

// Função para encontrar o nó com a maior chave na árvore
Node *findMax(Node *root);

// Função para salvar a árvore em um arquivo
void saveTreeToFile(Node *root, FILE *file);

// Função para encontrar o nó com o maior valor menor que x
Node *findPredecessor(Node *root, int x);

// Função para encontrar o nó com o menor valor maior que x
Node *findSuccessor(Node *root, int x);

// Função auxiliar para encontrar o nó com a chave mínima na subárvore direita
Node *findMinKeyNode(Node *root);

// Função para remover um nó com valor x da árvore
Node *removeNode(Node *root, int x);



#endif
