#include <iostream>
using std::cout;
using std::cin;
using std::ios;
using std::endl;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::fstream;

 struct data_Aluno
 {
    string cod;
    string nome;
    string CPF;
 };

struct node_Aluno
{
    data_Aluno data;
    node_Aluno *next;
};

int main()
{
    data_Aluno nova; int tipo_nova=0;
    ifstream arquivo_novo;
    arquivo_novo.open("alunos.bin", ios::out | ios::binary);
    arquivo_novo.read(((char*)&tipo_nova), sizeof(tipo_nova));
    arquivo_novo.read(((char*)&nova), sizeof(data_Aluno));
    cout << tipo_nova << endl;
    cout << nova.nome << endl;
    return 0;
}