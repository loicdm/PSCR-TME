#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : tab) {
        std::cout << i << std::endl;
    }

    for (int i=9; i > 0 ; i--) {
        if (tab[i] - tab[i-1] != 1) {
            std::cout << "probleme !";
        }
    }
    return 0;
}
