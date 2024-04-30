/*
A classe Soldado deve ser a classe base.
Deve ter variáveis de membro para o nome do soldado, saúde e poder de ataque.
Os seus métodos são atacar e defender.
O método atacar recebe como parâmetro outro Soldado e inflige um dano igual ao seu poder de ataque.
O método defender remove do atributo saúde, o valor do poder ataque repassado, e deve ser usado pelo
método atacar.
*/

#ifndef SOLDADO_H
#define SOLDADO_H

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <random>

class Soldado
{
    protected:
    string nome;
    double saudeMax;
    double saude;
    double poderDeAtaque;
    string titulo;

    bool lado;                              //bem = true; mal = false

    public:
    friend class Anao;
    friend class Humano;
    friend class Orc;
    friend class Sauron;
    friend class Mago;
    friend class Elfo;

    virtual void atacar(Soldado &inimigo);
    void defender(double poderDeAtaque);
    bool condicao();

    string getNome();
    string getTitulo();
    double getSaude();
    bool getLado();

    void setSaude(double novaSaude);
    
    Soldado(string novoNome)                //atributos padrão
    {
        nome = novoNome;
        saude = saudeMax = 100;
        poderDeAtaque = 20;
        lado = true;
        titulo = "Soldado";
    };

    Soldado(string novoNome, double novaSaude, double novoPoder)
    {
        nome = novoNome;
        saude = saudeMax = novaSaude;
        poderDeAtaque = novoPoder;
        lado = true;
        titulo = "Soldado";
    };
    
    ~Soldado(){};
};

void Soldado::atacar(Soldado &inimigo)
{
    cout << inimigo.getNome() << " foi atacado!" << endl;
    inimigo.saude -= poderDeAtaque;         //inflige o dano
    inimigo.defender(poderDeAtaque);        //defende
}

void Soldado::defender(double poderDeAtaque)   //20% de chance de defesa para todos os Soldados
{
    std::random_device rd;  // Dispositivo de entropia não determinístico
    std::mt19937 gen(rd());  // Gerador de números pseudoaleatórios com semente do dispositivo de entropia
    std::uniform_int_distribution<> dist(0, 99);  // Distribuição uniforme entre 0 e 99

    int probabilidade = dist(gen);          // Gera um número aleatório usando a distribuição
    if(probabilidade < 20)                  //se o numero for menor que 20, executa
    {
        saude += poderDeAtaque;
        if (saude > saudeMax) saude = saudeMax;
        cout << "Ataque defendido!" << endl;
    }
}

bool Soldado::condicao()
{
    if(saude > 0) return true;
    else return false;
}

string Soldado::getNome()
{
    return nome;
}

string Soldado::getTitulo()
{
    return titulo;
}

double Soldado::getSaude()
{
    return saude;
}

bool Soldado::getLado()
{
    return lado;
}

void Soldado::setSaude(double novaSaude)
{
    saude = novaSaude;
}

#endif