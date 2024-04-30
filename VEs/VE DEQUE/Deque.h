/*
1. (5,0) Um deque é uma estrutura de dados que permite a inserção e a remoção de informação
em ambos os extremos de uma lista. Normalmente um deque possui um tamanho fixo que não
pode ser extrapolado. Implemente uma classe para lidar com deques que armazenem valores do
tipo int e utilize alocação dinâmica. Você deve implementar:
(a) (1,0) um construtor cujo parâmetro é o tamanho máximo do deque e realize a alocação da
memória necessária, e o destrutor correspondente. Não se esqueça de implementar o construtor
por cópia.
(b) (1,5) métodos para inserção e remoção no deque dos valores. Os dois métodos devem
receber um parâmetro do tipo enum que define o local da operação (enum modoDeque
{frente=0, retaguarda}).
(c) (0,5) um método imprimir, que imprime todos os valores contidos no deque da frente para a
retaguarda.
(d) (2,0) Implemente também uma classe derivada do deque que lide com filas, uma fila é um
caso mais específico do deque que somente permite a inserção na retaguarda e a remoção na
frente. Limite a sua classe para que ela não possa fazer as operações incorretas nessa nova
estrutura
*/
#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <algorithm>

enum modoDeque {frente = 0, retaguarda};

class Deque
{
    protected:
    int max;
    int front;
    int back;
    int *array;

    //metodos auxiliares
    bool empty();
    bool full();
    bool exist(int);

    //metodos inserção
    void pushBack(int);
    void pushFront(int);

    //metodos de remoção
    void popBack();
    void popFront();

    public:
    //construtores
    Deque(int);
    Deque(const Deque&);
    
    //metodos pedidos
    void push(int, int);
    void pop(int);   
    void print();
};

bool Deque::empty()
{
    if(back == front) return true;
    else return false;
}

bool Deque::full()
{
    if(front - back == max) return true;
    else return false;
}

bool Deque::exist(int key)
{
    while(front <= back)
    {
        int medium = front + (back - front) / 2;
        if(array[medium] == key) return true;
        if(array[medium] < key)
        {
            front = medium + 1;
        }
        else
        {
            back = medium - 1;
        }
    }
    return false;
}

Deque::Deque(int tamanhoMaximo) : max(tamanhoMaximo), front(0), back(0)
{
    array = new int[tamanhoMaximo];
}

Deque::Deque(const Deque &lista) : max(lista.max), front(lista.front), back(lista.back)
{
    array = new int[max];
    std::copy(lista.array, lista.array + max, array); //copia o array inteiro    
}


void Deque::print()
{
    if(empty()) std::cout << "Lista vazia" << std::endl;
    else
    {
        for(int i = front-1; i >= back; i--)
        {
            std::cout << array[i] << " ";  
        }
        std::cout <<  std::endl;
    }
}


void Deque::pushBack(int value)
{
    if (full()) std::cout << "Lista cheia(" << value << ")" << std::endl;
    else
    {
        if (!empty())
        {
            for(int i = front; i > back; i--)
            {
                array[i] = array[i-1];
            }
        }
        array[back] = value;
        front++;
    }
}

void Deque::pushFront(int value)
{
    if (full()) std::cout << "Lista cheia(" << value << ")" << std::endl;
    else
    {
        array[front] = value;
        front++;
    }
}

void Deque::push(int value, int sw)
{
    if(sw == 0) pushFront(value);
    if(sw == 1) pushBack(value);
}

void Deque::popBack()
{
    if(empty()) std::cout << "Lista vazia" << std::endl;
    else
    {
        for(int i = back; i < front - 1; i++)
        {
            array[i] = array[i+1];
        }
        front--;
    }
}

void Deque::popFront()
{
    if(empty()) std::cout << "Lista vazia" << std::endl;
    else
    {
        front--;
    }
}

void Deque::pop(int sw)
{
    if(sw == 0) popFront();
    if(sw == 1) popBack();
}

#endif