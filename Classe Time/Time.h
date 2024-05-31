//Impede multiplas inclusões de arquivo de cabeçalho
#ifndef TIME_H
#define TIME_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;                      //objeto string

#include <cstring>
using std::memcpy;                      //copia de elementos

#include <vector>
using std::vector;                      //objeto vector

#include <algorithm>                    //funcoes de busca
using std::find_if;                     //algoritmo de busca
using std::sort;                        //função com algoritmo de organização
using std::copy;

#include <cstdlib>
#include <ctime>        

#include <random>                       //geração de números aleatórios
using std::random_device;               //semente de números não determinísticos
using std::mt19937;                     //motor de geração gen(rd)
using std::uniform_int_distribution;    //probabilidade uniforme de inteiros

#include <initializer_list>             //lista de inicialização(permite utilizar uma lista como parâmetro)
using std::initializer_list;

#include <cassert>                      //verifica condições(como em um debug retornando true ou false) retornando erro

#include <iomanip>                      //formatação de entrada e saída de fluxos
using std::setw;                        //largura do campo de inserção
using std::setfill;                     //preenche o campo de inserção com um caractere ' '
using std::setbase;                     //base 10, 16, 8 ...
using std::setprecision;                //numero de digitos de presição de ponto flutuante
using std::left;                        //alinhamento a esquerda
using std::right;                       
using std::internal;

class Time
{
    private:
    int hour;
    int minute;
    int second;

    public:
    Time(int = 0, int = 0, int = 0);
    
    int getHour() const         { return hour;}
    int getMinute() const       { return minute;}
    int getSecond() const       { return second;}

    void printUniversal() const;
    void printStandard() const;

    //Time & permite cascateamento
    Time &setTime(int, int, int);
    Time &setHour(int);
    Time &setMinute(int);
    Time &setSecond(int);    
};

Time::Time(int hour, int min, int sec)
{
    setTime(hour, min, sec);
}

Time &Time::setTime(int hour, int min, int sec)
{
    setHour(hour);
    setMinute(min);
    setSecond(sec);
    return *this; //permite cascateamento
}
Time &Time::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0;
    return *this;
}
Time &Time::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0;
    return *this;
}
Time &Time::setSecond(int s)
{
    second = (s >= 0 && s < 60) ? s : 0;
    return *this;
}

void Time::printUniversal() const
{
    cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second << endl;
}
void Time::printStandard() const
{
    cout << (((hour == 12 || hour == 0) ? 12 : hour % 12)) << ":" << minute << ":" << second << (hour < 12 ? " AM" : " PM") << endl;
}

#endif