#include "Banco.h"

int main()
{
    Banco b(10); //capacidade max do banco
    ClienteComum cc1("Joao", 1, 3, 5); //nome, tempo de chegada, tempo de sv, tempo de espera max
    ClienteComum cc3("Luiz", 3, 5, 2);
    ClienteComum cc2("Jose", 2, 4, 6);
    ClientePreferencial cp1("Maria", 1, 3); //nome, tempo de chegada, tempo de sv
    ClientePreferencial cp2("Ana", 2, 4);
    ClientePreferencial cp3("Jorge", 3, 5);
    b.adicionarCliente(cc2);
    b.adicionarCliente(cc3);
    b.adicionarCliente(cc1);
    b.adicionarCliente(cp2);
    b.adicionarCliente(cp3);
    b.adicionarCliente(cp1);

    stats st = b.simular();
    cout << st.tempoMedio << " " << st.desistentes << endl; //retorna estatísticas
}