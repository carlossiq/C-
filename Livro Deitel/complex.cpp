#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class Complex
{
    private:
    float real, imag;

    public:
    Complex (float real, float imag) : real(real), imag(imag) {}

    Complex &print()
    {
        cout << real << " + " << imag << "i" << endl;
        return *this;
    }

    friend Complex operator+ (Complex z1, Complex z2)
    {
        Complex sum(z1.real + z2.real, z1.imag + z2.imag);
        return sum;
    }

    float operator!(Complex z)
    {
        return 2*z.real + 3*z.imag;
    }
};

int main()
{
    Complex a(3,4);
    Complex b = a + a;
    cout << !a ;
}