#include <iostream>

// Classe que representa um nó na lista
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T value) : data(value), next(nullptr) {}
};

// Classe que representa a lista simplesmente encadeada
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Insere um elemento no início da lista
    void insertAtFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Insere um elemento no final da lista
    void insertAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Remove o elemento do início da lista
    void removeFromFront() {
        if (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Remove o elemento do final da lista
    void removeFromEnd() {
        if (!head) {
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T>* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
    }

    // Imprime a lista
    void printList() {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList<int> myList;

    myList.insertAtEnd(1);
    myList.insertAtEnd(2);
    myList.insertAtFront(0);
    myList.printList();

    myList.removeFromFront();
    myList.removeFromEnd();
    myList.printList();

    return 0;
}
