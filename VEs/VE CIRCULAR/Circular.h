/*
2. (5,0) Um buffer circular é uma estrutura de dados que usa um único buffer de tamanho fixo como se
estivesse conectado de ponta a ponta. Essa estrutura se presta facilmente ao buffer de fluxos de dados.
Assim, um algoritmo de leitura que leia a última posição do buffer e necessite continuar lendo irá
retornar ao início do buffer e proceder a leitura a partir daí. O mesmo vale para algoritmos de escrita,
sendo que a escrita numa posição não-vazia não é possível. Implemente uma classe para lidar com
buffers circulares que contenha:

a) (1,5) classes, construtor(es), destrutor(es) e atributo(s) necessários. Obrigatoriamente utilize a
alocação dinâmica;
b) (1,0) métodos que retornam se o buffer está cheio ou vazio;
c) (1,5) método de inserção que verifica antes de inserir se o buffer está cheio;
d) (1,0) método de remoção.
Obs: os dados não devem mudar de posição após as operações de inserção e remoção
*/

#ifndef CIRCULAR_H
#define CIRCULAR_H

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

#include <cmath>

class EstruturaBase
{
    private:
    size_t arrayMaxSize;                        //espaços do vetor
    size_t arraySize;                           //numero de elementos
    size_t arrayBegin;                          //inicio
    size_t arrayEnd;                            //fim
    int *array;                                 //poteiro para o endereço de memória a ser criado dinamicamente

    size_t getMaxSize() const;                  //retorna o espaço do vetor
    bool full();
    bool empty();
    
    public:
    void push(int);                             //insere o elemento no fim
    size_t size() const;                        //retorna o numero de elementos
    size_t begin() const;                       //retorna o inicio
    size_t end() const;                         //retorna o fim

    void info();                                //retorna todas as informações do array
    void pop();

    EstruturaBase(int);                            //construtor default
    EstruturaBase(initializer_list<int>);       //construtor para uma dada lista
    EstruturaBase(const EstruturaBase&);        //construtor por cópia

    ~EstruturaBase(){ delete[] array;}          //destrutor
};

using E0 = EstruturaBase;

//MÉTODOS BASE
size_t E0::getMaxSize() const
{
    return arrayMaxSize;
}

size_t E0::size() const
{
    return arraySize;
}

size_t E0::begin() const
{
    return arrayBegin;
}

size_t E0::end() const
{
    return arrayEnd;
}

void E0::push(int valor)
{
    if(!full())
    {
        arraySize++;
        arrayEnd = arrayBegin + arraySize;
        array[arrayEnd - 1] = valor;                                    //insere de fato o valor no array;
        arrayEnd = arrayEnd % arrayMaxSize;
    }
    else cout << "Cheio" << endl;
}

void E0::pop()
{
    if(!empty())
    {
        arraySize--;
        arrayBegin++;
        arrayBegin = arrayBegin % arrayMaxSize;
    }
    else cout << "Vazio" << endl;
}

void E0::info()
{
    cout << left;
    cout << setw(22) << "Tamanho maximo: " << arrayMaxSize << endl;
    cout << setw(22) << "Numero de elementos: " << arraySize << endl;
    cout << setw(22) << "Inicio: " << arrayBegin << endl;
    cout << setw(22) << "Fim: " << arrayEnd << endl;
    if(arraySize != 0)
    {
        cout << setw(22) << "Array: ";
        for(size_t i = arrayBegin; i < arrayBegin + arraySize; i++) cout << array[i % arraySize] << " ";
        cout << endl;
    } else cout << setw(22) << "Array: " << "Vazio";
    
}

bool E0::full()
{
    if(arrayMaxSize == arraySize) return true;
    else return false;
}

bool E0::empty()
{
    if(arraySize == 0) return true;
    else return false;
}
//CONSTRUTORES BASE
E0::EstruturaBase(int size) : arrayMaxSize(size), arraySize(0), arrayBegin(0), arrayEnd(0)
{
    array = new int[arrayMaxSize];
}

E0::EstruturaBase(initializer_list<int> lista) : arraySize(lista.size()), arrayBegin(0), arrayEnd((size_t)lista.end()), array(new int[arrayMaxSize])
{
    arrayMaxSize = (size_t)lista.size();
    array = new int[arrayMaxSize];
    copy(lista.begin(), lista.end(), array);
}

E0::EstruturaBase(const EstruturaBase& lista) : arrayMaxSize(lista.arrayMaxSize), arraySize(lista.arraySize), arrayBegin(lista.arrayBegin), arrayEnd(lista.arrayEnd), array(nullptr)
{
    if(lista.array != nullptr)
    {
        array = new int[arrayMaxSize];
        copy(lista.array, lista.array + lista.arraySize, array);
    }
}


#endif