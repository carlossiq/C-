// Implemente um sistema de contabilização de votos
// Ler os dados  dos candidatos de arquivo candidatos.txt armazenando as informações na memória
// Ler os dados da votação de cada urna arquivo urnas[1-4].txt, acumulando os votos de cada candidato
// Exibir na tela o relatório:
// quantidade de votos de cada candidato ordenada
// percentual de cada candidato sobre o total
// todo o sistema deve usar streams

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Candidato
{
    int numero, votos;
    string nome, partido;
    Candidato(int numero, string nome, string partido) : numero(numero), votos(0), nome(nome), partido(partido) {}

};

int main()
{
    ifstream arqCandidatos("candidatos.txt");
    vector<Candidato> candidatos;

    if(!arqCandidatos.is_open()) return 1;

    while(!arqCandidatos.eof())
    {
        int numero;
        string nome, partido;
        arqCandidatos >> numero >> nome >> partido;
        if(arqCandidatos.good()) candidatos.push_back(Candidato(numero, nome, partido)); //good indica se a última operações foi válida, flag good setada pelo operador de extração
    }


    for(int u = 1; u <= 4; u++)
    {
        ostringstream oss;
        int voto;
        oss << "urna" << u << ".txt";
        ifstream arqVotos(oss.str());
        if(!arqVotos.is_open()) return 2;
        while(!arqVotos.eof())
        {
            arqVotos >> voto;
            if(arqVotos.good()) candidatos[voto-1].votos++;
        }
        arqVotos.close();
    }

    for (int i = 0; i < candidatos.size(); i++)
    {
        cout << "Nome: " << candidatos[i].nome << ", Partido: " << candidatos[i].partido << ", Votos: " << candidatos[i].votos << endl;
    }
    
}