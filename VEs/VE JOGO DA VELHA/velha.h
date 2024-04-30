// 2. (5,0) O Jogo da Velha é um jogo simples e fácil de ser ensinado. Em um tabuleiro 3x3, jogadores se
// alternam escolhendo casas do tabuleiro. O objetivo final do jogo é ser o primeiro a traçar uma linha reta
// de três casas, seja na vertical, na horizontal ou na diagonal. Esse jogo pode ser generalizado para um
// tabuleiro n x n, onde o objetivo é também traçar uma linha reta, agora de tamanho n. Seu objetivo é
// implementar esse jogo. Implemente uma classe que gerencie um jogo completo de jogo da velha. Sua
// classe deve conter
// a) (1,5) Um construtor que recebe o tamanho n do tabuleiro. O tabuleiro deve ser alocado
// dinamicamente.
// b) (2,5) Um método jogar que recebe as coordenadas da casa a ser jogada e retorna um enum com a
// situação após a jogada. As situações possíveis são: Vitória do Jogador O, Vitória do Jogador X,
// Empate, Última Jogada Inválida, Última Jogada Válida. Uma Jogada Inválida ocorre quando são
// passadas coordenadas fora do tabuleiro ou já ocupadas. O método deve controlar de quem é a vez de
// jogar.
// d) (1,0) Um método que imprime o tabuleiro na sua situação corrente. A impressão deve ser similar ao
// seguinte exemplo.

#ifndef VELHA_H
#define VELHA_H

#include <iostream>

#define pA 'x'
#define pB 'o'
#define p0 ' '

enum {vitoriaO = 0, vitoriaX, empate, valida,invalida};

class Velha
{
    private:
    int size;
    bool time; //true a;x ; false b;o
    char **array;
    int jogadas;
    int endGame;

    int winner();
    void trace();
    char line();
    char column();
    char diagonalFirst();
    char diagonalSecond();

    public:
    Velha (const int); //recebe o tamanho do tabuleiro
    int jogar(int, int); //recebe as coordenadas, controla de quem é a vez de jogar(time)
    void print();
};

Velha::Velha (const int n) : size(n), time(true), jogadas(0), endGame(n*n) 
{
    array = new char*[size];
    for (int i = 0; i < size; i++) array[i] = new char[size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            array[i][j] = p0;
        }
    }
}

void Velha::trace()
{
    for (int i = 0; i < 2*size + 1; i++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;
}
char Velha::line()
{
    int counter, i = 0, j = 0;
    for (i = 0; i < size; i++)
    {
        counter = 0;
        for (j = 0; j < size - 1; j++)
        {
            if(array[i][j] != array[i][j+1]) break;
            else counter++;
        }
        if (counter == size - 1) return array[i][0];
    }
    return '\0';
}
char Velha::column()
{
    int counter, i = 0, j = 0;
    for (i = 0; i < size; i++)
    {
        counter = 0;
        for (j = 0; j < size - 1; j++)
        {
            if(array[j][i] != array[j+1][i]) break;
            else counter++;
        }
        if (counter == size - 1) return array[0][i];
    }
    return '\0';
}
char Velha::diagonalFirst()
{   
    int counter = 0, i = 0, j = 0;
    for (i = 0, j = 0; i < size-1, j < size-1; i++, j++)
    {
        if(array[i][j] != array[j+1][i+1]) break;
        else return array[0][0];
    }
    return '\0';
}
char Velha::diagonalSecond()
{
    for (int i = 0, j = size-1; i < size-1, j > 0; i++, j--)
    {
        if(array[i][j] != array[j-1][i+1]) break;
        else return array[0][size-1];
    }
    return '\0';
}
int Velha::winner()
{
    char L = line(), C = column(), D1 = diagonalFirst(), D2 = diagonalSecond();
    if(L)
    {
        if (L == 'o') return 0;
        else return 1;
    }
        else if(C)
        {
            if (C == 'o') return 0;
            else return 1;
        }
            else if(D1)
            {
                if (D1 == 'o') return 0;
                else return 1;
            }
                else if(D2)
                {
                    if (D2 == 'o') return 0;
                    else return 1;
                }
                    else return -1;
}

void Velha::print()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <  size; j++)
        {
            std::cout << "|" << array[i][j];
        }
        std::cout << "|" << std::endl;
        if(i+1 < size) trace();
    }
}

int Velha::jogar(int x, int y)
{
    if( !(x>0 && x <=size) || !(y>0 && y<=size)) return invalida;
    else
    {
        if(time == true) array[x-1][y-1] = pA;
        else array[x-1][y-1] = pB;
        jogadas++;
        if(jogadas >= size)
        {
            if (winner() == 0) return vitoriaO;
            if (winner() == 1) return vitoriaX;
        }
    }
    
}

#endif