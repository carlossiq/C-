#include <iostream>

// Função que implementa a busca binária
int binarySearch(int arr[], int l, int r, int x) { //left right
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Verifica se x está presente no meio
        if (arr[m] == x)
            return m;

        // Se x for maior, ignora a metade esquerda
        if (arr[m] < x)
            l = m + 1;

        // Se x for menor, ignora a metade direita
        else
            r = m - 1;
    }

    // Se não encontramos o elemento
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    
    if(result == -1) 
        std::cout << "Elemento não presente no array";
    else
        std::cout << "Elemento encontrado no índice " << result;
    
    return 0;
}