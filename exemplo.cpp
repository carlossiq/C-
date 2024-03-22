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
    
    // Dados de exemplo
    dados->numero = 10;
    dados->decimal = 3.14f;
    dados->caractere = 'A';

    // Abre um arquivo binário para escrita
    ofstream arquivo("dados.bin", ios::binary);

    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo." << endl;
        delete dados; // Liberar a memória alocada
        return 1;
    }

    // Escreve os dados no arquivo
    arquivo.write(reinterpret_cast<const char*>(dados), sizeof(Dados));

    // Fecha o arquivo
    arquivo.close();

    // Liberar a memória alocada
    delete dados;

    cout << "Dados salvos no arquivo binário com sucesso." << endl;

    return 0;
}