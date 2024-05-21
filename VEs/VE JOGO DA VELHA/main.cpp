#include "velha.h"

int main()
{
    int x, y;
    Velha jogo(3);
    jogo.print();
    while(1)
    {
        if(jogo.getFim())
        {
            std::cout <<  "Jogo encerrado!" << std::endl;
            break;
        }
        std::cout << "Insira as coordenadas 'x' e 'y': ";
        std::cin.clear();
        std::cin >> x >> y;
        jogo.jogar(x,y);
        jogo.print();
    }
    std::cout << jogo.getWinner() << std::endl;   
}