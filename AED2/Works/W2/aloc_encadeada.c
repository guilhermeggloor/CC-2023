// Aluno: Guilherme Garcia Gloor
// RGM: 45535

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;         // ID do bloco
    int start;      // Endereço inicial do bloco
    int end;        // Endereço final do bloco
} Block;

typedef struct Node {
    Block block;            // Bloco disponível
    struct Node* next;      // Próximo nó na lista
} Node;

Block* BlocosAlocados;     // Array de blocos alocados
int contarAlocados = 0;     // Quantidade de blocos alocados
int allocatedCapacity = 0;  // Capacidade máxima de blocos alocados
int M = 0;                 // Capacidade de armazenamento da memória em bytes
int idBlocos = 1;     // Contador de ID de blocos
Node* availableBlocks;      // Lista de blocos disponíveis

Node* createNode(int start, int size) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->block.start = start;
    newNode->block.end = start + size - 1;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int start, int size) {
    Node* newNode = createNode(start, size);

    if (*head == NULL || start < (*head)->block.start) {
        // Inserir no início da lista se a lista está vazia ou se o início é menor do que o primeiro bloco
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;

        while (current->next != NULL && start > current->next->block.start) {
            current = current->next;
        }

        // Inserir após o nó atual
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteNode(Node** head, int start) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL && current->block.start != start) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            // Remover o nó no início da lista
            *head = current->next;
        } else {
            prev->next = current->next;
        }

        free(current);
    }
}

void fundirBlocos(Node* head) {
    Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->block.end + 1 == current->next->block.start) {
            // Blocos adjacentes, combinar em um único bloco
            current->block.end = current->next->block.end;
            Node* next = current->next;
            current->next = next->next;
            free(next);
        } else {
            current = current->next;
        }
    }
}

// função do mapa de memória
void mapaMemoria() {
    printf("\nMapa de Memória:\n");

    for (int i = 0; i < contarAlocados; i++) {
        Block block = BlocosAlocados[i];
        printf("Bloco Alocado - ID: %d, Endereço Inicial: %d, Endereço Final: %d\n", block.id, block.start, block.end);
    }

    Node* current = availableBlocks;

    while (current != NULL) {
        Block block = current->block;
        printf("Bloco Disponível - Endereço Inicial: %d, Tamanho: %d bytes\n", block.start, block.end - block.start + 1);
        current = current->next;
    }
}


// função para mostrar a porcentagem de memória
void porcentagemMemoria() {
    int allocatedSize = 0;

    for (int i = 0; i < contarAlocados; i++) {
        allocatedSize += BlocosAlocados[i].end - BlocosAlocados[i].start + 1;
    }

    float percentage = (float)allocatedSize / M * 100;
    printf("\nPorcentagem de Memória Alocada: %.2f%%\n", percentage);
}

void allocateBlock(int size) {
    Node* current = availableBlocks;
    Node* prev = NULL;
    Node* bestFit = NULL;
    int bestFitSize = M + 1;

    while (current != NULL) {
        int blockSize = current->block.end - current->block.start + 1;

        if (blockSize >= size && blockSize < bestFitSize) {
            bestFit = current;
            bestFitSize = blockSize;
        }

        prev = current;
        current = current->next;
    }

    if (bestFit == NULL) {
        printf("Não foi possível alocar um bloco de tamanho %d.\n", size);
        return;
    }

    int start = bestFit->block.start;
    int end = start + size - 1;

    if (bestFit->block.start == start && bestFit->block.end == end) {
        // O bloco disponível tem exatamente o tamanho necessário, remover da lista
        if (prev == NULL) {
            availableBlocks = bestFit->next;
        } else {
            prev->next = bestFit->next;
        }
        free(bestFit);
    } else if (bestFit->block.start == start) {
        // Reduzir o tamanho do bloco disponível no início
        bestFit->block.start += size;
    } else if (bestFit->block.end == end) {
        // Reduzir o tamanho do bloco disponível no final
        bestFit->block.end -= size;
    } else {
        // Dividir o bloco disponível em dois
        Node* newNode = createNode(end + 1, bestFit->block.end - end);
        newNode->next = bestFit->next;
        bestFit->next = newNode;
        bestFit->block.end = start - 1;
    }

    Block newBlock = { idBlocos, start, end };
    BlocosAlocados[contarAlocados] = newBlock;
    contarAlocados++;
    idBlocos++;

    printf("Bloco alocado com sucesso. ID: %d, Endereço Inicial: %d, Endereço Final: %d\n", newBlock.id, newBlock.start, newBlock.end);
}

void desalocarBlocos(int id) {
    int index = -1;

    for (int i = 0; i < contarAlocados; i++) {
        if (BlocosAlocados[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Não foi encontrado um bloco com ID %d.\n", id);
        return;
    }

    int start = BlocosAlocados[index].start;
    int end = BlocosAlocados[index].end;

    // Remover o bloco da lista de blocos alocados
    for (int i = index; i < contarAlocados - 1; i++) {
        BlocosAlocados[i] = BlocosAlocados[i + 1];
    }
    contarAlocados--;

    // Inserir um novo bloco disponível
    insertNode(&availableBlocks, start, end - start + 1);

    fundirBlocos(availableBlocks);

    printf("Bloco com ID %d desalocado com sucesso.\n", id);
}

// liberar memória
void liberarMemoria() {
    Node* current = availableBlocks;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(BlocosAlocados);
}

int main() {
    printf("Digite a capacidade de armazenamento da memória em bytes (M): ");
    scanf("%d", &M);

    BlocosAlocados = (Block*)malloc(M * sizeof(Block));

    int capacity;
    printf("Digite a capacidade máxima de blocos alocados: ");
    scanf("%d", &capacity);

    availableBlocks = createNode(0, M);

    int choice = 0;
    int size;
    int id;

    // entrada de dados para selecionar entre alocar, desalocar, visualizar o mapa de memória e apresentar porcentagem
    while (choice != 5) {
        printf("\n===== MENU =====\n");
        printf("1. Alocar bloco\n");
        printf("2. Desalocar bloco\n");
        printf("3. Visualizar mapa de memória\n");
        printf("4. Apresentar porcentagem de memória alocada\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nDigite o tamanho do bloco que deseja alocar: ");
                scanf("%d", &size);
                allocateBlock(size);
                break;
            case 2:
                printf("\nDigite o ID do bloco que deseja desalocar: ");
                scanf("%d", &id);
                desalocarBlocos(id);
                break;
            case 3:
                mapaMemoria();
                break;
            case 4:
                porcentagemMemoria();
                break;
            case 5:
                break;
            default:
                printf("\nOpção inválida. Digite novamente.\n");
                break;
        }
    }

    liberarMemoria();

    return 0;
}
