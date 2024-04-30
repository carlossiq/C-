#ifndef FRIENDS_H
#define FRIENDS_H

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm> //funcoes de busca
using std::find_if;

class Character
{
    private:
    string nome;
    string ocupacao;

    public:
    string getNome();
    string getOcupacao();
    void setNome(string novoNome);
    void setOcupacao(string novaOcupacao);

    Character(string novoNome, string novaOcupacao)
    {
        setNome(novoNome);
        setOcupacao(novaOcupacao);
    }
};

class Relacao
{
    private:
    string A;
    string B;
    string relacao;

    public:
    string getA();
    string getB();
    string getRelacao();

    void setA(string);
    void setB(string);
    void setRelacao(string);

    Relacao(string nomeA, string nomeB, string novaRelacao)
    {
        setA(nomeA);
        setB(nomeB);
        setRelacao(novaRelacao);
    }
};

class CharacterDatabase
{
    private:
    vector <Character> personagens;
    vector <Relacao> relacoes;

    public:
    void addCharacter(Character);
    void editCharacter(string, string );
    void relate(Character, Character, string);
    void deleteCharacter(string);
    void imprimir();

    int searchCharacter(string);

    CharacterDatabase(){};
};

string Character::getNome(){return nome;}
string Character::getOcupacao(){return ocupacao;}
void Character::setNome(string novoNome){nome = novoNome;}
void Character::setOcupacao(string novaOcupacao){ocupacao = novaOcupacao;}

string Relacao::getA(){return A;}
string Relacao::getB(){return B;}
string Relacao::getRelacao(){return relacao;}
void Relacao::setA(string nome){A = nome;}
void Relacao::setB(string nome){B = nome;}
void Relacao::setRelacao(string novaRelacao){relacao = novaRelacao;}

int CharacterDatabase::searchCharacter(string nome)//erro
{
    auto it = find_if(personagens.begin(), personagens.end(), nome);
    int posicao = it - personagens.begin();
    return posicao;
}

void CharacterDatabase::addCharacter(Character c)
{
    personagens.push_back(c);
}

void CharacterDatabase::deleteCharacter(string nome)
{
    int posicao = searchCharacter(nome);
    personagens.erase(personagens.begin() + posicao);
}
void CharacterDatabase::editCharacter(string nome, string novaOcupacao)
{
    int posicao = searchCharacter(nome);
    personagens[posicao].setOcupacao(novaOcupacao);
}

void CharacterDatabase::relate(Character c1, Character c2, string novaRelacao)
{
    Relacao auxiliar(c1.getNome(), c2.getNome(), novaRelacao);
    relacoes.push_back(auxiliar);
}


void CharacterDatabase::imprimir()
{
    cout << "Lista de Personagens:" << endl;
    for (auto i : personagens)
    {
        cout << i.getNome() << endl;
    }
    
}

#endif