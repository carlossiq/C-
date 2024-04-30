#include <iostream>
#include <random>

int main()
{
    int tamanho = 10;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, tamanho - 1);


    int cont = 0;
    while(cont != 20)
    {
    int i = dis(gen);
    std::cout << i << std::endl;
    cont ++;
    }
}