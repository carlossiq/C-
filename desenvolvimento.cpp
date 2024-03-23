#include <iostream>
using std::cout;
using std::cin;
using std::ios;
using std::endl;

#include <cstring>
#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::fstream;

#include <string.h>

 struct data_Aluno
 {
    char cod[5];
    char nome[30];
    char CPF[12];
 };

struct node_Aluno
{
    data_Aluno data;
    node_Aluno *next;
};

int main()
{
    /*int tipo = 1;
    ofstream arquivo;
    arquivo.open("alunos.bin", ios::out | ios::binary);
    arquivo.write(((char*)&tipo), sizeof(int));
    data_Aluno auxiliar;

    strcpy(auxiliar.cod,"0000");
    strcpy(auxiliar.nome,"carlos");
    strcpy(auxiliar.CPF,"14674901723");

    arquivo.write(((char*)&auxiliar), sizeof(auxiliar));
    arquivo.close();*/

    data_Aluno nova; int tipo_nova=0;
    ifstream arquivo_novo;
    arquivo_novo.open("alunos.bin", ios::out | ios::binary);
    arquivo_novo.read(reinterpret_cast<char*>(&tipo_nova), sizeof(tipo_nova));
    arquivo_novo.read(((char*)&nova), sizeof(data_Aluno));
    cout << tipo_nova << endl;
    cout << nova.nome << endl;
    return 0;
}