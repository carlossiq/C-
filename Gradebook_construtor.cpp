#include <iostream>
#include <string>

class Gradebook
{
    private:
    //membros
    std::string courseName;

    public:
    //construtores
    Gradebook () {}                 //padrao
    Gradebook (std::string name)
    {
        setCourseName(name);
    }

    //funções membro
    void setCourseName( std::string name);
    void displayMessage();
    std::string getCourseName();

};

int main()
{
    Gradebook mygradebook1("Comunicacoes");
    Gradebook mygradebook0;

    mygradebook1.displayMessage();
    mygradebook0.displayMessage();

    return 0;
}

    //determinação das funções
    void Gradebook::setCourseName( std::string name) //com validação
    {
        if(name.length()<25) courseName = name;
        else courseName = name.substr(0,25);   //pega os primeiros 25 caracteres a partir do 0
    }

    std::string Gradebook::getCourseName ()
    {
        return courseName;
    }

    void Gradebook::displayMessage()
    {
    std::cout << "Welcome to Gradebook for " << getCourseName() << "!" << std::endl;
    }
