/*
A classe Sauron também deve herdar da classe Soldado.
Deve ter uma saúde muito alta (bônus 10x) e 30% chance de atacar com um poder duplo.
Já a classe Orc também deve herdar da classe Soldado e deve representar o exército de Sauron.
Deve ter uma chance de 20% de ataque duplo com 10% de bônus.
*/

#ifndef MAGO_H
#define MAGO_H

#include "Soldado.h"

class Mago : public Soldado
{
    public:  
    Mago(string novoNome) : Soldado(novoNome)
    {
        saude *= 0.8;                           //A classe mago 20% possui menos saude
        saudeMax = saude;                            
        poderDeAtaque += 50;                    //A classe mago possui um bonus de ataque de 50
        titulo = "o Mago";
    };
    
    Mago(string novoNome, double novaSaude, double novoPoder) : Soldado(novoNome, novaSaude, novoPoder)
    {
        saude *= 0.8;                             //A classe mago possui menos saude
        saudeMax = saude;
        poderDeAtaque += 50;                    //A classe mago possui um bonus de ataque de 50
        titulo = "o Mago";
    };

    ~Mago(){};
    void atacar(Soldado &inimigo);
    void recuperar();                           //A classe mago pode recuperar vida a cada ataque realizado com sucesso   
};

void Mago::atacar(Soldado &inimigo)
{
    std::random_device rd;                        // Dispositivo de entropia não determinístico
    std::mt19937 gen(rd());                       // Gerador de números pseudoaleatórios com semente do dispositivo de entropia
    std::uniform_int_distribution<> dist(0, 99);  // Distribuição uniforme entre 0 e 99

    int numero = dist(gen);  // Gera um número aleatório usando a distribuição

    if(numero < 50)                             //50% de chance de ataque
    {
        cout << inimigo.getNome() << " foi atacado com magia!" << endl;
        inimigo.saude -= poderDeAtaque;          //inflige o dano
        inimigo.defender(poderDeAtaque);         //defende
        recuperar();
    }
    else cout << getNome() << " errou o ataque!" << endl;
}

void Mago::recuperar()
{
    if(saude != saudeMax)                           //se não houver nada para recuperar, não acontece nada
    {
        saude += 0.1*saudeMax;                      //recuper 10% da vida maxima
        if (saude > saudeMax) {saude = saudeMax;}
        cout <<  "Saude do mago recuperada!" << endl;
        //getchar();
    }
}
#endif