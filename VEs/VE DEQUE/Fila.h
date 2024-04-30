/*
(d) (2,0) Implemente também uma classe derivada do deque que lide com filas, uma fila é um
caso mais específico do deque que somente permite a inserção na retaguarda e a remoção na
frente. Limite a sua classe para que ela não possa fazer as operações incorretas nessa nova
estrutura
*/

#ifndef FILA_H
#define FILA_H

#include "Deque.h" 

class Fila : public Deque

{
    public:
    void push(int);
    void pop();
    Fila (int number) : Deque (number){};
    Fila (const Deque& list) : Deque (list){};

};

void Fila::push(int value)
{
    pushBack(value);
}

void Fila::pop()
{
    popFront();
}

#endif