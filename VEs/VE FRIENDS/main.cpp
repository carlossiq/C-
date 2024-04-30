#include <iostream>
using std::cout;
using std::endl;

#include "Friends.h"

int main()
{
CharacterDatabase database;
Character c1 = Character("Rachel Green", "Garçonete"); Character c2 = Character("Monica Geller", "Chef");
Character c3 = Character("Phoebe Buffay", "Massagista"); Character c4 = Character("Chandler Bing", "Desconhecido");
Character c5 = Character("Ross Geller", "Professor"); Character c6 = Character("Joey Tribbiani", "Ator");
database.addCharacter(c1); database.addCharacter(c2); database.addCharacter(c3);
database.addCharacter(c4); database.addCharacter(c5); database.addCharacter(c6);
database.editCharacter("Rachel Green", "Design de Moda");
cout << database.searchCharacter("Gunther") << endl; cout << database.searchCharacter("Rachel Green") << endl;
database.relate(c2, c5, "irmãos"); database.relate(c2, c4, "casados");
database.relate(c1, c2, "roommates"); database.relate(c4, c6, "roommates");
database.deleteCharacter("Phoebe Buffay"); database.imprimir();
return 0;
}