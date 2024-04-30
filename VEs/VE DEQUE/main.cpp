#include "Deque.h"
#include "Fila.h"

int main()
{
    Deque a(6);
    a.push(10, retaguarda);
    Deque b(a);
    b.push(20, retaguarda);
    b.push(30, retaguarda);
    b.push(40, retaguarda);
    b.push(50, retaguarda);
    b.push(60, retaguarda);
    //b.print();
    Deque c(b);
    c.pop(frente);
    c.push(100, frente);
    c.pop(retaguarda);
    c.push(600, retaguarda);
    //c.print();

    Fila d(c);
    d.print();
    d.pop();
    d.print();
    d.pop();
    d.print();
    d.pop();
    d.print();
    d.push(99);
    d.print();


}