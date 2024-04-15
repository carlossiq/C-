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

#include <iostream> // Entrada e saída
using std::cout;
using std::cin;
using std::endl;

#include <fstream> // Para manipulacao de arquivos

#include <cstring> // Para funcoes de manipulacao de strings em estilo C

#include <iomanip>
using std::setw;

#include <windows.h>
#include <ctime>

#define PRESENT "SISTEMA DE CADASTRO UNIVERSITARIO"

/* Mostra o dia no sistema */
void show_time() {
    time_t tempoAtual = time(nullptr);
    tm* dataHora = localtime(&tempoAtual);

    // Mostra a data atual formatada como dd/mm/aaaa
    std::cout << dataHora->tm_mday << "/" << dataHora->tm_mon + 1 << "/" << dataHora->tm_year + 1900 << endl << endl;
}

void title()
{
    system("cls");
    cout << PRESENT << " "; show_time();
}

void clean()
{
    getchar();
    cin.ignore();
    system("cls");            
}


class Aluno {
private:
    char codigo[6];
    char nomeCompleto[51]; // Vetor de caracteres para o nome completo
    char cpf[12];

public:
    Aluno() {} // Construtor padrao

    Aluno(const char* cpf, const char* nomeCompleto, const char* codigo) {
        setCPF(cpf);
        setNome(nomeCompleto);
        setCodigo(codigo);
    }

    const char* getCPF() const {
        return cpf;
    }

    const char* getNomeCompleto() const {
        return nomeCompleto;
    }

    const char* getCodigo() const {
        return codigo;
    }

    void setCodigo(const char* novoCodigo) {
        strncpy(codigo, novoCodigo,5);
        codigo[5]='\0';
    }

    void setCPF(const char* novoCPF) {
        strcpy(cpf, novoCPF);
    }

    void setNome(const char* novoNome) {
        strncpy(nomeCompleto, novoNome, 50);
    }
};

struct NodeA {
    Aluno aluno;
    NodeA* next;

    NodeA(const Aluno& aluno) : aluno(aluno), next(nullptr) {}
};

class ListaAlunos {
private:
    NodeA* head;

public:
    ListaAlunos() : head(nullptr) {
        carregarLista("alunos.bin");
    }

    ~ListaAlunos() {
        while (head != nullptr) {
            NodeA* nextNode = head->next;
            delete head;
            head = nextNode;
        }
    }

    std::string nomeAluno (const char* codigo) const {
        
        NodeA* current = head;
        while (current != nullptr) {
            if (std::strcmp(current->aluno.getCodigo(), codigo) == 0) {
                return current->aluno.getNomeCompleto();
            }
            current = current->next;
        }
        return "";
    }

