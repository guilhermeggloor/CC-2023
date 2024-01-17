#include <iostream>
#include <vector>
#include <algorithm>

class SortedSet {
private:
    std::vector<int> data;

public:
    void insert(int value) {
        auto it = std::upper_bound(data.begin(), data.end(), value);
        data.insert(it, value);
    }

    int read(int index) {
        if (index >= 0 && index < data.size()) {
            return data[index];
        } else {
            return -1;
        }
    }

    void remove(int value) {
        data.erase(std::remove(data.begin(), data.end(), value), data.end());
    }

    void print() {
        for (int value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    SortedSet mySet;
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(3);
    mySet.insert(4);
    mySet.insert(1);

    std::cout << "Conjunto ordenado: ";
    mySet.print();

    int index = 2;
    int value = mySet.read(index);
    if (value != -1) {
        std::cout << "Elemento na posição " << index << ": " << value << std::endl;
    } else {
        std::cout << "Índice fora dos limites." << std::endl;
    }

    int valueToRemove = 1;
    mySet.remove(valueToRemove);
    std::cout << "Após a remoção de " << valueToRemove << ": ";
    mySet.print();

    return 0;
}
