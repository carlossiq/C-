#ifndef PHONE_H
#define PHONE_H

#include <iostream>
using std::ostream;
using std::istream;

#include <string>
using std::string;

#include <iomanip>
using std::setw;


class PhoneNumber
{
    friend ostream &operator<<(ostream &, const PhoneNumber &);         //função global ostream&
    friend istream &operator>>(istream &, PhoneNumber &);
    
    private:
    string areaCode;                    //DDD
    string exchange;                    //4dig
    string line;                        //4dig
    
};

ostream &operator<<(ostream &output, const PhoneNumber &number)
{
    output << "(" << number.areaCode << ") " << number.exchange << " - " << number.line;
    return output;
}

istream &operator>>(istream &input, PhoneNumber &number)
{
    input.ignore(); //pula
    input >> setw(2) >> number.areaCode;
    input.ignore(2);//pula
    input >> setw(4) >> number.exchange;
    input.ignore(3); //pula
    input >> setw(4) >> number.line;
    return input;
}
#endif