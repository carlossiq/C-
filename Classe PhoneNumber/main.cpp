#include "Phone.h"

int main()
{
    PhoneNumber phone;
    std::cout << "Enter the phone number in the form (xx) xxxx - xxxx:" << std::endl;
    std::cin >> phone;

    std::cout << "The phone is: " << phone << std::endl;
    
    return 0;
}