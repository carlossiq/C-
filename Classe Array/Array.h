#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include <cstdlib>


using namespace std;

class Array
{
    friend ostream& operator<<(ostream &, const Array&);                 //operador de inserção
    friend istream& operator>>(istream &, Array&);                     //extração

    private:
        int size;
        int *ptr;

    public:
        Array(int = 10);                                                //tamamho padrão do array
        Array(const Array &);                                           //construtor por cópia
        ~Array();

        int getSize() const;

        const Array& operator=(const Array&);
        bool operator==(const Array&) const;

        bool operator!=(const Array &right)
        {
            return !(*this == right);
        }

        int &operator[](int);
        int operator[](int) const;
};

Array::Array(int arraySize)
{
    size = (arraySize > 0 ? arraySize : 10);
    ptr = new int[size];
    for(int i = 0; i < size; i++) ptr[i] = 0;
}

Array::Array(const Array &copy) : size(copy.size)                       //recebe uma referência para evitar recursão infinita
{
    ptr = new int[size];
    for(int i = 0; i < size; i++) ptr[i] = copy.ptr[i];
}

Array::~Array()
{
    delete[] ptr;
}

int Array::getSize() const
{
    return size;
}

const Array& Array::operator=(const Array& right)                       //const evita (a = b) = c
{
    if(&right != this)                                                  //se eles foram iguais (mesmo espaço de memória) - evita auto-atribuição 
    {
        if(size != right.size)                                          //se tiverem tamanhos diferentes
        {
            delete[] ptr;                                               //desaloca a esquerda
            size = right.size;                                          //iguala o tamanho dos objetos
            ptr = new int[size];                                        //cria um novo espaço de memória 
        }
        for (int i = 0; i <  size; i++) ptr[i] = right.ptr[i];          //atribui os dados novos da direita à esquerda
    }
    return *this;                                                       //permite cascateamento do operador a = b = c;
}

bool Array::operator==(const Array& right) const
{
    //não significa que eles são iguais! mas que contém mesmo tamanho e os mesmos dados
    if(size != right.size) return false;
    for(int i = 0; i < size; i++)
    {
        if(ptr[i] != right.ptr[i]) return false;
    }
    return true;
}

//operador subscript para arrays não constantes
//a referencia retorna um lvalue modificável
//interador
int &Array::operator[] (int subscript)
{
    if(subscript < 0 || subscript >= size)
    {
        cerr << "\nError: Subscript " << subscript << " out of range" << endl;
        exit(1);
    }
    return ptr[subscript]; //retorna a referência
}

//operador subscript para arrays constantes (não podem ser modificador através de iterador, portanto sua cópia é modificada)
int Array::operator[] (int subscript) const
{
    if(subscript < 0 || subscript >= size)
    {
        cerr << "\nError: Subscript " << subscript << " out of range" << endl;
        exit(1);
    }
    return ptr[subscript]; //retorna cópia do elemento
}


ostream &operator<<(ostream &output, const Array &array)
{
    for(int i = 0; i < array.size; i++)
    {
        output << array.ptr[i];
        if(i < array.size - 1) output << " ";
    }
    return output;
}

istream& operator>>(istream &input, Array &array)
{
    for(int i = 0; i < array.size; i++) input >> array.ptr[i];
    return input;
}

#endif