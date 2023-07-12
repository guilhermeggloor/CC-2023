// Aluno: Guilherme Garcia Gloor 
// RGM: 45535
// Aviso: tentei o implementar completamente mas parece que o código ainda ficou incompleto :P 

#include <stdio.h>
#include "binary_tree.h"
#include "gfx.h"

// Função para criar um novo nó
Node *createNode(int key) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int getWidth(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int leftWidth = getWidth(root->left);
    int rightWidth = getWidth(root->right);
    return leftWidth + rightWidth + 1;
}

int countNodes(Node *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}


// Função para exibir a arvore binaria utilizando a gfx
void displayTree(Node *root, int x, int y) {
    if (root == NULL) {
        return;
    }

    int nodeSize = 30;

    // Calcula o espaçamento horizontal com base no número de nós na subárvore esquerda e direita
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    int horizontalSpacing = (leftCount + rightCount) * 30;

    // Exibe o nó atual
    gfx_set_color(128, 0, 128);
    gfx_filled_rectangle(x, y, x + nodeSize, y + nodeSize);
    char label[10];
    snprintf(label, sizeof(label), "%d", root->key);
    int textWidth, textHeight;
    gfx_get_text_size(label, &textWidth, &textHeight);
    gfx_set_color(255, 255, 255);
    gfx_text(x + (nodeSize / 2) - (textWidth / 2), y + (nodeSize / 2) - (textHeight / 2), label);

    // Exibe as conexões com os filhos
    int childY = y + 2 * nodeSize;

    if (root->left != NULL) {
        int leftChildSpacing = -horizontalSpacing / 2;
        gfx_line(x + (nodeSize / 2), y + nodeSize, x + leftChildSpacing + (nodeSize / 2), childY);
        displayTree(root->left, x + leftChildSpacing, childY);
    }

    if (root->right != NULL) {
        int rightChildSpacing = horizontalSpacing / 2;
        gfx_line(x + (nodeSize / 2), y + nodeSize, x + rightChildSpacing + (nodeSize / 2), childY);
        displayTree(root->right, x + rightChildSpacing, childY);
    }
}


// Função para inserir um nó na árvore
Node *insertNode(Node *root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }

    gfx_clear();
    displayTree(root, 400, 30);
    gfx_paint();

    return root;
}

// Função para encontrar o nó com a menor chave na árvore
Node *findMin(Node *root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

// Função para encontrar o nó com a maior chave na árvore
Node *findMax(Node *root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root;
}

void saveTreeToFile(Node *root, FILE *file) {
    if (root != NULL) {
        struct s_arq_no node;
        node.chave = root->key;
        node.esq = (root->left != NULL);
        node.dir = (root->right != NULL);
        fwrite(&node, sizeof(struct s_arq_no), 1, file);
        saveTreeToFile(root->left, file);
        saveTreeToFile(root->right, file);
    }
}

Node *search(Node *root, int x) {
    if (root == NULL || root->key == x) {
        return root;
    }

    if (x < root->key) {
        return search(root->left, x);
    } else {
        return search(root->right, x);
    }
}

// Função para encontrar o nó com o maior valor menor que x
Node *findPredecessor(Node *root, int x) {
    Node *predecessor = NULL;

    while (root != NULL) {
        if (root->key < x) {
            predecessor = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return predecessor;
}

// Função para encontrar o nó com o menor valor maior que x
Node *findSuccessor(Node *root, int x) {
    Node *successor = NULL;

    while (root != NULL) {
        if (root->key > x) {
            successor = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return successor;
}

Node *findMinKeyNode(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node *removeNode(Node *root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = removeNode(root->left, key);
    } else if (key > root->key) {
        root->right = removeNode(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *minKeyNode = findMinKeyNode(root->right);
        root->key = minKeyNode->key;
        root->right = removeNode(root->right, minKeyNode->key);
    }

    gfx_clear();
    displayTree(root, 400, 30);
    gfx_paint();

    return root;
}

// Função principal com entrada de dados e opções de escolha no terminal
int main() {
    gfx_init(1024, 768, "W3 AED2");

    Node *root = NULL;

    int choice, key, x;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Inserir um valor\n");
        printf("2. Remover um valor\n");
        printf("3. Buscar a maior chave\n");
        printf("4. Buscar a menor chave\n");
        printf("5. Buscar o predecessor de uma chave\n");
        printf("6. Buscar o sucessor de uma chave\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

         switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &key);
                root = insertNode(root, key);
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &key);
                root = removeNode(root, key);
                break;
            case 3:
                if (root == NULL) {
                    printf("A árvore está vazia.\n");
                } else {
                    Node *maxNode = findMax(root);
                    printf("Maior chave: %d\n", maxNode->key);
                }
                break;
            case 4:
                if (root == NULL) {
                    printf("A árvore está vazia.\n");
                } else {
                    Node *minNode = findMin(root);
                    printf("Menor chave: %d\n", minNode->key);
                }
                break;
            case 5:
                printf("Digite o valor da chave: ");
                scanf("%d", &x);
                Node *predecessor = findPredecessor(root, x);
                if (predecessor != NULL) {
                    printf("Predecessor de %d: %d\n", x, predecessor->key);
                } else {
                    printf("Não há predecessor de %d.\n", x);
                }
                break;
            case 6:
                printf("Digite o valor da chave: ");
                scanf("%d", &x);
                Node *successor = findSuccessor(root, x);
                if (successor != NULL) {
                    printf("Sucessor de %d: %d\n", x, successor->key);
                } else {
                    printf("Não há sucessor de %d.\n", x);
                }
                break;
            case 7:
                printf("Encerrando...\n");
                break;
            default: 
                printf("Opção inválida!\n");
                break;                
            }

        displayTree(root, 400, 30);
        gfx_paint();
            
    }while(choice != 7);
                

    // Encontrar a menor chave
    Node *minNode = findMin(root);
    if (minNode != NULL) {
        printf("Menor chave: %d\n", minNode->key);
    } else {
        printf("A árvore está vazia.\n");
    }

    // Encontrar a maior chave
    Node *maxNode = findMax(root);
    if (maxNode != NULL) {
        printf("Maior chave: %d\n", maxNode->key);
    } else {
        printf("A árvore está vazia.\n");
    }

    // Salvar a árvore em um arquivo
    FILE *file = fopen("arvore.bin", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    saveTreeToFile(root, file);
    fclose(file);

    return 0;

    return 0;
}
