#include <iostream>
#include <string>
using std::string;

enum Key{off = 0, on};
class Vehicle
{
    private:
    string model;
    int key;

    public:
    static int count;
    Vehicle (string model) : model(model), key(off)
    {
        count++;
    } //operador de inicialização : membros constantes devem ser inicializador assim
    //métodos constantes podem ser chamados por objetos constantes!!!!

    void turn(Key on_off)
    {
        key = on_off;
    }

    void info() const
    {
        string message;
        if(key == on) message = "on";
        else message = "off";
        std::cout << "The vehicle " << model << " is " << message << "." << std::endl;
    }

    static int getCount()
    {
        return count;
    }
};

int Vehicle::count = 0;

class Car : public Vehicle
{
    public:
    Car (string model) : Vehicle(model){}
};

int main()
{   
    const Car Onix1("Onix 2028"); //const garante que o objeto não pode ser alterado, qualquer tentativa de modificá-lo gera erro de compilação
    const Car Onix2("Onix 2029"); //const garante que o objeto não pode ser alterado, qualquer tentativa de modificá-lo gera erro de compilação
    //Onix.turn(on);
    //Onix.turn(off);
    Onix1.getCount();
    return 0;
}