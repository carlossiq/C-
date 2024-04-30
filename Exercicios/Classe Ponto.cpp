/*
-Implementar uma classe Ponto que represente pontos em três dimensões (x, y e z).
-Incluir um construtor por default, um construtor alternativo;
-Uma função oposto(), que transforme o ponto em seu oposto
-Uma função distância que devolve a distância do ponto a origem (0,0,0)
-Uma função visualizar()
*/

#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

class Ponto
{
    private:
    double x;
    double y;
    double z;

    public:
    double getX();
    double getY();
    double getZ();

    public:
    double distanciaOrigem();
    void visualizar();
    void oposto();

    Ponto():x(0),y(0),z(0){}
    Ponto(double X, double Y, double Z):x(X), y(Y), z(Z){}
    ~Ponto(){};
};

double Ponto::getX() { return x; }
double Ponto::getY() { return y; }
double Ponto::getZ() { return z; }

double Ponto::distanciaOrigem()
{
    return (sqrt(x*x + y*y + z*z));
}

void Ponto::oposto()
{
    x = -x;
    y = -y;
    z = -z;
}

void Ponto::visualizar()
{
    cout << "Coordenada X = " << getX() << endl;
    cout << "Coordenada Y = " << getY() << endl;
    cout << "Coordenada Z = " << getZ() << endl;
    cout << "A distancia ate a origem e " << distanciaOrigem() << endl << endl;
}

int main()
{
    Ponto p1;
    p1.visualizar();
    Ponto p2(5,10,9);
    p2.oposto();
    p2.visualizar();
    return 0;
}