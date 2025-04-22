#include <iostream>
#include <cstdlib>

class Ensemble {
private:
    static const int MAX_SIZE = 100;
    int elements[MAX_SIZE];
    int size;

public:
    Ensemble() : size(0) {}

    bool empty() {
        size = 0;
        return true;
    }

    bool add(int element) {
        if (size >= MAX_SIZE)
            return false;

        for (int i = 0; i < size; i++) {
            if (elements[i] == element)
                return false;
        }

        elements[size++] = element;
        return true;
    }

    bool remove(int element) {
        for (int i = 0; i < size; i++) {
            if (elements[i] == element) {
                for (int j = i; j < size - 1; j++) {
                    elements[j] = elements[j + 1];
                }
                size--;
                return true;
            }
        }
        return false;
    }

    bool copy(Ensemble& other) {
        if (this == &other)
            return true;

        if (size > other.size) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            other.elements[i] = elements[i];
        }
        other.size = size;
        return true;
    }

    bool is_member(int element) {
        for (int i = 0; i < size; i++) {
            if (elements[i] == element)
                return true;
        }
        return false;
    }

    bool is_equal(Ensemble& other) {
        if (size != other.size)
            return false;

        for (int i = 0; i < size; i++) {
            if (!other.is_member(elements[i]))
                return false;
        }
        return true;
    }

    void print() {
        std::cout << "{ ";
        for (int i = 0; i < size; i++) {
            std::cout << elements[i] << " ";
        }
        std::cout << "}" << std::endl;
    }
};

int main() {
    Ensemble e1, e2;
    e1.add(1);
    e1.add(2);
    e1.add(3);
    e1.print(); // Affiche : { 1 2 3 }

    e2.add(2);
    e2.add(4);
    e2.print(); // Affiche : { 2 4 }

    e1.remove(2);
    e1.print(); // Affiche : { 1 3 }

    e2.copy(e1);
    e2.print(); // Affiche : { 1 3 }

    std::cout << "L'élément 3 est-il dans l'ensemble ? " << (e2.is_member(3) ? "Oui" : "Non") << std::endl;
    std::cout << "Les ensembles e1 et e2 sont-ils égaux ? " << (e1.is_equal(e2) ? "Oui" : "Non") << std::endl;

    return 0;
}
