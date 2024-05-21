#ifndef NOME_H
#define NOME_H

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

//implemente duas classes de estrutura sem tamanho definido: inserem no fim, porem uma retira no fim e a outra retira no início,
//com alocação dinâmica
class EstruturaBase
{
    protected:
    size_t arrayMaxSize;                        //espaços do vetor
    size_t arraySize;                           //numero de elementos
    size_t arrayBegin;                          //inicio
    size_t arrayEnd;                            //fim
    int *array;                                 //poteiro para o endereço de memória a ser criado dinamicamente

    size_t getMaxSize() const;                  //retorna o espaço do vetor
    int maximize(int);                          //retorna a proxima potência de 2
    bool minimize(int);                         //verifica se o tamanho é uma potência de a fim de minimizar o vetor

    private:
    // Método para acessar um elemento com segurança
    int& operator[](size_t index) {
        if (index >= arraySize) {
            throw std::out_of_range("Index out of range");
        }
        return array[arrayBegin + index];  // Ajustar pelo arrayBegin se necessário
    }

    // Método const para acessar um elemento sem modificar
    const int& operator[](size_t index) const {
        if (index >= arraySize) {
            throw std::out_of_range("Index out of range");
        }
        return array[arrayBegin + index];
    }

    public:
    void push(int);                             //insere o elemento no fim
    size_t size() const;                        //retorna o numero de elementos
    size_t begin() const;                       //retorna o inicio
    size_t end() const;                         //retorna o fim

    void info();                                //retorna todas as informações do array

    EstruturaBase();                            //construtor default
    EstruturaBase(initializer_list<int>);       //construtor para uma dada lista
    EstruturaBase(const EstruturaBase&);        //construtor por cópia

    ~EstruturaBase(){ delete[] array;}          //destrutor
};

class EstruturaDerivada1 : public EstruturaBase
{
    public:
    EstruturaDerivada1() : EstruturaBase (){}
    EstruturaDerivada1(initializer_list<int> lista) : EstruturaBase (lista){}
    EstruturaDerivada1(const EstruturaBase& lista) : EstruturaBase (lista){}

    void pop();
};

class EstruturaDerivada2 : public EstruturaBase
{
    public:
    EstruturaDerivada2() : EstruturaBase (){}
    EstruturaDerivada2(initializer_list<int> lista) : EstruturaBase (lista){}
    EstruturaDerivada2(const EstruturaBase& lista) : EstruturaBase (lista){}

    void pop();
};

using E0 = EstruturaBase;
using E1 = EstruturaDerivada1;
using E2 = EstruturaDerivada2;

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

int E0::maximize(int x)
{
    if((x > 0) && ((x & (x - 1)) == 0)) // Verifica se x é uma potência de 2
    {
        return x;
    } else
        {
            if(x < 1) return 1;
            return (int)std::pow(2, ((int)std::ceil(std::log2(x)))); //proxima potencia de 2
        }
}

bool E0::minimize(int x)
{
    {
        if((x > 0) && ((x & (x - 1)) == 0)) return true; //verifica se potência de 2
        else return false;
    }
}

void E0::push(int valor)
{
    arrayEnd++;
    arraySize = arrayEnd - arrayBegin;
    arrayMaxSize = maximize(arraySize);                             //aumentar o tamanho do vetor para o dobro de elementos
    int *newArray = new int[arrayMaxSize];                          //cria um novo espaço de memória
    if(array !=  nullptr)                                           
    {
        copy(array + arrayBegin, array + arraySize, newArray);      //copia os valores do vetor antigo != nullptr
        delete[] array;                                             //libera a memória do array anterior caso não seja o primeiro elemento
    }
    array = newArray;                                               //atribui o novo espaço de memória ao atributo array da classe base
    array[arrayEnd - 1] = valor;                                    //insere de fato o valor no array;
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
        for(size_t i = arrayBegin; i < arrayEnd; i++) cout << array[i] << " ";
        cout << endl;
    } else cout << setw(22) << "Array: " << "Vazio";
    
}

//CONSTRUTORES BASE
E0::EstruturaBase() : arrayMaxSize(0), arraySize(0), arrayBegin(0), arrayEnd(0), array(nullptr){}

E0::EstruturaBase(initializer_list<int> lista) : arraySize(lista.size()), arrayBegin(0), arrayEnd((size_t)lista.end()), array(new int[arrayMaxSize])
{
    arrayMaxSize = maximize(lista.size());
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

//METODO CLASSE DERIVADA 1: RETIRA NO FIM;

void E1::pop()
{
    arrayEnd--;
    arraySize = arrayEnd - arrayBegin;
    if(arraySize == 0)
    {
        delete[] array;
        array = nullptr;
    }
    else if(minimize(arraySize))                     //diminuindo o array se ele chegar a uma potencia de dois
         {
             arrayMaxSize = arraySize;
             int *newArray = new int[arrayMaxSize]; 
             copy(array + arrayBegin, array + arrayEnd, newArray);
             delete[] array;
             array = newArray;
         }
}

//METODO CLASSE DERIVADA 1: RETIRA NO INICIO;

void E2::pop()
{
    arrayBegin++;
    arraySize = arrayEnd - arrayBegin;
    if(arraySize == 0)
    {
        delete[] array;
        array = nullptr;
        arrayBegin--;
        arrayEnd--;
    }
    else if(minimize(arraySize))                     //diminuindo o array se ele chegar a uma potencia de dois
         {
             arrayMaxSize = arraySize;
             int *newArray = new int[arrayMaxSize]; 
             copy(array + arrayBegin, array + arrayEnd, newArray);
             delete[] array;
             array = newArray;
             arrayBegin--;
             arrayEnd--;
         }
}


//para evitar copia dos arrays é necessário desativar o construtor por cópia e o operador (assignment operator)
//Array(const Array&) = delete;
//Array& operator=(const Array&) = delete;
#endif