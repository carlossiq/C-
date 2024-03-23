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
    char cod[5];
    char nome[51];
    char CPF[12];
 };

struct node_Aluno
{
    data_Aluno data;
    node_Aluno *next;
};


/* Disciplina : 5 Campos*/
struct node_Disciplina
{
    char cod[6];
    char nome[51];
    char professor[51];
    int credito;
    node_Disciplina *next;
};

/* Relações de Matrícula por período : 5 Campos*/
struct node_Matricula
{
    int periodo;
    char cod1[5];
    char cod2[6];
    node_Matricula *next;
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
    system("cls");
    cout << PRESENT << " "; show_time();
}

void clean()
{
    getchar();
    fflush(stdin);
    system("cls");            
}

/* Classe de funções com inserção de dados com sobrecarga de funções*/
class Data_In
{
    public:
        void newline(node_Aluno *&lista)
        {
            title();
            cout << "Cadastro de Alunos" << endl;
            cout << "Insira abaixo o Codigo, Nome e o CPF." << endl;
            char codigo[5]; char nome[51]; char CPF[12];
            cout << "Codigo: " << endl;
            cin >> codigo;
            cout << "Nome: " << endl;
            cin >> nome;
            cout << "CPF: " << endl;
            cin >> CPF;

            line(*&lista, codigo, nome, CPF);

            title();
            cout << endl << "Aluno inserido com sucesso!";
            clean();
        }

        /* Carrega o arquivo binário na memória*/
        void open(const char* arq_bin, node_Aluno *&lista_aluno, node_Disciplina* lista_dis, node_Matricula* lista_mat)
        {
            inicialize(arq_bin);
            if (tipo==1)
            {   
                data_Aluno auxiliar;
                arquivo.open(arq_bin, ios::out | ios::binary);
                arquivo.seekg(sizeof(int));
                while(arquivo.read(reinterpret_cast<char*>(&auxiliar),sizeof(auxiliar)))
                {   
                    line(*&lista_aluno, auxiliar.cod, auxiliar.nome, auxiliar.CPF);
                }
                
                arquivo.close();
                clean();
            }
    }

    private:
        int tipo;
        ifstream arquivo;
    
        void inicialize(const char* arq_bin)
        {
            arquivo.open(arq_bin, ios::out | ios::binary);
            if (!arquivo.is_open())
            {   
                title();
                cerr << "Erro ao abrir o arquivo." << endl;
                clean();
                return;
            }
            arquivo.read(reinterpret_cast<char*>(&tipo), sizeof(int));
            arquivo.close();
        }

        /*Cria novos nos para Alunos com passagem por referência*/
        void line(node_Aluno *&lista, char cod[], char nome[], char CPF[])
        {
            node_Aluno* node = new node_Aluno();

            strcpy(node->data.cod,cod);
            strcpy(node->data.nome,nome);
            strcpy(node->data.CPF,CPF);
            node->next = nullptr;

            if(lista == nullptr)
            {
                lista = node;
                return;
            }
            
            node_Aluno *aux = lista;
            while(aux->next != nullptr)
            {
                aux = aux->next;
            }
            aux->next = node;    
        }
};

/* Classe de funções de remoção de dados com sobrecarga de funções*/

/* Classe de funções leitura e busca das estruturas*/
class Data_Show
{
    public:
        /* Função sobrecarregada para imprimir os dados das listas de acordo com o tipo*/    
        void print_list(node_Aluno* lista)
        {   
            title();
            if(lista == nullptr)
            {
                cout << "Nao ha alunos cadastrados.";
                clean();

            }
            else
            {
                //cout << "----------------------------------------------------------------------------------"<< endl;
                while(lista != nullptr)
                {
                    cout << setw(4) << lista->data.cod << setw(20) << lista->data.nome << setw(12) << lista->data.CPF << endl;
                    lista = lista->next;
                }
                //cout <<endl;
                //cout << "----------------------------------------------------------------------------------"<< endl;
                cout << endl;
                cout << "Pressione qualquer tecla para continuar..." << endl;
                clean();
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
    void save(node_Aluno* lista)
    {
            
        int tipo = 1;
        out_arquivo.open(AL, ios::out | ios:: binary | ios::trunc);//ate (posição final) //app escritas no final //tellp posição atual
        out_arquivo.write(reinterpret_cast<const char*>(&tipo), sizeof(int));
        data_Aluno auxiliar;        

        while(lista != nullptr)
        {   
            strcpy(auxiliar.cod, lista->data.cod);
            strcpy(auxiliar.nome, lista->data.nome);
            strcpy(auxiliar.CPF, lista->data.CPF);
            out_arquivo.write(reinterpret_cast<const char*>(&auxiliar), sizeof(auxiliar));          
            lista = lista->next;
        }
        title();
        cout <<"Arquivo salvo com sucesso!";
        out_arquivo.close();
            

        clean();
    }
    private:
    ofstream out_arquivo;

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
            cout << "[3] - Matricular Aluno" << endl;
            cout << "[4] - Listar Alunos" << endl;
            cout << "[5] - Listar Disciplinas" << endl;
            cout << "[6] - Busca por Aluno" << endl;
            cout << "[7] - Busca por Disciplina" << endl;
            cout << "[8] - Salvar" << endl;
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
    node_Aluno *lista_aluno = nullptr;
    node_Disciplina *lista_disciplina = NULL;
    node_Matricula *lista_matricula = NULL;
       
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
            sh.print_list(lista_aluno);
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
        
        case 0:
            in.open(AL, lista_aluno, lista_disciplina, lista_matricula);
            break;
        }
    }
    return 0;
}