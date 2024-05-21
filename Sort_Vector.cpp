#include <iostream>
#include <vector>
#include <algorithm>  // Necessário para std::sort

int main() {
    std::vector<int> vec = {10, 5, 15, 20, 3};

    // Ordenando em ordem ascendente
    std::sort(vec.begin(), vec.end());

    // Ordenando em ordem descendente
    //std::sort(vec.begin(), vec.end(), [](int a, int b) {
    //    return a > b;
    //});

    // Imprimindo o vetor ordenado
    std::cout << "Vetor ordenado: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}