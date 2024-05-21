#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;

int binarySearch(const vector<int>& vec, int value) {
    // Usando std::lower_bound para encontrar o valor, que retona o iterador que aponta para o valor
    auto it = std::lower_bound(vec.begin(), vec.end(), value);

    // Verifica se o iterador não está no fim e se o elemento no iterador é o valor procurado
    if (it != vec.end() && *it == value) { //operador de dereferência necessário para imprimir o iterador
        // Retorna o índice do elemento
        return it - vec.begin();
    } else {
        // Retorna -1 se o valor não for encontrado
        return -1;
    }
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};  // Vetor deve estar ordenado para busca binária
    int x = 10;
    
    int result = binarySearch(arr, x);
    if (result == -1) {
        std::cout << "Elemento não presente no vetor";
    } else {
        std::cout << "Elemento encontrado no índice " << result;
    }

    return 0;
}