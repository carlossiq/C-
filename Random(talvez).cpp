#include <iostream>
#include <random>
#include <ctime>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

int main()
{
    int tamanho = 10; //10% de chance de execução

    /* é uma classe que fornece um gerador de números aleatórios não determinístico.
    Isso significa que ele tenta usar uma fonte de aleatoriedade do sistema operacional para gerar
    números aleatórios que são menos previsíveis e não repetitivos, comparado a um gerador determinístico.
    Essa linha cria uma instância de random_device chamada rd.*/
    random_device rd; //substitui time(nullptr) em gen( time(nullptr) ) => gen( rd )

    /* é uma implementação de um gerador de números pseudoaleatórios do tipo Mersenne Twister, que é
    amplamente utilizado devido à sua alta qualidade de aleatoriedade e desempenho rápido.
    Este gerador precisa de uma semente para iniciar sua sequência de números pseudoaleatórios,
    e aqui ele está sendo semeado com o valor gerado por rd. Isso ajuda a garantir que as sequências
    de números gerados sejam diferentes a cada execução do programa. */
    mt19937 gen(rd());

    /* é uma classe que modela uma distribuição de probabilidade uniforme. Neste caso, ela está configurada
    para distribuir inteiros de forma uniforme entre 0 e tamanho - 1 (inclusive). Isso significa que qualquer
    número inteiro dentro desse intervalo tem igual probabilidade de ser escolhido cada vez que um número
    é gerado usando esta distribuição. */

    std::uniform_int_distribution<> dis(0, tamanho - 1); //em tamanho = 10
    //uniform_int_distribution<mt19937::result_type> dis(0, tamanho - 1); //em tamanho = 10 //especifica explicitamente que o tipo de dados usado pela distribuição é o mesmo tipo de resultado que o gerador de números pseudoaleatórios

    //MAIN
    int cont = 0;
    while(cont != 20)
    {
    int i = dis(gen);
    std::cout << i << std::endl;
    cont ++;
    }
}