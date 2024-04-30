/*
Implementar uma classe Matriz 2x2 que inclua um construtor por default
funções de acesso para acessar os atributos da matriz
uma função inversa(), que devolve o inverso da matriz,
uma função det() que devolve o determinante da matriz
uma função visualizar.
*/

#include <iostream>
using std::cout;
using std::endl;

class Matriz_2x2
{
    private:
    double matriz[2][2];

    public:
    double det();
    void inversa();
    void visualizar();

    Matriz_2x2()
    {
        matriz[0][0] = 0;
        matriz[0][1] = 0;
        matriz[1][0] = 0;
        matriz[1][1] = 0;
    }
    Matriz_2x2(double a10, double a11, double a20, double a21)
    {
        matriz[0][0] = a10;
        matriz[0][1] = a11;
        matriz[1][0] = a20;
        matriz[1][1] = a21;
    }
};

double Matriz_2x2::det()
{
    double det = matriz[0][0]*matriz[1][1] - (matriz[0][1]*matriz[1][0]);
    return det;
}

void Matriz_2x2::inversa()
{
    if (det()>=0)
    {
        double aux;
        aux = matriz[0][0];
        matriz[0][0] = (1/det())*matriz [1][1];
        matriz [1][1] = (1/det())*aux;

        matriz[0][1] = matriz[0][1] * (-1) * (1/det());
        matriz[1][0] = matriz[1][0] * (-1) * (1/det());
    }
    else { std::cerr << "Nao ha inversa" << endl;}
}

void Matriz_2x2::visualizar()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }   
}

int main()
{
    Matriz_2x2 m(1,0,0,1);
    m.visualizar();
    m.inversa();
    m.visualizar();
    return 0;
}