    bool codigoExiste(const char* codigo) const {
        NodeA* current = head;
        while (current != nullptr) {
            if (std::strcmp(current->aluno.getCodigo(), codigo) == 0) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    bool cpfExiste(const char* cpf) const {
    NodeA* current = head;
    while (current != nullptr) {
        if (std::strcmp(current->aluno.getCPF(), cpf) == 0) {
            return true; // O CPF já existe na lista
        }
        current = current->next;
    }
    return false; // O CPF não existe na lista
    }

    void inserirAluno(Aluno& aluno) {
        char novoCodigo[5]; // Buffer para armazenar o novo código
        char novoCPF[12]; // Buffer para armazenar o novo CPF

        // Verificar se o código do aluno já existe na lista
        while (codigoExiste(aluno.getCodigo())) {
            std::cerr << "Codigo de aluno ja existente na lista. Digite um codigo diferente: ";
            std::cin >> novoCodigo;
            aluno.setCodigo(novoCodigo); // Atualiza o código do aluno com o novo código inserido
        }

        // Verificar se o CPF do aluno já existe na lista
        while (cpfExiste(aluno.getCPF())) {
            std::cerr << "CPF ja cadastrado na lista. Digite um CPF diferente: ";
            std::cin >> novoCPF;
            aluno.setCPF(novoCPF); // Atualiza o CPF do aluno com o novo CPF inserido
        }

        // Se o código não existir na lista, inserir o aluno normalmente
        NodeA* newNode = new NodeA(aluno);
        newNode->next = head;
        head = newNode;
    }

    void exibirAlunos() const {
        NodeA* current = head;
        std::cout << setw(7) << "Codigo" << setw(38) << "Nome Completo" << setw(27) << "CPF" << std::endl;
        while (current != nullptr) {
            std::cout << setw(6) << current->aluno.getCodigo() << setw(51) << current->aluno.getNomeCompleto() << setw(19) << current->aluno.getCPF() << std::endl;
            current = current->next;
        }
    }

    bool validarCPF(const char* cpf) const {
        // Verifica se todos os caracteres são dígitos
        for (int i = 0; i < 11; ++i) {
            if (!isdigit(cpf[i])) {
                return false;
            }
        }

        // Verifica se todos os dígitos são iguais
        bool allEqual = true;
        for (int i = 1; i < 11; ++i) {
            if (cpf[i] != cpf[0]) {
                allEqual = false;
                break;
            }
        }
        if (allEqual) {
            return false;
        }

        // Calcula o primeiro dígito verificador
        int sum = 0;
        for (int i = 0; i < 9; ++i) {
            sum += (cpf[i] - '0') * (10 - i);
        }
        int firstDigit = 11 - (sum % 11);
        if (firstDigit >= 10) {
            firstDigit = 0;
        }

        // Verifica o primeiro dígito verificador
        if (cpf[9] - '0' != firstDigit) {
            return false;
        }

        // Calcula o segundo dígito verificador
        sum = 0;
        for (int i = 0; i < 10; ++i) {
            sum += (cpf[i] - '0') * (11 - i);
        }
        int secondDigit = 11 - (sum % 11);
        if (secondDigit >= 10) {
            secondDigit = 0;
        }

        // Verifica o segundo dígito verificador
        if (cpf[10] - '0' != secondDigit) {
            return false;
        }

        return true;
    }

    bool validarCodigo(const char* codigo) const{
        if (std::strlen(codigo)==5){
            bool digitos = true;
            for (int i = 0; i < 5; i++)
            {
                if(!std::isdigit(codigo[i])) {
                    digitos=false;
                    return false;
                }
            }
            return digitos;           
        }
        else return false;
    }

    void salvarLista(const char* nomeArquivo) const {
        std::ofstream arquivo(nomeArquivo, std::ios::binary);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo para escrita!" << std::endl;
            return;
        }

        NodeA* current = head;
        while (current != nullptr) {
            arquivo.write(reinterpret_cast<const char*>(&current->aluno), sizeof(Aluno));
            current = current->next;
        }

        arquivo.close();
        //std::cout << "Lista de alunos salva em " << nomeArquivo << std::endl;
    }

    void carregarLista(const char* nomeArquivo) {
        std::ifstream arquivo(nomeArquivo, std::ios::binary);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo para leitura!" << std::endl;
            return;
        }

        Aluno aluno;
        while (arquivo.read(reinterpret_cast<char*>(&aluno), sizeof(Aluno))) {
            inserirAluno(aluno);
        }

        arquivo.close();
        //std::cout << "Lista de alunos carregada de " << nomeArquivo << std::endl;
    }

    void removerAlunoPorCodigo(const char* codigo) {
    NodeA* current = head;
    NodeA* prev = nullptr;

    while (current != nullptr) {
        if (std::strcmp(current->aluno.getCodigo(), codigo) == 0) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            std::cout << "Aluno com codigo " << codigo << " removido da lista." << std::endl;
            return;
        }
        prev = current;
        current = current->next;
    }

    std::cerr << "Aluno com codigo " << codigo << " nao encontrado na lista." << std::endl;
}
};


class Disciplina {
private:
    char codigo[5];
    char disciplina[51]; // Vetor de caracteres para o nome completo
    char professor[51];
    int credito;

public:
    Disciplina() {} // Construtor padrao

    Disciplina(const char* professor, const char* disciplina, const char* codigo, int credito) {
        setDisciplina(disciplina);
        setCodigo(codigo);
        setCredito(credito);
        setProfessor(professor);
    }

    const char* getProfessor() const {
        return professor;
    }

    const char* getDisciplina() const {
        return disciplina;
    }

    const char* getCodigo() const {
        return codigo;
    }

    int getCredito() const {
        return credito;
    }

    void setCodigo(const char* novoCodigo) {
        strncpy(codigo, novoCodigo,4);
        codigo[4]='\0';
    }

