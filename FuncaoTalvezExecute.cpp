#include <iostream>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

void minhaFuncao() {
    std::cout << "A funçao foi executada!" << std::endl;
}

void talvezExecute() {
    srand(time(NULL));  // Inicializa o gerador de números aleatórios
    int numero = rand() % 100;  // Gera um número aleatório entre 0 e 99
    if (numero < 10) {  // 10% de chance de ser menor que 10
        minhaFuncao();  // Executa a função
    }
}

int main() {
    talvezExecute();  // Testa a função
    return 0;
}