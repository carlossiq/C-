#ifndef FRIENDS_H
#define FRIENDS_H

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>                    //funcoes de busca
using std::find_if;                     //algoritmo de busca
using std::sort;                        //função com algoritmo de organização
using std::copy;

class Character
{
    private:
    string name;
    string profession;

    public:
    Character(){}
    Character(string, string);
    friend class CharacterDatabase;

};

class CharacterDatabase
{
    private:
    struct Relation
    {
        Character A;
        Character B;
        string relation;
    };

    size_t dataCharSize;
    size_t dataRelationSize;
    Character *dataChar;
    Relation *dataRelation;


    public:
    //friend class Character;
    CharacterDatabase() : dataCharSize(0), dataRelationSize(0), dataChar(nullptr), dataRelation(nullptr) {}
    
    CharacterDatabase(const CharacterDatabase&) = delete;
    CharacterDatabase& operator=(const CharacterDatabase&) = delete;

    ~CharacterDatabase()
    { 
        delete[] dataChar;
        delete[] dataRelation;
    }

    void addCharacter(Character&);
    void editCharacter(string, string);
    string searchCharacter(string);
    void relate(Character&, Character&, string);
    void deleteCharacter(string);
    void imprimir();
    void imprimir(int);
};

Character::Character(string newName, string newProfession)
{
    name = newName;
    profession = newProfession;
}

void CharacterDatabase::addCharacter(Character& character)
{
    dataCharSize++;
    if(dataChar == nullptr)
    {
        dataChar = new Character [dataCharSize];
        dataChar[0].name = character.name;
        dataChar[0].profession = character.profession;
    } 
    else
    {
        Character *newData = new Character[dataCharSize];
        for(size_t i = 0; i < (dataCharSize - 1); i++)
        {
            newData[i] = dataChar[i];
       }
        newData[dataCharSize - 1] = character;
        delete dataChar;
        dataChar = newData;
    }
}

void CharacterDatabase::editCharacter(string name, string newProfession)
{
    for(size_t i = 0; i < dataCharSize; i++)
    {
        if(dataChar[i].name.compare(name) == 0)
        {
            dataChar[i].profession = newProfession;
            break;
        }
        else cout << "Character " << name << " not found" << endl;
    }
}

string CharacterDatabase::searchCharacter(string name)
{
    for(size_t i = 0; i < dataCharSize; i++)
    {
        if(dataChar[i].name.compare(name) == 0)
        {
            return dataChar[i].profession;
        }
    }
    return "Character not found \n";
}

void CharacterDatabase::relate(Character &c1, Character &c2, string relation)
{
    dataRelationSize++;
    if(dataRelation == nullptr)
    {
        dataRelation = new Relation [dataRelationSize];
        dataRelation[dataRelationSize - 1].A = c1;
        dataRelation[dataRelationSize - 1].B = c2;
        dataRelation[dataRelationSize - 1].relation = relation;
    }
    else
    {
        Relation *newDataRelation = new Relation [dataRelationSize];
        for(size_t i = 0; i < (dataRelationSize - 1); i++)
        {
            newDataRelation[i] = dataRelation[i];
        }
        newDataRelation[dataRelationSize - 1].A = c1;
        newDataRelation[dataRelationSize - 1].B = c2;
        newDataRelation[dataRelationSize - 1].relation = relation;
        delete[] dataRelation;
        dataRelation = newDataRelation;
    }
}

void CharacterDatabase::deleteCharacter(string name)
{
    //CHARACTER
    if(dataCharSize == 1)
    {
        dataCharSize--;
        delete[] dataChar;
        dataChar = nullptr;
    }
    else
    {
        size_t index = 0;
        bool found = false;
        for(size_t i = 0; i < dataCharSize; i++)
        {
            if(dataChar[i].name.compare(name) == 0)
            {
                found = true;
                index = i;
                dataCharSize--;
                Character *newData = new Character[dataCharSize];
                for(size_t i = 0; i < dataCharSize + 1; i++)
                {
                    size_t j = i;
                    if(i>=index) j++;
                    newData[i] = dataChar[j];
                    delete[] dataChar;
                    dataChar = newData;
                }
                i--;                                                //garante que a busca continue após o deslocamento
            }
        }
        if(found == false)
        {
            cout << "Not found" << endl;
            exit(1);   
        }     
    }
    //RELATION
    if(dataRelationSize == 1)
    {
        dataRelationSize--;
        delete[] dataRelation;
        dataRelation = nullptr;
    }
    else
    {
        size_t index = 0;
        for(size_t i = 0; i < dataRelationSize; i++)
        {
            if(dataRelation[i].A.name.compare(name) == 0 || dataRelation[i].B.name.compare(name) == 0)
            {
                index = i;
                dataRelationSize--;
                Relation *newData = new Relation[dataRelationSize];
                for(size_t i = 0; i < dataRelationSize + 1; i++)
                {
                    size_t j = i;
                    if(i >= index) j++;
                    newData[i] = dataRelation[j];
                    delete[] dataRelation;
                    dataRelation = newData;
                }
                i--;
            }
        }        
    }
}

void CharacterDatabase::imprimir()
{
    for(size_t i = 0; i < dataRelationSize; i++)
    {
        cout << dataRelation[i].A.name << " e " << dataRelation[i].B.name << " sao " << dataRelation[i].relation << "." << endl;
    }
}    

#endif