    void setProfessor(const char* novoProfessor) {
        strncpy(professor, novoProfessor,50);
    }

    void setDisciplina(const char* novaDisciplina) {
        strncpy(disciplina, novaDisciplina,50);
    }

    void setCredito(int novoCredito) {
        credito = novoCredito;
    }
};

struct NodeD {
    Disciplina disciplina;
    NodeD* next;

    NodeD(const Disciplina& disciplina) : disciplina(disciplina), next(nullptr) {}
};

class ListaDisciplinas {
private:
    NodeD* head;

public:
    ListaDisciplinas() : head(nullptr) {
        carregarLista("disciplinas.bin");
    }

    ~ListaDisciplinas() {
        while (head != nullptr) {
            NodeD* nextNode = head->next;
            delete head;
            head = nextNode;
        }
    }

    bool codigoExiste(const char* codigo) const {
        NodeD* current = head;
        while (current != nullptr) {
            if (std::strcmp(current->disciplina.getCodigo(), codigo) == 0) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    std::string nomeDisciplina (const char* codigo) const {
        
        NodeD* current = head;
        while (current != nullptr) {
            if (std::strcmp(current->disciplina.getCodigo(), codigo) == 0) {
                return current->disciplina.getDisciplina();
            }
            current = current->next;
        }
        return "";
    }

    bool professorExiste(const char* professor) const {
        NodeD* current = head;
        while (current != nullptr) {
            if (std::strcmp(current->disciplina.getProfessor(), professor) == 0) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    void inserirDisciplina(Disciplina& disciplina) {
        NodeD* newNode = new NodeD(disciplina);
        newNode->next = head;
        head = newNode;
    }

    void exibirDisciplinas() const {
        NodeD* current = head;
        std::cout << setw(7) << "Codigo" << setw(38) << "Disciplina" << setw(27) << "Professor" << setw(10) << "Credito" << std::endl;
        while (current != nullptr) {
            std::cout << setw(6) << current->disciplina.getCodigo() << setw(51) << current->disciplina.getDisciplina() << setw(19) << current->disciplina.getProfessor() << setw(10) << current->disciplina.getCredito() << std::endl;
            current = current->next;
        }
    }

    bool validarCodigo(const char* codigo) const{
        if (std::strlen(codigo)==4){
            bool digitos = true;
            for (int i = 0; i < 4; i++)
            {
                if(!std::isdigit(codigo[i])) {
                    digitos=false;
                    return false;
                }
            }
            return digitos;           
        }
        else return false;
    }

    void salvarLista(const char* nomeArquivo) const {
        std::ofstream arquivo(nomeArquivo, std::ios::binary);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo para escrita!" << std::endl;
            return;
        }

        NodeD* current = head;
        while (current != nullptr) {
            arquivo.write(reinterpret_cast<const char*>(&current->disciplina), sizeof(Disciplina));
            current = current->next;
        }

        arquivo.close();
    }

    void carregarLista(const char* nomeArquivo) {
        std::ifstream arquivo(nomeArquivo, std::ios::binary);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo para leitura!" << std::endl;
            return;
        }

        Disciplina disciplina;
        while (arquivo.read(reinterpret_cast<char*>(&disciplina), sizeof(Disciplina))) {
            inserirDisciplina(disciplina);
        }

        arquivo.close();
    }

    void removerDisciplinaPorCodigo(const char* codigo) {
    NodeD* current = head;
    NodeD* prev = nullptr;

    while (current != nullptr) {
        if (std::strcmp(current->disciplina.getCodigo(), codigo) == 0) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            std::cout << "Disciplina com codigo " << codigo << " removido da lista." << std::endl;
            return;
        }
        prev = current;
        current = current->next;
    }

    std::cerr << "Disciplina com codigo " << codigo << " nao encontrado na lista." << std::endl;
}
};

struct Data {
    int dia;
    int mes;
    int ano;
};

Data getDataAtual() {
    time_t tempoAtual = time(nullptr);
    tm* data = localtime(&tempoAtual);

    Data dataAtual;
    dataAtual.dia = data->tm_mday;
    dataAtual.mes = data->tm_mon + 1;
    dataAtual.ano = data->tm_year + 1900;

    return dataAtual;
}

class Matricula {
private:
    char codal[6];
    char coddis[5];

public:
    Data data;
    Matricula() {} // Construtor padrao

