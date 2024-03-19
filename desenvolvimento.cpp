#include <iostream>
using std::cin;
using std::cout;
using std::ios;
using std::endl;

#include <fstream>
using std::ofstream;

#include <string>
using std::string;

#include <string.h>

/* Estruturas - 3 - Aluno, Disciplina, Matrícula */
/* Aluno */
struct data_Aluno
{
    char cod[5];
    char nome[51];
    char CPF[12];
};

/* Disciplina */
struct data_Disciplina
{
    string cod;
    string nome;
    string professor;
    int credito;
};

/* Relações de Matrícula */
struct data_Matricula
{
    int periodo;
    string cod1;
    string cod2;
};

/* Tipos a serem verificados na abertura do arquivo */
enum tipo {aluno=1, disciplina, matricula};

//rb+ - leitura e escrita (apaga o conteúdo caso o arquivo exista)

//função add aluno

data_Aluno aux;

int main()
{
    printf("Insira o codigo do aluno: ");
    char cod[5];
    scanf("%4[^\n]s", cod);
    strcpy(aux.cod,cod);

    printf("Insira o nome do aluno: ");
    char nome[51];
    scanf("%50[^\n]s", nome);
    strcpy(aux.nome,nome);
    
    printf("Insira o CPF do aluno: ");
    char cpf[51];
    scanf("%50[^\n]s", cpf);
    strcpy(aux.CPF,cpf);
    
    FILE *arquivo = fopen("alunos.dat","ab+");
    fseek(arquivo, sizeof(int), SEEK_SET);
    fwrite(aux.cod, sizeof(aux.cod), 1, arquivo);
    fwrite(aux.nome, sizeof(aux.nome), 1, arquivo);
    fwrite(aux.CPF, sizeof(aux.CPF), 1, arquivo);
    rewind(arquivo);
    return 0;
}