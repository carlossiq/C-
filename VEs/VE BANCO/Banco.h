/*
PROGRAMA QUE SIMULA O ATENDIMENTO DE UM BANCO.
FUNCIONAMENTO EM CAPACIDADE MAXIMA DIÁRIA E DOIS CAIXAS;
CLIENTE COMUM:
NOME, TEMPO DE CHEGADA, DURAÇÃO DO SV(INT MINUTO)
CLIENTE PREFERENCIAL: +Ñ DESISTE APÓS O TEMPO MAX

1)CONSTRUA A HIERARQUIA DE CLASSES COMPLETA PARA OS CLIENTES QUE MINIMIZE A REP DOS CÓDIGOS;
2)CLASSE BANCO QUE IMPLEMENTA FILAS DE ATENDIMENTO COM A POSSIBILIDADE DE INCLUIR CLIENTES ANTES DA SIMULAÇÃO; (NÃO HÁ RELAÇÃO ENTRE A ORDEM DE CHEGADA DA FILA E A ORDEM DE INSERÇÃO NA FILA)
3)FAÇA O MÉTODO SIMULAR QUE A CADA MINUTO MOSTRA NA TELA SE EXISTE UM CLIENTE TERMINANDO ATENDIMENTO OU DEIXANDO A FILA SEM ATENDIMENTO;
AO FINAL DEVE SER RETORNADA A EFICIENCIA DO ATENDIMENTO COM O TEMPO MÉDIO DE ATENDIMENTO E O NUMERO DE DESISTENTES
*/

#ifndef BANCO_H
#define BANCO_H

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

//1) HIERAQUIA DE CLASSES DE CLIENTES
class Cliente
{
    protected:
    string nome;
    int t_chegada;
    int t_servico;

    public:
    friend class Banco;
    Cliente (string novoNome, int t1, int t2) : nome(novoNome), t_chegada(t1), t_servico(t2){}
    
};

class ClienteComum : public Cliente
{
    private:
    int t_espera;

    public:
    friend class Banco;
    ClienteComum (string novoNome, int t1, int t2, int t3) : Cliente (novoNome, t1, t2), t_espera(t3){}
};

class ClientePreferencial : public Cliente
{
    public:
    friend class Banco;
    ClientePreferencial (string novoNome, int t1, int t2) : Cliente (novoNome, t1, t2){}
};

//
struct stats
{
    int tempoMedio;
    int desistentes;
};

//2) CLASSE BANCO
class Banco
{
    private:
    int capacidade;
    int tempo;
    vector <ClienteComum> caixaComum;
    vector <ClientePreferencial> caixaPreferencial;

    public:
    Banco(int novaCapacidade): capacidade(novaCapacidade), tempo(0){}
    void adicionarCliente(ClienteComum);
    void adicionarCliente(ClientePreferencial);
    stats simular();
    void printCaixaComum()
    {
        for(int i=0; i < (int)caixaComum.size(); i++)
        {
            cout << caixaComum[i].nome << " ";
        }
        puts("");
    }
};

void Banco::adicionarCliente(ClienteComum novoCliente)
{
    caixaComum.push_back(novoCliente);
    sort(caixaComum.begin(), caixaComum.end(), [](const ClienteComum& a, const ClienteComum& b) { return a.t_chegada < b.t_chegada; }); //organiza a vector de maneira a ter o primeiro elemento com menor tempo de chegada
}

void Banco::adicionarCliente(ClientePreferencial novoCliente)
{
    caixaPreferencial.push_back(novoCliente);
    sort(caixaPreferencial.begin(), caixaPreferencial.end(), [](const ClientePreferencial& a, const ClientePreferencial& b) {return a.t_chegada < b.t_chegada;}); //idem
}

stats Banco::simular()
{
    stats valor;
    int tempoMedio = 0, desistentes = 0;
    int numeroClientes = caixaComum.size() + caixaPreferencial.size();

    while(caixaComum.size() > 0 || caixaPreferencial.size() > 0) //enquanto houver alguém na fila de qualquer caixa
    {      
        tempo++;
        //cout << tempo << endl;
        //caixa comum
        if(caixaComum.size() > 0)
        {
            for(int i = 0; i < (int)caixaComum.size(); i++)
            {
                if(tempo >= caixaComum[i].t_chegada) //indica se que o cliente chegou a fila
                {
                    if(i == 0)
                    {
                        if(caixaComum[i].t_servico == 0)
                        {
                            cout << "Cliente " << caixaComum[i].nome << " terminando o atendimento." << endl << endl;
                            caixaComum.erase(caixaComum.begin());
                        }
                        else caixaComum[i].t_servico--;
                    }
                    else //se o cliente não estiver sendo atendido
                    {
                        if(tempo > caixaComum[i].t_espera + caixaComum[i].t_chegada) //se o tempo de espera do cliente comum é excedido
                        {
                            cout << "Cliente " << caixaComum[i].nome << " deixando a fila sem atendimento." << endl << endl;
                            caixaComum.erase(caixaComum.begin() + i); //o cliente comum desiste
                            desistentes++;
                        }
                    }

                }
                
            }
        }

        //caixa preferencial
        if(caixaPreferencial.size() > 0)
        {
            if(caixaPreferencial[0].t_servico == 0)
            {
                cout << "Cliente Preferencial " << caixaPreferencial[0].nome << " terminando o atendimento." << endl << endl;
                caixaPreferencial.erase(caixaPreferencial.begin());
            }
            caixaPreferencial[0].t_servico--;
        }
    }

    tempoMedio = tempo/numeroClientes;
    valor.tempoMedio = tempoMedio;
    valor.desistentes = desistentes;

    return valor;    
}

#endif