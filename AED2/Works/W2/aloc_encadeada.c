#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    int size;
    struct Node* next;
} Node;

Node* createNode(int size, int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

void insertBlock(Node** head, int size, int* idCounter, int maxSize) {
    int allocatedSize = 0;
    Node* currentNode = *head;
    while (currentNode != NULL) {
        allocatedSize += currentNode->size;
        currentNode = currentNode->next;
    }
    if (allocatedSize + size > maxSize) {
        printf("Tamanho máximo de memória excedido. Impossível alocar.\n");
        return;
    }

    Node* newNode = createNode(size, (*idCounter)++);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Bloco de tamanho %d alocado com sucesso! ID gerado: %d\n", size, newNode->id);
}

void deallocateBlock(Node** head, int id) {
    if (*head == NULL) {
        printf("Lista vazia. Impossível desalocar.\n");
        return;
    }

    Node* currentNode = *head;
    Node* prevNode = NULL;

    while (currentNode != NULL) {
        if (currentNode->id == id) {
            if (prevNode == NULL) {
                *head = currentNode->next;
            } else {
                prevNode->next = currentNode->next;
            }
            free(currentNode);
            printf("Bloco ID %d desalocado com sucesso!\n", id);
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    printf("Bloco ID %d não encontrado na lista.\n", id);
}

void printBlocks(Node* head) {
    if (head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Blocos alocados:\n");
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("ID: %d\n", currentNode->id);
        printf("Tamanho: %d\n", currentNode->size);
        printf("Endereço inicial: 0\n");
        printf("Endereço final: %d\n", currentNode->size - 1);
        printf("\n");
        currentNode = currentNode->next;
    }
}

void freeList(Node** head) {
    Node* currentNode = *head;
    Node* nextNode = NULL;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    *head = NULL;
    printf("Memória liberada.\n");
}

int main() {
    Node* head = NULL;
    int idCounter = 1, size, choice;
    int maxSize;

    printf("Digite o tamanho máximo de memória: ");
    scanf("%d", &maxSize);

    while (1) {
        printf("\n1. Alocar bloco de memória\n");
        printf("2. Desalocar bloco de memória\n");
        printf("3. Imprimir blocos alocados\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o tamanho do bloco de memória a ser alocado: ");
                scanf("%d", &size);
                insertBlock(&head, size, &idCounter, maxSize);
                break;
            case 2:
                printf("Digite o ID do bloco de memória a ser desalocado: ");
                scanf("%d", &size);
                deallocateBlock(&head, size);
                break;
            case 3:
                printBlocks(head);
                break;
            case 4:
                freeList(&head);
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
