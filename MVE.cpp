/*
prazo 14/04 domingo
Confeccione um sistema de matrículas em disciplinas de uma faculdade:
Entidades mais importantes: Aluno e Disciplina
Aluno: código (5 dígitos), nome, CPF
Disciplina: código (4 dígitos), nome, professor, quatidade de créditos
O sistema deve ser capaz de armazenar uma lista de alunos e uma lista de disciplinas por periodo (2018.2)
Estruturas alocadas dinamicamente
Opções: Inserção, remoção (através de um menu de opções)
        Consultas das disciplinas de um aluno em um determinado periodo
        Consultas dos alunos que estão matriculados em uma disciplina em um determinado periodo
        Salvamento e recuperação dos dados entre sessão
Entregar arquivo (mínimo 3 alunos, disciplinas e alocações)
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "MVE.h" // funções de verificação


/* Estruturas - 3 - Aluno, Disciplina, Matrícula */
/* Aluno */
struct data_Aluno
{
    string cod;
    string nome;
    string CPF;
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
enum tipo {aluno=0, disciplina, matricula};

/* Classe de Funções*/
class MVE
{
    public:
    /*funções de arquivo automáticas*/
    void save();
    void open(FILE *ptr)
    {
        int tipo;
        fread(&tipo,sizeof(int),1,ptr);
        if(tipo==aluno){puts("Aluno");}
    };
    
    /*menu*/
    void menu();
    void insert();//disciplina, aluno, matricula
    void remove();//disciplina, aluno, matricula
    void list();//aluno->periodo->disciplina //disciplina->periodo->aluno

   /*inserir*/
   void get_al();
   void get_dis();
   void set_mat();
};


int main()
{   
    /*Classe de funções*/
    MVE mve;
    
    /*Declaração da Structs*/
    data_Aluno *Aluno=NULL;
    data_Disciplina *Disciplina=NULL;
    data_Matricula *Matricula=NULL;

    /*Alocação dinâmica*/
    Aluno = (data_Aluno*) malloc(sizeof(data_Aluno));
    Disciplina = (data_Disciplina*) malloc(sizeof(data_Disciplina));
    Matricula = (data_Matricula*) malloc(sizeof(data_Matricula));

    /*carregando arquivos*/
    FILE *arquivo1 = fopen("alunos", "rb");
    FILE *arquivo2 = fopen("disciplinas", "rb");
    FILE *arquivo3 = fopen("matriculas", "rb");
    mve.open(arquivo1);

    /*Menu*/
    int op;
    switch (op)
    {
    case 1:
        /*  */
        break;
    
    default:
        break;
    }

    return 0;
}