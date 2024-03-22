#include <iostream>
#include <fstream>

void type()
    {
        int tipo;
        std::ifstream arquivo("alunos.dat", std::ios::out | std::ios:: binary);
        arquivo.read(reinterpret_cast<char*>(&tipo), sizeof(int));
    }