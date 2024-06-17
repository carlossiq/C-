#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric> 
#include <stdexcept>
using namespace std;



class NumeroRacional
{

friend ostream& operator<<(ostream& output, const NumeroRacional& numero);
friend istream& operator>>(istream& input, NumeroRacional &numero);

private:
    int p;                                              //dividendo
    int q;                                              //divisor
    int mdc(int a, int b)                               //metodo que calcula o minimo miltiplo comum
    {
        if (b == 0) {
            return a;
        } else {
            return mdc(b, a % b);
        }
    }

public:
    NumeroRacional(){}                                  //construtor padrão
    NumeroRacional(int p,int q)
    {                                                   //construtor alternativo
        //se divisor for 0 retorna erro
        if (q==0)
        {
            throw runtime_error("Erro");
        }
        int divisor = mdc(p,q);
        p/=divisor;
        q/=divisor;
        this->p=p;
        this->q=q;
    }

    operator float()
    {
        return p/(float)q;
    }

    //sobrecarga da operação +
    NumeroRacional operator+(const NumeroRacional &n)
    {
        return NumeroRacional(p*n.q+q*n.p,q*n.q); 
    }
    
    //sobrecarga da operação /
    NumeroRacional operator/(const NumeroRacional &n)
    {
        return NumeroRacional(p*n.q, q*n.p);
    }

    //operador ++Numero
    NumeroRacional& operator++()
    {
        p += q;
        return *this;
    }

    //operador numero++
    NumeroRacional operator++(int)
    {
        NumeroRacional copia(*this);
        this->operator++();
        return copia;
    }

    const NumeroRacional& operator=(const NumeroRacional& numero)
    {
        p = numero.p;
        q = numero.q;
        return *this; 
    }

    bool operator==(const NumeroRacional& numero)
    {
        if(p != numero.p) return false;
        if(q != numero.q) return false;
        return true;
    }

    // void imprimir()
    // {
    //     if(q==1) cout << p << endl;
    //     else cout << p <<"/"<< q << endl;
    // }

};

ostream& operator<<(ostream& output, const NumeroRacional& numero)
{
    if(numero.q == 1) output << numero.p;
    else output << numero.p << "/" << numero.q;
    return output;
}

istream& operator>>(istream& input, NumeroRacional &numero)
{
    char c;
    input >> numero.p >> c >> numero.q;
    if (c != '/') throw runtime_error("Erro");
    else
    {
        int divisor = numero.mdc(numero.p,numero.q);
        numero.p/=divisor;
        numero.q/=divisor;
    }
    return input;
}

int main(){
    NumeroRacional n1(-3,-5);
    NumeroRacional n2(3,5);
    // float f = n1;
    // cout << f << endl;
    // cout << n1 << endl; //a sobrecarga do float permite a impressão sem a função do cout
    // cout << n1 << endl;
    // NumeroRacional n3;
    // cin >> n3;
    // NumeroRacional n4;
    // n4 = n3;
    // cout << ++n4;
    // if(n1 == n2) cout << "ok";
    // else cout << "not ok";
}