#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;                      //objeto string

#include <cstring>
using std::memcpy;                      //copia de elementos

#include <vector>
using std::vector;                      //objeto vector

#include <algorithm>                    //funcoes de busca
using std::find_if;                     //algoritmo de busca
using std::sort;                        //função com algoritmo de organização
using std::copy;

#include <cstdlib>
#include <ctime>        

#include <random>                       //geração de números aleatórios
using std::random_device;               //semente de números não determinísticos
using std::mt19937;                     //motor de geração gen(rd)
using std::uniform_int_distribution;    //probabilidade uniforme de inteiros

#include <initializer_list>             //lista de inicialização(permite utilizar uma lista como parâmetro)
using std::initializer_list;

#include <cassert>                      //verifica condições(como em um debug retornando true ou false) retornando erro

#include <iomanip>                      //formatação de entrada e saída de fluxos
using std::setw;                        //largura do campo de inserção
using std::setfill;                     //preenche o campo de inserção com um caractere ' '
using std::setbase;                     //base 10, 16, 8 ...
using std::setprecision;                //numero de digitos de presição de ponto flutuante
using std::left;                        //alinhamento a esquerda
using std::right;                       
using std::internal;                       

// X cor do jogador 1
// 0 cor do jogador 2
// ponto para uma posicao nao ocupada

#include <cmath>

enum tab {vazio = 0, jogador_1 = 1, jogador_2 = 20};
enum situation {valida = 0, invalida};

class Lig4
{
    private:
    int m;                              //colunas
    int n;                              //linhas
    int k;                              //sequencia

    int end;                            //numero maximo de jogadas
    int counter;                        //jogadas realizadas
    int jogador;                        //vez do jogador

    int **field;                       //tabuleiro

    public:
    Lig4(int m, int n) : m(m), n(n), k(4), end(m*n), counter(0), jogador(jogador_1)
    {
        field = new int*[m];
        for(int i = 0; i < m; i++) field[i] = new int[n];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                field[j][i] = 0;
            }
    }

    ~Lig4(){delete[] field;}

    void display()
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(field[j][i] == vazio) cout << ".";
                else if(field[j][i] == jogador_1) cout << "X";
                else if(field[j][i] == jogador_2) cout << "O";
            }
            cout << endl;        
        }
        for(int i = 0; i < m; i++) cout << (i+1);
        cout << endl;
    }

    void alternarVez()
    {
        if(jogador == jogador_1) jogador = jogador_2;
        else jogador = jogador_1;
    }

    situation validade(int coluna, int linha)
    {
        if(coluna < 0 || coluna > m) return invalida;
        if(linha < 0 || linha > n) return invalida;
        if(field[coluna][linha] != vazio) return invalida;
        return valida;
    }

    void jogar(int coluna)
    {
        if(counter == end)
        {
            cout << "jogo encerrado!" <<endl;
            exit(1);
        }
        if(field[coluna][0] != vazio)
        {
            cout << "Jogada invalida." << endl << endl;
        }
        else
        {
            int i = n;
            int j = coluna;        
            while(true)
            {
                if(field[coluna][i] != vazio) i--;
                else break;
            }
            
            if(jogador == jogador_1)
            {
                if(validade(j,i) == valida)
                {
                    field[j][i] = jogador_1;
                    counter++;
                }
                else cout << "Jogada invalida." << endl << endl;
            }
            else //jogador 2
            {
                if(validade(j,i) == valida)
                {
                    field[j][i] = jogador_2;
                    counter++;
                }
                else cout << "Jogada invalida." << endl << endl;
            }

        }
    }

    void resultado()
    {
        display();
        
    }

};

int main()
{
    Lig4 game(7, 6);
    game.display();
    game.jogar(0);
    game.alternarVez();
    game.jogar(1);
    game.jogar(2);
    game.jogar(2);
    game.jogar(2);
    game.jogar(2);
    game.jogar(2);
    game.jogar(2);
    game.jogar(2);
    game.jogar(2);                  //jogada invalida
    //game.jogar(2);
    //game.jogar(3);
    //game.jogar(0);
    game.display();
    return 0;
}