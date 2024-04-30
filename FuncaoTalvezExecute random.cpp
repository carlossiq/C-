#include <iostream>
#include <random>  // Inclui std::random_device e std::mt19937

void minhaFuncao() {
    std::cout << "A função foi executada!" << std::endl;
}

void talvezExecute() {
    std::random_device rd;  // Dispositivo de entropia não determinístico
    std::mt19937 gen(rd());  // Gerador de números pseudoaleatórios com semente do dispositivo de entropia
    std::uniform_int_distribution<> dist(0, 99);  // Distribuição uniforme entre 0 e 99

    int numero = dist(gen);  // Gera um número aleatório usando a distribuição

    if (numero < 10) {  // 10% de chance de ser menor que 10
        minhaFuncao();  // Executa a função
    }
}

int main() {
    talvezExecute();  // Testa a função
    return 0;
}