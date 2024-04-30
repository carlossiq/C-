#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Lista
{
    protected:
    int inicio;
    int fim;
    int nElemento;
    int *array;
    
    void nbElemento(int n);
    void expandir(int n);

    public:
    void inserir(int valor);
    void listar();
    void remover(int chave);
    void imprimir();
    int buscaBinaria(int *array, int inicio, int fim, int chave);

    Lista(int novaCapacidade)
    {
        nbElemento(novaCapacidade);
        array = new int[novaCapacidade];
    }

    ~Lista(){}
};

class Pilha : public Lista
{
    public:
    Pilha(int novaCapacidade) : Lista(novaCapacidade){};
    void remover();
};

class Fila : public Lista
{
    public:
    Fila(int novaCapacidade) : Lista(novaCapacidade){};
    void inserir(int valor);
    void remover();
};

class Deque : public Fila
{
    public:
    Deque(int novaCapacidade) : Fila(novaCapacidade){};
    void inserirInicio(int valor);
    void inserirFim(int valor);
    void removerInicio();
    void removerFim();
};

int main()
{
    Lista l(3);     //ok
    
    Pilha p(4);     //ok
    
    Fila f(3);      //ok
    
    Deque d(4);     //ok
    
    return 0;
}

void Lista::nbElemento(int n)
{
    nElemento = n;
    inicio = 0;
    fim = 0;
}

void Lista::expandir(int n)
{
    int novaCapacidade = n + nElemento;
    int *newarray = new int[novaCapacidade];
    for (int i = 0; i < nElemento; i++)
    {
        newarray[i] = array[i];
    }
    delete[] array;
    array = newarray;
    nElemento = novaCapacidade;
}

void Lista::imprimir()
{
    if(fim == inicio){cout << "Lista Vazia" << endl;}
    else
    {
        for (int i = 0; i < fim; i++) {cout << array[i] << " ";}
        cout << endl;
    }
}

void Lista::inserir(int valor)
{
    if(fim-inicio == nElemento) {cout << "Lista cheia" << endl;}
    else
    {   
        array[fim] = valor;
        fim++;
    }
}

void Lista::remover(int chave)
{
    int posicao = buscaBinaria(array, inicio, fim, chave);
    if( posicao != (-1))
    {
        for (int i = posicao; i < fim-1; i++)
        {
            array[i] = array[i+1]; 
        }
        fim--;        
    }
    else {cout << "Valor nao encontrado." << endl;}
}

int Lista::buscaBinaria(int *array, int inicio, int fim, int chave) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Verifica se o elemento está no meio
        if (array[meio] == chave)
            return meio;

        // Se o elemento for maior, ignora a metade esquerda
        if (array[meio] < chave)
            inicio = meio + 1;

        // Se o elemento for menor, ignora a metade direita
        else
            fim = meio - 1;
    }

    // Retorna -1 se o elemento não está presente
    return -1;
}

void Pilha::remover()
{
    fim--;
}

void Fila::inserir(int valor)
{
    if(fim-inicio == nElemento) {cout << "Lista cheia" << endl;}
    else 
    {
        for (int i = fim; i > inicio; i--)
        {
            array[i]=array[i-1];
        }
        array[inicio] = valor;
        fim++;
    }
}

void Fila::remover()
{
    for (int i = inicio; i < fim-1; i++)
    {
        array[i] = array[i+1];
    }
    fim--;
}

void Deque::inserirFim(int valor)
{
    Lista::inserir(valor);
}

void Deque::inserirInicio(int valor)
{
    Fila::inserir(valor);
}

void Deque::removerInicio()
{
    Fila::remover();
}

void Deque::removerFim()
{
    fim--;
}