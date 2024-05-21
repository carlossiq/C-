#ifndef NOME_H
#define NOME_H

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


#include <cmath>

//CLASSE

//para evitar copia dos arrays é necessário desativar o construtor por cópia e o operador (assignment operator)
//Array(const Array&) = delete;
//Array& operator=(const Array&) = delete;
#endif