    Matricula(const char* coddis, const char* codal, const Data& data) {
        setCodDis(coddis);
        setCodAl(codal);
        setData(data);
    }

    const char* getCodDis() const {
        return coddis;
    }

    const char* getCodAl() const {
        return codal;
    }

    const Data& getData() const {
        return data;
    }

    void setCodDis(const char* novoCodigo) {
        strncpy(coddis, novoCodigo, 4);
        coddis[4] = '\0';
    }

    void setCodAl(const char* novoCodigo) {
        strncpy(codal, novoCodigo, 5);
        codal[5] = '\0';
    }

    void setData(const Data& novaData) {
        data = novaData;
    }
};

struct NodeM {
    Matricula matricula;
    NodeM* next;

    NodeM(const Matricula& matricula) : matricula(matricula), next(nullptr) {}
};

class ListaMatricula {
private:
    NodeM* head;

public:
    ListaMatricula() : head(nullptr) {
        carregarLista("matriculas.bin");
    }

    ~ListaMatricula() {
        while (head != nullptr) {
            NodeM* nextNode = head->next;
            delete head;
            head = nextNode;
        }
    }
    
    void matricular(Matricula& matricula) {
        
        NodeM* newNode = new NodeM(matricula);
        newNode->next = head;
        head = newNode;
    }

    void exibirMatriculas(int periodo, const ListaAlunos& listaAlunos, const ListaDisciplinas& listaDisciplinas) const {
    NodeM* current = head;
    cout << setw(7) << "Codigo" << setw(27) << "Disciplina" << setw(38) << "Nome Completo" << endl;

    while (current != nullptr) {
        // Calcula o período baseado no mês da data da matrícula
        int matriculaPeriodo = (current->matricula.getData().mes - 1) / 6 + 1;

        if (matriculaPeriodo == periodo) {
            std::string nomeDisciplina = listaDisciplinas.nomeDisciplina(current->matricula.getCodDis());
            std::string nomeAluno = listaAlunos.nomeAluno(current->matricula.getCodAl());

            cout << setw(7) << current->matricula.getCodDis()
                 << setw(27) << (nomeDisciplina.empty() ? "Nao encontrado" : nomeDisciplina)
                 << setw(38) << (nomeAluno.empty() ? "Nao encontrado" : nomeAluno)
                 << endl;
        }
        current = current->next;
    }
}

    void salvarLista(const char* nomeArquivo) const {
        std::ofstream arquivo(nomeArquivo, std::ios::binary);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo para escrita!" << std::endl;
            return;
        }

        NodeM* current = head;
        while (current != nullptr) {
            arquivo.write(reinterpret_cast<const char*>(&current->matricula), sizeof(Matricula));
            current = current->next;
        }

        arquivo.close();
        //std::cout << "Lista de alunos salva em " << nomeArquivo << std::endl;
    }

    void carregarLista(const char* nomeArquivo) {
        std::ifstream arquivo(nomeArquivo, std::ios::binary);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo para leitura!" << std::endl;
            return;
        }

        Matricula matricula;
        while (arquivo.read(reinterpret_cast<char*>(&matricula), sizeof(Matricula))) {
            matricular(matricula);
        }

        arquivo.close();
        //std::cout << "Lista de alunos carregada de " << nomeArquivo << std::endl;
    }

    void removerMatriculaPorCodigo(const char* codigoDis, const char* codigoAl) {
    NodeM* current = head;
    NodeM* prev = nullptr;

    while (current != nullptr) {
        // Checa se ambos os códigos (disciplina e aluno) são iguais aos dados fornecidos
        if (strcmp(current->matricula.getCodDis(), codigoDis) == 0 && strcmp(current->matricula.getCodAl(), codigoAl) == 0) {
            if (prev == nullptr) {
                head = current->next; // Se o nó a ser removido é o head, atualiza o head
            } else {
                prev->next = current->next; // Remove o nó da lista ligando o anterior ao próximo
            }
            delete current; // Libera a memória do nó removido
            std::cout << "Matrícula removida com sucesso." << std::endl;
            return; // Sai da função após remover a matrícula
        }
        prev = current; // Atualiza o ponteiro para o nó anterior
        current = current->next; // Move para o próximo nó
        }

        std::cout << "Matrícula não encontrada com os códigos fornecidos." << std::endl;
    }

    bool matriculaExistente(const char* coddis, const char* codal) {
        NodeM* current = head;
        while (current != nullptr) {
            if (strcmp(current->matricula.getCodDis(), coddis) == 0 && strcmp(current->matricula.getCodAl(), codal) == 0) {
                return true; // A matrícula já existe
            }
            current = current->next;
        }
        return false; // Não encontrada a matrícula com os códigos fornecidos
    }
};


