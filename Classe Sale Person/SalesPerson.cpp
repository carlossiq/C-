#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include "SalesPerson.h"

//construtor
SalesPerson::SalesPerson()
{
    for (int i = 0; i < 12; i++)
    {
        sales[i] = 0.0; 
    }    
}

void SalesPerson::getSalesFromUser()
{
    double salesFigure;
    for (int i = 1; i <= 12; i++)
    {
        cout << "Digite a quantidade de vendas por mes " << i << ": ";
        cin >>salesFigure;
        setSales(i, salesFigure);
    }    
}

void SalesPerson::setSales(int mes, double quantidade)
{
    if (mes >= 1 && mes <= 12 && quantidade > 0) {sales[mes - 1] = quantidade;}
    else {cout << "Mes ou vendas invalidos." << endl;}
}

double SalesPerson::totalAnnualSales()
{
    double total = 0.0;
    for (int i = 0; i < 12; i++)
    {
        total += sales[i];
    }
    return total;
}

int main()
{
    SalesPerson s;

    s.getSalesFromUser();
    s.printtAnnualSales();
    return 0;
}