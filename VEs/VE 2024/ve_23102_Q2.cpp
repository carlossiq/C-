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

class FuncionarioBase
{
    private:
    int id;                                     //identificador unico
    string name;                                //nome
    double salary;                              //salario
    string tipo;                                //funcao

    public:
    double getSalary(){ return salary;}
    string getTipo(){ return tipo;}
    FuncionarioBase (int id, string name, double salary, string tipo) : id(id), name(name), salary(salary), tipo(tipo){}

    void exibirDetalhes()
    {
        cout << "Id: " << id << endl;
        cout << "Nome: " << name << endl;
        cout << "Salario " << salary << endl;
        cout << "Funcao: " << tipo << endl << endl;
    }
};

class Funcionario : public FuncionarioBase
{
    public:
    Funcionario (int id, string name, double salary, string tipo) : FuncionarioBase(id, name, salary, tipo) {}

};
class Gerente : public FuncionarioBase
{
    private:
    vector<FuncionarioBase> equipe;

    public:
    Gerente (int id, string name, double salary) : FuncionarioBase(id, name, salary, "Gerente"){}
    void adicionarFuncionario (FuncionarioBase& func)
    {
        if(func.getTipo().compare("Gerente") == 0) cout << "Nao e possivel adicionar um gerente a equipe." << endl << endl;
        else if(equipe.size() < 10) equipe.push_back(func);
        else cout << "Equipe completa, nao e possivel mais adicionar ninguem." << endl << endl;
    }

    void mostrarTime()
    {
        cout << "TIME:" << endl;
        for(size_t i = 0; i < equipe.size(); i++)
        {
            equipe[i].exibirDetalhes();    
        }
    }

    double salarioTotal()
    {
        double sum = getSalary();
        for(size_t i = 0; i < equipe.size(); i++)
        {
            sum += equipe[i].getSalary();
        }

        return sum;
    }
};




int main()
{
    FuncionarioBase a(0, "Carlos", 1000.3, "caixa");
    FuncionarioBase b(a);
    FuncionarioBase c(a);
    FuncionarioBase d(a);
    FuncionarioBase e(a);
    FuncionarioBase f(a);
    FuncionarioBase g(a);
    FuncionarioBase h(a);
    FuncionarioBase i(a);
    FuncionarioBase j(a);
    FuncionarioBase k(a);

    Gerente gerente(10, "Gerente", 10000);
    Gerente gerente2(gerente);
    //gerente.exibirDetalhes();
    gerente.adicionarFuncionario(gerente2); //tentando adicionar gerente a equipe
    gerente.adicionarFuncionario(a);        //adicionando funcionario...
    gerente.adicionarFuncionario(b);
    gerente.adicionarFuncionario(c);
    gerente.adicionarFuncionario(d);
    gerente.adicionarFuncionario(e);
    gerente.adicionarFuncionario(f);
    gerente.adicionarFuncionario(g);
    gerente.adicionarFuncionario(h);
    gerente.adicionarFuncionario(i);
    gerente.adicionarFuncionario(j);
    gerente.adicionarFuncionario(k);        //tentando adicionar o 11º funcionario
    gerente.mostrarTime();                  //mostra os detalhes de todos na equipe do gerente
    cout << gerente.salarioTotal() << endl; //mostra o salario total da equipe mais o gerente
    return 0;
}