void exibirMenu() {
    title();
    cout << "1. Adicionar Aluno" << endl;
    cout << "2. Adicionar Disciplina" << endl;
    cout << "3. Exibir Alunos" << endl;
    cout << "4. Exibir Disciplinas" << endl;
    cout << "5. Remover Aluno" << endl;
    cout << "6. Remover Disciplina" << endl;
    cout << "7. Salvar Lista" << endl;
    cout << "8. Sair" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
ListaAlunos lista_aluno;
ListaDisciplinas lista_dis;
ListaMatricula lista_mat;

    int opcao;
    do {
        exibirMenu();
        std::cin >> opcao;

        switch (opcao) {
            //Adicionar Aluno
            case 1: {
                title();
                char cpf[12];
                char nomeCompleto[51];
                char codigo[5];

                bool swCPF = false;
                bool swCod = false;

                cout << "\nInserir novo aluno:" << std::endl;

                do
                {
                    cout << "Codigo (5 digitos): ";
                    cin.ignore();
                    cin >> codigo;
                    if(!lista_aluno.validarCodigo(codigo)){cout << "Codigo Invalido!" << endl;}
                    if(lista_aluno.codigoExiste(codigo)){cout << "Codigo ja cadastrado no sistema!" << endl;}
                    if((lista_aluno.validarCodigo(codigo)) && (!lista_aluno.codigoExiste(codigo))) swCod=true;
                } while (!swCod);                       

                cout << "Nome Completo: ";
                cin.ignore(); // Limpar o buffer do teclado
                cin.getline(nomeCompleto, sizeof(nomeCompleto));
                
                do {
                    cout << "CPF (11 digitos): ";
                    cin >> cpf;
                    if(!lista_aluno.validarCPF(cpf)){cout << "CPF Invalido!" << endl;}
                    if(lista_aluno.cpfExiste(cpf)){cout << "CPF ja cadastrado no sistema!" << endl;}
                    if((lista_aluno.validarCPF(cpf)) && (!lista_aluno.cpfExiste(cpf))) swCPF=true;
                } while (!swCPF);

                Aluno novoAluno(cpf, nomeCompleto, codigo);
                lista_aluno.inserirAluno(novoAluno);

                cout << "Aluno inserido com sucesso!" << endl;
                clean();

                break;
            }

            //Adicionar Disciplina
            case 2: {
                title();
                char professor[51];
                char disciplina[51];
                char codigo[4];
                int credito;

                bool swProfessor = false;
                bool swCod = false;

                cout << "\nInserir nova disciplina:" << std::endl;

                do
                {
                    cout << "Codigo (4 digitos): ";
                    cin.ignore();
                    cin >> codigo;
                    if(!lista_dis.validarCodigo(codigo)){cout << "Codigo Invalido!" << endl;}
                    if(lista_dis.codigoExiste(codigo)){cout << "Codigo ja cadastrado no sistema!" << endl;}
                    if((lista_dis.validarCodigo(codigo)) && (!lista_dis.codigoExiste(codigo))) swCod=true;
                } while (!swCod);                       

                cout << "Nome da Disciplina: ";
                cin.ignore(); // Limpar o buffer do teclado
                cin.getline(disciplina, sizeof(disciplina));
                
                do {
                    cout << "Nome do Professor: ";
                    //cin.ignore();
                    cin.getline(professor, sizeof(professor));
                    if(lista_dis.professorExiste(professor)){cout << "Professor ja cadastrado no sistema!" << endl;}
                    if((!lista_dis.professorExiste(professor))) swProfessor=true;
                } while (!swProfessor);

                cout << "Credito: ";
                //cin.ignore(); // Limpar o buffer do teclado
                cin >> credito;
                cin.ignore();

                Disciplina novaDisciplina(professor, disciplina, codigo, credito);

                lista_dis.inserirDisciplina(novaDisciplina);

                cout << "Disciplina inserida com sucesso!" << endl;
                clean();

                break;
            }

            //Matricular
            case 9: {
                title();
                char codal[6]; // Array para o código do aluno, espaço suficiente para o '\0'
                char coddis[5]; // Array para o código da disciplina
                Data data = getDataAtual(); // Obtem a data atual

                bool swCodDis = false;
                char continuar = 's';

                cout << "\nMatricular Alunos:\n";

                // Obtenção e validação do código da disciplina
                while (!swCodDis) {
                    cout << "Digite o codigo da disciplina (4 dígitos): ";
                    cin >> coddis;
                    coddis[4] = '\0'; // Assegura o terminador nulo

                    if (!lista_dis.validarCodigo(coddis) || !lista_dis.codigoExiste(coddis)) {
                        cout << "Codigo de disciplina invalido ou nao cadastrado!\n";
                    } else {
                        swCodDis = true;
                    }
                }

                cout << "Disciplina selecionada: " << lista_dis.nomeDisciplina(coddis) << endl;

                // Loop para matricular um ou mais alunos
                do {
                    cout << "Digite o código do aluno (5 dígitos): ";
                    cin >> codal;
                    codal[5] = '\0'; // Assegura o terminador nulo

                    if (!lista_aluno.validarCodigo(codal) || !lista_aluno.codigoExiste(codal)) {
                        cout << "Codigo de aluno invalido ou nao cadastrado!\n";
                        continue;
                    }

                    Matricula novaMatricula(coddis, codal, data);

                    // Verifica se a matrícula já existe
                    if (lista_mat.matriculaExistente(coddis, codal)) {
                        cout << "Aluno ja matriculado nesta disciplina.\n";
                    } else {
                        lista_mat.matricular(novaMatricula);
                        cout << "Aluno matriculado com sucesso!\n";
                    }

                    cout << "Deseja matricular outro aluno nesta disciplina? (s/n): ";
                    cin >> continuar;

                } while (continuar == 's' || continuar == 'S');

                clean();
                break;
            }

            //Exibir Matriculas
            case 10:{
                cout << "Lista de matriculas por periodo. Insira o periodo desejado (1 ou 2):" << endl;
                int periodo;
                do{
                    cin.ignore();
                    cin >> periodo;
                    if(!(periodo == 1 || periodo == 2)) {cout << "O periodo deve ser 1 ou 2" << endl;}
                }while(!(periodo == 1 || periodo == 2));
                lista_mat.exibirMatriculas(periodo, lista_aluno, lista_dis);
                clean();
                break;
            }

            //Exibir Alunos
            case 3:{
                cout << "\nLista de Alunos:" << endl;
                lista_aluno.exibirAlunos();
                clean();
                break;
            }

            //Exibir Disciplinas
            case 4:{
                cout << "\nLista de Disciplinas:" << endl;
                lista_dis.exibirDisciplinas();
                clean();
                break;
            }

            //Remover Aluno
            case 5: {
                char codigo[5];
                cout << "\nRemover aluno - Informe o codigo: ";
                cin >> codigo;
                lista_aluno.removerAlunoPorCodigo(codigo);
                break;
            }

            //Remover Disciplina
            case 6: {
                char codigo[5];
                cout << "\nRemover disciplina - Informe o codigo: ";
                cin >> codigo;
                lista_dis.removerDisciplinaPorCodigo(codigo);
                break;
            }

            //Remover Matricula
            case 11: {
                char codigoDis[5];
                char codigoAl[6];
                cout << "Remover matricula, informe o codigo da disciplina (4 digitos) e o codigo do aluno (5 digitos): ";
                cin >> codigoDis >> codigoAl;
                lista_mat.removerMatriculaPorCodigo(codigoDis, codigoAl);
                break;
            }

            //Salvar
            case 7:{
                lista_aluno.salvarLista("alunos.bin");
                lista_dis.salvarLista("disciplinas.bin");
                lista_mat.salvarLista("matriculas.bin");
                break;
            }

            //Sair
            case 8:{
                cout << "Encerrando o programa..." << endl;
                break;           
            }            
            
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while (opcao != 8);

    return 0;
}