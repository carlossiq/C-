#include <iostream>
using std::cout;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cstdlib>  // srand() e rand()
#include <ctime>    // time()
#include <random>

#include "Soldado.h"
#include "Classes.h"
#include "Sauron.h"
#include "Mago.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

/*
A função main deve criar um exército de Elfos, Anões, Humanos, e Orcs e deve ser capaz de
atribuir um nome, saúde e poder de ataque a cada soldado em seu exército. O programa deve criar 1
instância de Sauron, 1 Mago, 10 orcs, 5 elfos, 5 humanos e 5 anões, onde todos lutam entre si
aleatoriamente até restar apenas um. O personagem que restar é então o campeão do torneio e deve ter
seu nome imortalizado para sempre na saída do programa.
*/

int main()
{   
    // contêiner de personagens que compoe o campo de batalha
    vector <Soldado*> personagem;
    
    // Adiciona elfos
    personagem.push_back(new Elfo("Kurmiel", 100, 20));
    personagem.push_back(new Elfo("Grielga"));
    personagem.push_back(new Elfo("Ethquen"));
    personagem.push_back(new Elfo("Rondlan"));
    personagem.push_back(new Elfo("Hathir"));

    // Adiciona humanos
    personagem.push_back(new Humano("Kabras", 100, 20));
    personagem.push_back(new Humano("Dinoley"));
    personagem.push_back(new Humano("Nielda"));
    personagem.push_back(new Humano("Reginson"));
    personagem.push_back(new Humano("Sungsan"));

    // Adiciona mago
    personagem.push_back(new Mago("Lethgius The Grey", 100, 20));

    // Adiciona anões
    personagem.push_back(new Anao("Grilin", 100, 20));
    personagem.push_back(new Anao("Tolbrand"));
    personagem.push_back(new Anao("Duum"));
    personagem.push_back(new Anao("Dargar"));
    personagem.push_back(new Anao("Ummo"));

    // Adiciona Sauron
    personagem.push_back(new  Sauron("Sauron", 100, 50));

    // Adiciona orcs
    personagem.push_back(new Orc("Moggrat'grim", 100, 20));
    personagem.push_back(new Orc("Zhul'murz"));
    personagem.push_back(new Orc("Orkmashbei"));
    personagem.push_back(new Orc("Ga'skab"));
    personagem.push_back(new Orc("Lukjuthrum"));
    personagem.push_back(new Orc("El-thu"));
    personagem.push_back(new Orc("Rosh'rogg"));
    personagem.push_back(new Orc("Triggsharksel"));
    personagem.push_back(new Orc("Cro'zu"));
    personagem.push_back(new Orc("Dorgargshnag"));

    //Batalha
    //srand(time(nullptr));
    std::mt19937 rng(time(nullptr));  // O motor de geração

    cout << "A batalha esta iniciando com " << personagem.size() << " personagens em conflito!" << endl;
    while(personagem.size() > 1)
    {
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, personagem.size() - 1);  // Recria a distribuição com numeros aleatorios de 0 até o tamanho -1
    //cout <<  "Existem " << personagem.size() << " personagens no campo de batalha." << endl;
        //int i = rand()%personagem.size();
        //int j = rand()%personagem.size();
        int i = dist(rng);
        int j = dist(rng);
        if (i != j)                                              //se persongens diferentes
        {
            cout << personagem[i]->getNome() << " atacando " << personagem[j]->getNome() << endl;
            personagem[i]->atacar(*personagem[j]);
            if(personagem[j]->condicao() == false)                //se o personagem está morto
            {
                cout << personagem[j]->getNome() << " morreu!" << endl;
                if(personagem[j]->getNome() == "Sauron")
                {
                    cout << endl;
                    cout << "O grande mal que dominava nossa terra finalmente caiu, quem sera o vencedor de Terra-Media?" << endl;
                    cout << endl;
                getchar();
                }
                personagem.erase(personagem.begin() + j);        //é apagado.
            }
        } cout << endl;
        #ifdef _WIN32
            //Sleep(500); // Windows espera em milissegundos
        #else
            //usleep(500,000); // Unix espera em segundos
        #endif
        //getchar();
    }
    Soldado& p = *personagem[0];                                  //referencia//alias
    cout << p.getNome() <<", " << p.getTitulo() <<  ", ergueu-se perante Campo de Batalha com honra e gloria jamais apreciados!" << endl;
    cout << "A paz uma vez mais reina em Terra-Media sob o comando das forcas do ";
    if (p.getLado() == true) cout << "bem!" << endl;
    else cout << "mal. Mas sera mesmo a paz?" << endl;

    return 0;
}