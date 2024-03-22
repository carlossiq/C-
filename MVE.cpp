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

Cada arquivo terá dois inteiros na sua inicialização:
Tipo (1 - Aluno; 2 - Disciplina, 3 - Matrícula)
Quantidade de estruturas contidas;
*/

#include <iostream>
using std::cin;
using std::cout;
using std::ios;
using std::endl;
using std::cerr;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <cstdlib>
using std::exit;

#include <iomanip>
using std::setw;

//#include <vector>

#include <windows.h>

#define PRESENT "SISTEMA DE CADASTRO UNIVERSITARIO"
#define AL "alunos.dat"
#define DIS "disciplinas.dat"
#define MAT "matriculas.dat"

/* Estruturas - 3 - Aluno, Disciplina, Matrícula ::  Listas encadeadas */

/* Aluno : 4 Campos*/
struct data_Aluno
{
    string cod;
    string nome;
    string CPF;
    data_Aluno *next;
};

/* Disciplina : 5 Campos*/
struct data_Disciplina
{
    string cod;
    string nome;
    string professor;
    int credito;
    data_Disciplina *next;
};

/* Relações de Matrícula por período : 5 Campos*/
struct data_Matricula
{
    int periodo;
    string cod1;
    string cod2;
    data_Matricula *next;
};

/* Mostra o dia no sistema */
void show_time()
{
    SYSTEMTIME time;
    GetSystemTime(&time);
    cout << time.wDay << "/" << time.wMonth << "/" << time.wYear << endl << endl;
}

void title()
{
    cout << PRESENT << " "; show_time();
}

void clean()
{
    getchar();
    fflush(stdin);
    system("cls");            
}

/* Classe de funções de inserção de dados com sobrecarga de funções*/
class Data_In
{
    public:
        data_Aluno* begin_Al()
        {
            return line(NULL, "", "", "");
        }
               

        void newline(data_Aluno* lista)
        {
            system("cls");
            title();
            cout << "Cadastro de Alunos" << endl;
            cout << "Insira abaixo o Codigo, Nome e o CPF." << endl;
            string codigo, nome, CPF;
            cout << "Codigo: " << endl;
            getline(cin,codigo);
            cout << "Nome: " << endl;
            getline(cin,nome);
            cout << "CPF: " << endl;
            getline(cin,CPF);

            line(lista, codigo, nome, CPF);

            cout << endl << "aluno inserido com sucesso!";
            getchar();
            system ("cls");
        }

        /* Carrega o arquivo binário na memória*/
        void chargelines (string nome_arquivo)
        {
            ofstream arquivo(nome_arquivo, ios::out | ios:: binary);
        }

    private:
        data_Aluno* line(data_Aluno* aluno, string cod, string nome, string CPF)
        {
    
            data_Aluno* node = new data_Aluno;

            node->next=NULL;
            node->cod=cod;
            node->nome=nome;
            node->CPF=CPF;

            if(aluno)
            {
                aluno->next=node;
            }

            return aluno ? aluno : node; 
        }
};

/* Classe de funções de remoção de dados com sobrecarga de funções*/

/* Classe de funções leitura e busca das estruturas*/
class Data_Show
{
    public:
        /* Função sobrecarregada para imprimir os dados das listas de acordo com o tipo*/    
        void list(data_Aluno* lista)
        {   
            system("cls");
            if(lista->next == NULL)
            {
                cout << "Nao ha alunos cadastrados.";
                clean();

            }
            else
            {
                cout << "----------------------------------------------------------------------------------"<< endl;
                while(lista != NULL)
                {
                    cout << setw(4) << lista->cod << setw(20) << lista->nome << setw(12) << lista->CPF << endl;
                    lista = lista->next;
                }
                cout <<endl;
                cout << "----------------------------------------------------------------------------------"<< endl;
                cout <<endl;
            }
        }
            
    private:
};

class Data_Search
{
    public:
};

/* Classe de funções salvamento*/    
class Data_Save
{
    public:
    void save(data_Aluno* lista)
    {
            
        int tipo = 1;
        ofstream arquivo(AL, ios::out | ios:: binary | ios::trunc);//ate (posição final) //app escritas no final //tellp posição atual
        arquivo.write(reinterpret_cast<const char*>(&tipo), sizeof(int));
        while(lista != NULL)
        {
            arquivo.write(reinterpret_cast<const char*>(lista), sizeof(data_Aluno));
            lista = lista->next;
        }
        arquivo.close();
            

        clean();
    }

};

/* Classe de funções carregamento de arquivos*/
class Data_Charge
{
    public:
    void type()
    {
        int tipo;
        ifstream arquivo(AL, ios::out | ios:: binary);
        arquivo.read(reinterpret_cast<char*>(&tipo), sizeof(int));
    }
    
};


/*Classe menu de opções*/
enum tipo {cadastrar_aluno=1, cadastrar_disciplina, matricular, listar_aluno, listar_disciplina, busca_aluno, busca_dis, salvar, sair };

class Menu
{
    public: 
        void display()
        {
            title();
            cout << "[1] - Cadastrar Aluno" << endl;
            cout << "[2] - Cadastrar Disciplina" << endl;
            cout << "[3] - Matricular Aluno" << endl << endl;
            cout << "[4] - Listar Alunos" << endl << endl;
            cout << "[5] - Listar Disciplinas" << endl << endl;
            cout << "[6] - Busca por Aluno" << endl << endl;
            cout << "[7] - Busca por Disciplina" << endl << endl;
            cout << "[8] - Salvar" << endl << endl;
            cout << "[9] - Sair" << endl << endl;
            cout << "Digite a opcao acima: ";
        }

        /*Obtém a opção do switch*/
        int get_op()
        {
            display();
            cin >> operador; fflush(stdin);
            return operador;
        }

    private:
        int operador; 
};

int main()
{   
    /*Classe de funções*/
    Menu menu;
    Data_Show sh;
    Data_In in;
    Data_Save sv;
    
    /*Alocação dinâmica das listas encadeadas*/
    data_Aluno *lista_aluno = in.begin_Al();
       
    /*carregando arquivos*/
    
    /*Menu*/
    while (1)
    {           
        switch (menu.get_op())
        {
        case cadastrar_aluno:
            in.newline(lista_aluno);
            break;

        case cadastrar_disciplina:
            
            break;
        
        case matricular:
            
            break;

        case listar_aluno:
            sh.list(lista_aluno);
            break;
        
        case listar_disciplina:
            
            break;
        
        case busca_aluno:
            
            break;
        
        case busca_dis:
            
            break;
        
        case salvar:
            sv.save(lista_aluno);
            break;
        
        case sair:
            exit(1);
            break;
        
        default:
            break;
        }
    }
    return 0;
}