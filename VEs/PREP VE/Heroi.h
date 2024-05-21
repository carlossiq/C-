#ifndef HEROI_H
#define HEROI_H

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <random>

#include <vector>
using std::vector;

class Superpoder
{
    private:
    string nome;
    int categoria;

    public:
    string getNome()
    {
        return nome;
    }
    int getCategoria()
    {
        return categoria;
    }

    Superpoder(string nome, int categoria)
    {
        this->nome = nome;
        this->categoria = categoria;
    }
};

class Personagem
{
    private:
    string nome;
    string nomeVidaReal;
    Superpoder* poderes[4];

    public:
    bool adicionaSuperpoder(Superpoder &sp)
    {
        for(int i = 0; i < 4; i++)
        {
            if(poderes[i] == nullptr)
            {
                poderes[i] = new Superpoder(sp);
                return true;
            }
        }
        return false;
    }
    virtual double getPoderTotal()
    {
        double poderTotal = 0;
        for(int i = 0; i < 4; i++)
            if(poderes[i] != nullptr)
                poderTotal += poderes[i]->getCategoria();

        return poderTotal;
    }
    string getNome()
    {
        return nome;
    }

    Personagem (string nome, string nomeVidaReal)
    {
        this->nome = nome;
        this->nomeVidaReal = nomeVidaReal;
        for(int i = 0; i < 4; i++) poderes[i] = nullptr;
    }

    Personagem (const Personagem& copia) //
    {
        this->nome = copia.nome;
        this->nomeVidaReal = copia.nomeVidaReal;
        for(int i = 0; i < 4; i++)
        {
            if(copia.poderes[i] != nullptr)
            {
                poderes[i] = new Superpoder(*(copia.poderes[i])); //* acessa o objeto ao qual copia.poderes[i] aponta
            } else poderes[i] = nullptr;
        }
    }

    ~Personagem (){ delete[] poderes;}
};

class SuperHeroi : public Personagem
{
    public:
    double getPoderTotal() override
    {
        return Personagem::getPoderTotal()*1.1;
    }

    SuperHeroi(string nome, string nomeVidaReal) :  Personagem(nome, nomeVidaReal){}
};

class Vilao : public Personagem
{
    private:
    int tempoDePrisao;

    public:
    double getPoderTotal() override
    {
        double aux = tempoDePrisao*0.01 + 1; //adiciona 1% para cada ano de prisão;
        return Personagem::getPoderTotal()*aux;
    }

    Vilao(string nome, string nomeVidaReal, int tempoDePrisao) : Personagem(nome, nomeVidaReal)
    {
        this->tempoDePrisao = tempoDePrisao;
    }
};

class Confronto
{
    public:
    string enfrentar (SuperHeroi &p1, Vilao &p2)
    {     
        if(p1.getPoderTotal() > p2.getPoderTotal())
        {
            return p1.getNome();
        }
        else if(p1.getPoderTotal() < p2.getPoderTotal())
        {
            return p2.getNome();
        }
        else
        {
            return "Empate";
        }
    }
};

#endif