#include "Implementation.h"
#include "Interface.h"
#include <iostream>
using std::cout;
using std::endl;

Interface::Interface(int v) : ptr(new Implementation(v)){} //inicializa o ponteiro para apontar para um novo objeto implementation
void Interface::setValue(int v)
{
    ptr->setValue(v);
}

int Interface::getValue() const
{
    return ptr->getValue();
}

Interface::~Interface()
{
    delete ptr;
}

int main()
{
    Interface i(5);
    cout << i.getValue();
}