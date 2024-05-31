#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::copy;

#include <string>
using std::string;

class Empregado
{
    private:
    const string name;
    double salary;
    int ramal;

    static size_t counter;

    void error() const
    {
        if(counter >= 5) cout << "Lista cheia "<< counter << endl;
    }

    public:
    Empregado(string newName, double newSalary, int newRamal) : name(newName), salary(newSalary), ramal(newRamal)
    {
        error();
        counter++;
    }
    Empregado(string newName) : name(newName), salary(0), ramal(0)
    {
        error();
        counter++;
    }
    Empregado(const Empregado&)
    {
        error();
        counter++;
    }
    ~Empregado()
    {
        counter--;
    }

    //metodos
    string getName() const
    {
        return name;
    }
    
    double getSalary() const
    {
        return salary;
    }

    int getRamal() const
    {
        return ramal;
    }

    void setSalary(double newSalary)
    {
        salary = newSalary;
    }

    void setRamal(double newRamal)
    {
        ramal = newRamal;
    }

    static size_t getCounter()
    {
        return counter;
    } 
};

size_t Empregado::counter = 0;

int main()
{
    vector <Empregado> lista;
    lista.push_back(Empregado("Moises"));
    lista.push_back(Empregado("Moises"));


    cout << endl << Empregado::getCounter() << endl;

}