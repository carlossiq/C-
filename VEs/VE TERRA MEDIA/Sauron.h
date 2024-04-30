/*
A classe Sauron também deve herdar da classe Soldado.
Deve ter uma saúde muito alta (bônus 10x) e 30% chance de atacar com um poder duplo.
Já a classe Orc também deve herdar da classe Soldado e deve representar o exército de Sauron.
Deve ter uma chance de 20% de ataque duplo com 10% de bônus.
*/

#ifndef SAURON_H
#define SAURON_H

#include "Soldado.h"

class Sauron : public Soldado
{
    public:  
    Sauron(string novoNome) : Soldado(novoNome)
    {
        saude *= 10;     //bonus de saude para Sauron
        saudeMax = saude;
        lado = false;
        titulo = "o senhor do escuro de Mordor";
    }
    
    Sauron(string novoNome, double novaSaude, double novoPoder) : Soldado(novoNome, novaSaude, novoPoder)
    {
        saude = novaSaude * 10;     //bonus de saude para Sauron
        saudeMax = saude;
        lado = false;
        titulo = "o senhor do escuro de Mordor";
    }
    
    ~Sauron(){};
    void atacar(Soldado &inimigo);    
};

class Orc : public Soldado
{
    public:  
    Orc(string novoNome) : Soldado(novoNome){lado = false; titulo = "o Orc";}
    
    Orc(string novoNome, double novaSaude, double novoPoder) : Soldado(novoNome, novaSaude, novoPoder){lado = false; titulo = "o Orc";} 

    ~Orc(){};
    void atacar(Soldado &inimigo);
};

void Sauron::atacar(Soldado &inimigo)
{
    std::random_device rd;                      // Dispositivo de entropia não determinístico
    std::mt19937 gen(rd());                     // Gerador de números pseudoaleatórios com semente do dispositivo de entropia
    std::uniform_int_distribution<> dist(0, 99);  // Distribuição uniforme entre 0 e 99

    int numero = dist(gen);                     // Gera um número aleatório usando a distribuição
    if(numero < 30)                             //30% de chance de ataque DUPLO
    {
        cout << inimigo.nome << " foi atacado com ataque duplo!" << endl;
        inimigo.saude -= 2*poderDeAtaque;       //inflige o dano
        inimigo.defender(poderDeAtaque);        //defende
        getchar();
    }
    else
    {
        cout << inimigo.nome << " foi atacado!" << endl;
        inimigo.saude -= poderDeAtaque;         //inflige o dano
        inimigo.defender(poderDeAtaque);        //defende
    }
}

void Orc::atacar(Soldado &inimigo)
{
    std::random_device rd;                      // Dispositivo de entropia não determinístico
    std::mt19937 gen(rd());                     // Gerador de números pseudoaleatórios com semente do dispositivo de entropia
    std::uniform_int_distribution<> dist(0, 99);  // Distribuição uniforme entre 0 e 99

    int numero = dist(gen);                     // Gera um número aleatório usando a distribuição
    if(numero < 20)                             //20% de chance de ataque DUPLO com 10% de bonus
    {
        cout << inimigo.nome << " foi atacado com ataque duplo!" << endl;
        inimigo.saude -= 2*1.1*poderDeAtaque;   //inflige o dano
        inimigo.defender(poderDeAtaque);        //defende
        getchar();
    }
    else
    {
        cout << inimigo.nome << " foi atacado!" << endl;
        inimigo.saude -= poderDeAtaque;         //inflige o dano
        inimigo.defender(poderDeAtaque);        //defende
    }
}

#endif