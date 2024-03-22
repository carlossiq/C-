#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Estrutura de exemplo para dados
struct Dados {
    int numero;
    float decimal;
    char caractere;
};

int main() {
    // Alocando a estrutura na memória
    Dados *dados = new Dados;
    
    // Abre um arquivo binário para escrita
    ifstream arquivo("dados.bin", ios::binary);

    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    // Escreve os dados no arquivo
    arquivo.read(reinterpret_cast<char*>(dados), sizeof(Dados));

    // Fecha o arquivo
    arquivo.close();
    
    cout << dados->caractere << endl;
    cout << dados->decimal << endl;
    cout << dados->numero << endl;

    return 0;
}