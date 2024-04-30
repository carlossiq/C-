/*
As classes Elfo, Anão, e Humano devem herdar da classe Soldado e devem ter seus próprios poderes de ataque.
A classe Elfo possui um bônus de +1 poder de ataque.
A classe Anão tem um bônus de ataque de +20 porém 40% de chance de errar um ataque.
Já a classe Humano tem 10% de chance de realizar um ataque.
*/

#ifndef CLASSES_H
#define CLASSES_H

#include "Soldado.h"

class Elfo : public Soldado
{
    public:  
    Elfo(string novoNome) : Soldado(novoNome)
    {
        poderDeAtaque += 1;     //bonus do poder de ataque para elfos
        titulo = "o Elfo";
    };
    
    Elfo(string novoNome, double novaSaude, double novoPoder) : Soldado(novoNome, novaSaude, novoPoder)
    {
        poderDeAtaque += 1;     //bonus do poder de ataque para elfos
        titulo = "o Elfo";
    };
    
    ~Elfo(){};
};

class Anao : public Soldado
{
    public:
    void atacar(Soldado &inimigo);
    Anao(string novoNome) : Soldado(novoNome)
    {
        poderDeAtaque += 20;     //bonus do poder de ataque para Anoes
        titulo = "o Anao";
    }

    Anao(string novoNome, double novaSaude, double novoPoder) : Soldado(novoNome, novaSaude, novoPoder)
    {
        poderDeAtaque += 20;     //bonus do poder de ataque para Anoes
        titulo = "o Anao";
    };

    ~Anao(){}
};

class Humano : public Soldado
{
    public:
    void atacar(Soldado &inimigo);
    Humano(string novoNome) : Soldado(novoNome){}
    Humano(string novoNome, double novaSaude, double novoPoder) : Soldado(novoNome, novaSaude, novoPoder){titulo = "o Humano";}
    ~Humano(){titulo = "o Humano";}
};

void Anao::atacar(Soldado &inimigo)
{
    std::random_device rd;  // Dispositivo de entropia não determinístico
    std::mt19937 gen(rd());  // Gerador de números pseudoaleatórios com semente do dispositivo de entropia
    std::uniform_int_distribution<> dist(0, 99);  // Distribuição uniforme entre 0 e 99

    int numero = dist(gen);  // Gera um número aleatório usando a distribuição
    if(numero < 40)                             //40% de chance de erro
    {
        cout << nome << " errou o ataque!" << endl;
    }
    else
    {
        cout << inimigo.getNome() << " foi atacado!" << endl;
        inimigo.saude -= poderDeAtaque;          //inflige o dano
        inimigo.defender(poderDeAtaque);        //defende
    }  
}

void Humano::atacar(Soldado &inimigo)
{
    std::random_device rd;                        // Dispositivo de entropia não determinístico
    std::mt19937 gen(rd());                       // Gerador de números pseudoaleatórios com semente do dispositivo de entropia
    std::uniform_int_distribution<> dist(0, 99);  // Distribuição uniforme entre 0 e 99

    int numero = dist(gen);                       // Gera um número aleatório usando a distribuição
    if(numero < 10)                               //10% de chance de ataque
    { 
        cout << inimigo.getNome() << " foi atacado!" << endl;
        inimigo.saude -= poderDeAtaque;          //inflige o dano
        inimigo.defender(poderDeAtaque);         //defende
    }
}

#endif