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
 };

struct node_Aluno
{
    data_Aluno data;
    node_Aluno *next;
};


/* Disciplina : 5 Campos*/
struct node_Disciplina
{
    string cod;
    string nome;
    string professor;
    int credito;
    node_Disciplina *next;
};

/* Relações de Matrícula por período : 5 Campos*/
struct node_Matricula
{
    int periodo;
    string cod1;
    string cod2;
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
        node_Aluno* begin_Al()
        {
            return line(NULL, "", "", "");
        }  

        void newline(node_Aluno* lista)
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

            title();
            system("cls");
            cout << endl << "Aluno inserido com sucesso!";
            clean();
        }

        /* Carrega o arquivo binário na memória*/
        void open(string arq_bin, node_Aluno* lista_aluno, node_Disciplina* lista_dis, node_Matricula* lista_mat)
        {
            inicialize(arq_bin);
            if (tipo==1)
            {   
                data_Aluno auxiliar;
                arquivo.open(arq_bin, ios::out | ios::binary);
                arquivo.seekg(sizeof(int));
                while(!arquivo.eof())
                {
                    arquivo.read(reinterpret_cast<char*>(&auxiliar),sizeof(data_Aluno));
                    cout << auxiliar.cod << endl;
                    cout << auxiliar.nome << endl;
                    cout << auxiliar.CPF << endl;
                    
                    //line(lista_aluno, auxiliar.cod, auxiliar.nome, auxiliar.CPF); contador++;
                }
                
                arquivo.close();
                clean();
            }
    }

    private:
        int tipo;
        ifstream arquivo;
    
        void inicialize(string arq_bin)
        {
            arquivo.open(arq_bin, ios::out | ios::binary);
            arquivo.read(reinterpret_cast<char*>(&tipo), sizeof(int));
            arquivo.close();
        }

        /*Cria novos nos para Alunos*/
        node_Aluno* line(node_Aluno* aluno, string cod, string nome, string CPF)
        {
            
            if (aluno && aluno->next) //vai para o final da lista de list e list.next forem diferentes de NULL
                return line(aluno->next, cod, nome, CPF); 
            node_Aluno* node = new node_Aluno;

            node->next=NULL;
            node->data.cod=cod;
            node->data.nome=nome;
            node->data.CPF=CPF;

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
        void list(node_Aluno* lista)
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
                    cout << setw(4) << lista->data.cod << setw(20) << lista->data.nome << setw(12) << lista->data.CPF << endl;
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
    void save(node_Aluno* lista)
    {
            
        int tipo = 1;
        out_arquivo.open(AL, ios::out | ios:: binary | ios::trunc);//ate (posição final) //app escritas no final //tellp posição atual
        out_arquivo.write(reinterpret_cast<const char*>(&tipo), sizeof(int));
        data_Aluno auxiliar;
        lista=lista->next;

        auxiliar.cod=lista->data.cod;
        auxiliar.nome=lista->data.nome;
        auxiliar.CPF=lista->data.CPF;

        out_arquivo.write(reinterpret_cast<const char*>(&auxiliar), sizeof(auxiliar));

        /*while(lista != NULL)
        {   
            auxiliar.cod=lista->data.cod;
            auxiliar.nome=lista->data.nome;
            auxiliar.CPF=lista->data.CPF;
            cout <<"verificando:"<< auxiliar.cod << "ok" << endl;
            cout <<"verificando:"<< auxiliar.nome << "ok" << endl;
            cout <<"verificando:"<< auxiliar.CPF << "ok" << endl;

            arquivo.write(reinterpret_cast<const char*>(&auxiliar), sizeof(data_Aluno));
            lista = lista->next;
        }*/

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
    node_Aluno *lista_aluno = in.begin_Al();
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
        
        case 0:
            in.open(AL, lista_aluno, lista_disciplina, lista_matricula);
            break;
        }
    }
    return 0;
}