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
#include <cstring>
#include <windows.h>

#define pA 'x'
#define pB 'o'
#define p0 ' '

enum {vitoriaO = 0, vitoriaX, empate, valida,invalida};

class Velha
{
    private:
    std::string ganhador;
    int size;
    bool time; //true a;x ; false b;o
    char **array;
    int jogadas;
    int endGame;
    bool fim;

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
    bool getFim();
    std::string getWinner();
};

Velha::Velha (const int n) : ganhador("empate"), size(n), time(true), jogadas(0), endGame(n*n), fim(0)
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

//funções para verificar se há vitoria
char Velha::line()
{
    // Verifica cada linha para ver se todos os elementos são iguais
    for (int i = 0; i < size; i++)
    {
        int counter = 0;
        // Compara cada elemento da linha com o próximo
        for (int j = 0; j < size - 1; j++)
        {
            if (array[i][j] != array[i][j+1])
                break;
            else
                counter++;
        }
        // Se todos os elementos forem iguais, retorna o elemento da linha
        if (counter == size - 1)
            return array[i][0];
    }
    // Se nenhuma linha completa foi encontrada, retorna '\0'
    return '\0';
}

char Velha::column()
{
    // Verifica cada coluna para ver se todos os elementos são iguais
    for (int i = 0; i < size; i++)
    {
        int counter = 0;
        // Compara cada elemento da coluna com o próximo
        for (int j = 0; j < size - 1; j++)
        {
            if (array[j][i] != array[j+1][i])
                break;
            else
                counter++;
        }
        // Se todos os elementos forem iguais, retorna o elemento da coluna
        if (counter == size - 1)
            return array[0][i];
    }
    // Se nenhuma coluna completa foi encontrada, retorna '\0'
    return '\0';
}

char Velha::diagonalFirst()
{
    int counter = 0;
    // Verifica se todos os elementos na diagonal principal são iguais
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i][i] != array[i+1][i+1])
            break;
        counter++;
    }
    // Se todos os elementos da diagonal principal forem iguais, retorna o elemento no topo
    if (counter == size - 1)
        return array[0][0];
    // Caso contrário, retorna '\0'
    return '\0';
}

char Velha::diagonalSecond()
{
    int counter = 0;
    // Verifica se todos os elementos na diagonal secundária são iguais
    for (int i = 0, j = size - 1; i < size - 1 && j > 0; i++, j--) //se utilizar a vírgula ao invés do loop, ele descarta a primeira a primeira condição, portando deve-se utilizar &&
    {
        if (array[i][j] != array[i + 1][j - 1])
            break;
        counter++;
    }
    // Se todos os elementos da diagonal secundária forem iguais, retorna o elemento no topo desta diagonal
    if (counter == size - 1)
        return array[0][size - 1];
    // Caso contrário, retorna '\0'
    return '\0';
}

int Velha::winner()
{
    char L = line(), C = column(), D1 = diagonalFirst(), D2 = diagonalSecond();

    if(line()=='x' || line()=='o')
    {
        std::cout << "L positivo" << std::endl; 
        if (L == 'x') return 0;
        else return 1;
    }
        else if(C)
        {
        std::cout << "C positivo" << std::endl; 
            if (C == 'x') return 0;
            else return 1;
        }
            else if(D1)
            {
        std::cout << "D1 positivo" << std::endl; 
                if (D1 == 'x') return 0;
                else return 1;
            }
                else if(D2)
                {
        std::cout << "D2 positivo" << std::endl; 
                    if (D2 == 'x') return 0;
                    else return 1;
                }
                    else return -1;
}

void Velha::print()
{
    //system("cls");
    puts("");
    std::cout << "JOGO DA VELHA\n\n";
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
    if(jogadas == endGame)
    {   
        //std::cout << "Jogo empatado!";
        //std::cin.ignore();
        //getchar();
        fim = true;
        return empate;
    }
    else
    {
        if( !(x>0 && x <=size) || !(y>0 && y<=size) || (array[x-1][y-1] != ' '))
        {
            std::cout << "Jogada invalida!";
            std::cin.ignore();
            getchar();
            return invalida;
        }
        else
        {
            if(time == true) array[x-1][y-1] = pA;      //se for a vez de X, preencher com pA = x
            else array[x-1][y-1] = pB;                  //do contrário, preencher com pB = o
            {
                if(jogadas >= size)                     //numero mínimo de jogadas para haver vitória
                {
                    if (winner() == 0)
                    {
                        std::string player1 = "Player 1 ganhou!";
                        ganhador = player1;
                        std::cin.ignore();
                        getchar();
                        fim = true;
                        return vitoriaX;
                    }
                    else
                    {
                        if (winner() == 1)
                        {
                            std::string player2 = "Player 2 ganhou!";
                            ganhador = player2;
                            std::cin.ignore();
                            getchar();
                            fim = true;
                            return vitoriaO;
                        }
                        else
                        {
                            jogadas++;                             //controla o numeros de lances
                            time = !time;
                            return valida;
                        }
                    }
                }
                else
                {
                    jogadas++;                             //controla o numeros de lances
                    time = !time;
                    return valida;
                }
            }
        }
    }    
}

bool Velha::getFim()
{
    return fim;
}

std::string Velha::getWinner()
{
    if(ganhador.compare("empate") == 0) std::cout << "Jogo empatado!";
    else 
    {
        return ganhador;
    }
}


#endif