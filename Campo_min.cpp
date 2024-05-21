#include<bits/stdc++.h>
#include<cmath>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;
enum lugar{ normal, lados, quina};
enum situacao{valida, invalida};
class CM{
    private:
        int tamC;
        int tamL;
        string ** tabuleiroV = new string* [2*tamL-1];
        string ** tabuleiroF = new string* [2*tamL-1];
        int num_bomba;

        bool verificar_vitoria(){
            for(int i=0; i<2*tamL-1; i++){
                for(int j=0; j<2*tamC-1; j++){
                    if(tabuleiroV[i][j]!="X" && tabuleiroF[i][j]==" ")
                        return 0;}}
            cout<<endl<<"parabens! voce desbravou esse campo minado."<<endl;
            return 1;                

        }
        situacao verificar_casa(int x, int y){
            if(x>=0 && x<2*tamL-1 && y>=0 && y<2*tamC-1 ){

                if(tabuleiroF[2*x][2*y]==" "){
                    return valida;
                }
                else{
                    cout<< "Essa casa ja esta ocupada."<<endl;
                    return invalida;
                    }
                    }
            else{
                cout<< "Essa casa nao esta no tabuleiro."<<endl;
                return invalida;}}

        lugar verificar_lugar(int x, int y){

            if((x==2*tamL-2 && y!=0 && y!=2*tamC-2) || (x==0 && y!=0 && y!=2*tamC-2) ||(x!=0 && x!=2*tamL-1 && y==0) ||(x!=0 && x!=2*tamL-2 && y==2*tamC-2) )
                return lados;
            else if((x==0 || x==2*tamL-2) && (y==0 || y==2*tamC-2 ))
                return quina;
            else 
                return normal;}

    void mostra_0(int i, int j) {
        if (tabuleiroV[2 * i][2 * j] == to_string(0)) {
            lugar casa = verificar_lugar(2 * i, 2 * j);
            if (casa == quina && i == 0 && j == 0) {
                if (tabuleiroF[2][0] == " " && tabuleiroV[2][0] != "X") {
                    tabuleiroF[2][0] = tabuleiroV[2][0];
                    mostra_0(1, 0);
                }
                if (tabuleiroF[2][2] == " " && tabuleiroV[2][2] != "X") {
                    tabuleiroF[2][2] = tabuleiroV[2][2];
                    mostra_0(1, 1);
                }
                if (tabuleiroF[0][2] == " " && tabuleiroV[0][2] != "X") {
                    tabuleiroF[0][2] = tabuleiroV[0][2];
                    mostra_0(0, 1);
                }
            }
            else if (casa == quina && i == 0 && j == 2 * tamC - 2) {
                if (tabuleiroF[2][2 * tamC - 2] == " " && tabuleiroV[2][2 * tamC - 2] != "X") {
                    tabuleiroF[2][2 * tamC - 2] = tabuleiroV[2][2 * tamC - 2];
                    mostra_0(1, tamC - 1);
                }
                if (tabuleiroF[2][2 * tamC - 4] == " " && tabuleiroV[2][2 * tamC - 4] != "X") {
                    tabuleiroF[2][2 * tamC - 4] = tabuleiroV[2][2 * tamC - 4];
                    mostra_0(1, tamC - 2);
                }
                if (tabuleiroF[0][2 * tamC - 4] == " " && tabuleiroV[0][2 * tamC - 4] != "X") {
                    tabuleiroF[0][2 * tamC - 4] = tabuleiroV[0][2 * tamC - 4];
                    mostra_0(0, tamC - 2);
                }
            }
            else if (casa == quina && i == 2 * tamL - 2 && j == 2 * tamC - 2) {
                if (tabuleiroF[2 * tamL - 4][2 * tamC - 2] == " " && tabuleiroV[2 * tamL - 4][2 * tamC - 2] != "X") {
                    tabuleiroF[2 * tamL - 4][2 * tamC - 2] = tabuleiroV[2 * tamL - 4][2 * tamC - 2];
                    mostra_0(tamL - 2, tamC - 1);
                }
                if (tabuleiroF[2 * tamL - 4][2 * tamC - 4] == " " && tabuleiroV[2 * tamL - 4][2 * tamC - 4] != "X") {
                    tabuleiroF[2 * tamL - 4][2 * tamC - 4] = tabuleiroV[2 * tamL - 4][2 * tamC - 4];
                    mostra_0(tamL - 2, tamC - 2);
                }
                if (tabuleiroF[2 * tamL - 2][2 * tamC - 4] == " " && tabuleiroV[2 * tamL - 2][2 * tamC - 4] != "X") {
                    tabuleiroF[2 * tamL - 2][2 * tamC - 4] = tabuleiroV[2 * tamL - 2][2 * tamC - 4];
                    mostra_0(tamL - 1, tamC - 2);
                }
            }
            else if (casa == quina && i == 2 * tamL - 2 && j == 0) {
                if (tabuleiroF[2 * tamL - 2][2] == " " && tabuleiroV[2 * tamL - 2][2] != "X") {
                    tabuleiroF[2 * tamL - 2][2] = tabuleiroV[2 * tamL - 2][2];
                    mostra_0(tamL - 1, 1);
                }
                if (tabuleiroF[2 * tamL - 4][2] == " " && tabuleiroV[2 * tamL - 4][2] != "X") {
                    tabuleiroF[2 * tamL - 4][2] = tabuleiroV[2 * tamL - 4][2];
                    mostra_0(tamL - 2, 1);
                }
                if (tabuleiroF[2 * tamL - 4][0] == " " && tabuleiroV[2 * tamL - 4][0] != "X") {
                    tabuleiroF[2 * tamL - 4][0] = tabuleiroV[2 * tamL - 4][0];
                    mostra_0(tamL - 2, 0);
                }
            }
            else if (casa == normal) {
                if (tabuleiroF[2 * i][2 * j - 2] == " " && tabuleiroV[2 * i][2 * j - 2] != "X") {
                    tabuleiroF[2 * i][2 * j - 2] = tabuleiroV[2 * i][2 * j - 2];
                    mostra_0(i, j - 1);
                }
                if (tabuleiroF[2 * i][2 * j + 2] == " " && tabuleiroV[2 * i][2 * j + 2] != "X") {
                    tabuleiroF[2 * i][2 * j + 2] = tabuleiroV[2 * i][2 * j + 2];
                    mostra_0(i, j + 1);
                }
                if (tabuleiroF[2 * i + 2][2 * j] == " " && tabuleiroV[2 * i + 2][2 * j] != "X") {
                    tabuleiroF[2 * i + 2][2 * j] = tabuleiroV[2 * i + 2][2 * j];
                    mostra_0(i + 1, j);
                }
                if (tabuleiroF[2 * i + 2][2 * j - 2] == " " && tabuleiroV[2 * i + 2][2 * j - 2] != "X") {
                    tabuleiroF[2 * i + 2][2 * j - 2] = tabuleiroV[2 * i + 2][2 * j - 2];
                    mostra_0(i + 1, j - 1);
                }
                if (tabuleiroF[2 * i + 2][2 * j + 2] == " " && tabuleiroV[2 * i + 2][2 * j + 2] != "X") {
                    tabuleiroF[2 * i + 2][2 * j + 2] = tabuleiroV[2 * i + 2][2 * j + 2];
                    mostra_0(i + 1, j + 1);
                }
                if (tabuleiroF[2 * i - 2][2 * j - 2] == " " && tabuleiroV[2 * i - 2][2 * j - 2] != "X") {
                    tabuleiroF[2 * i - 2][2 * j - 2] = tabuleiroV[2 * i - 2][2 * j - 2];
                    mostra_0(i - 1, j - 1);
                }
                if (tabuleiroF[2 * i - 2][2 * j + 2] == " " && tabuleiroV[2 * i - 2][2 * j + 2] != "X") {
                    tabuleiroF[2 * i - 2][2 * j + 2] = tabuleiroV[2 * i - 2][2 * j + 2];
                    mostra_0(i - 1, j + 1);
                }
                if (tabuleiroF[2 * i - 2][2 * j] == " " && tabuleiroV[2 * i - 2][2 * j] != "X") {
                    tabuleiroF[2 * i - 2][2 * j] = tabuleiroV[2 * i - 2][2 * j];
                    mostra_0(i - 1, j);
                }
            }
            else {
                if (casa == lados && i == 0) {
                    if (tabuleiroF[0][2 * j - 2] == " " && tabuleiroV[0][2 * j - 2] != "X") {
                        tabuleiroF[0][2 * j - 2] = tabuleiroV[0][2 * j - 2];
                        mostra_0(0, j - 1);
                    }
                    if (tabuleiroF[0][2 * j + 2] == " " && tabuleiroV[0][2 * j + 2] != "X") {
                        tabuleiroF[0][2 * j + 2] = tabuleiroV[0][2 * j + 2];
                        mostra_0(0, j + 1);
                    }
                    if (tabuleiroF[2][2 * j] == " " && tabuleiroV[2][2 * j] != "X") {
                        tabuleiroF[2][2 * j] = tabuleiroV[2][2 * j];
                        mostra_0(1, j);
                    }
                    if (tabuleiroF[2][2 * j + 2] == " " && tabuleiroV[2][2 * j + 2] != "X") {
                        tabuleiroF[2][2 * j + 2] = tabuleiroV[2][2 * j + 2];
                        mostra_0(1, j + 1);
                    }
                    if (tabuleiroF[2][2 * j - 2] == " " && tabuleiroV[2][2 * j - 2] != "X") {
                        tabuleiroF[2][2 * j - 2] = tabuleiroV[2][2 * j - 2];
                        mostra_0(1, j - 1);
                    }
                }
                else if (casa == lados && i == 2 * tamL - 2) {
                    if (tabuleiroF[2 * tamL - 2][2 * j - 2] == " " && tabuleiroV[2 * tamL - 2][2 * j - 2] != "X") {
                        tabuleiroF[2 * tamL - 2][2 * j - 2] = tabuleiroV[2 * tamL - 2][2 * j - 2];
                        mostra_0(tamL - 1, j - 1);
                    }
                    if (tabuleiroF[2 * tamL - 2][2 * j + 2] == " " && tabuleiroV[2 * tamL - 2][2 * j + 2] != "X") {
                        tabuleiroF[2 * tamL - 2][2 * j + 2] = tabuleiroV[2 * tamL - 2][2 * j + 2];
                        mostra_0(tamL - 1, j + 1);
                    }
                    if (tabuleiroF[2 * tamL - 4][2 * j] == " " && tabuleiroV[2 * tamL - 4][2 * j] != "X") {
                        tabuleiroF[2 * tamL - 4][2 * j] = tabuleiroV[2 * tamL - 4][2 * j];
                        mostra_0(tamL - 2, j);
                    }
                    if (tabuleiroF[2 * tamL - 4][2 * j + 2] == " " && tabuleiroV[2 * tamL - 4][2 * j + 2] != "X") {
                        tabuleiroF[2 * tamL - 4][2 * j + 2] = tabuleiroV[2 * tamL - 4][2 * j + 2];
                        mostra_0(tamL - 2, j + 1);
                    }
                    if (tabuleiroF[2 * tamL - 4][2 * j - 2] == " " && tabuleiroV[2 * tamL - 4][2 * j - 2] != "X") {
                        tabuleiroF[2 * tamL - 4][2 * j - 2] = tabuleiroV[2 * tamL - 4][2 * j - 2];
                        mostra_0(tamL - 2, j - 1);
                    }
                }
                else if (casa == lados && j == 2 * tamC - 2) {
                    if (tabuleiroF[2 * i - 2][2 * tamC - 2] == " " && tabuleiroV[2 * i - 2][2 * tamC - 2] != "X") {
                        tabuleiroF[2 * i - 2][2 * tamC - 2] = tabuleiroV[2 * i - 2][2 * tamC - 2];
                        mostra_0(i - 1, tamC - 1);
                    }
                    if (tabuleiroF[2 * i + 2][2 * tamC - 2] == " " && tabuleiroV[2 * i + 2][2 * tamC - 2] != "X") {
                        tabuleiroF[2 * i + 2][2 * tamC - 2] = tabuleiroV[2 * i + 2][2 * tamC - 2];
                        mostra_0(i + 1, tamC - 1);
                    }
                    if (tabuleiroF[2 * i - 2][2 * tamC - 4] == " " && tabuleiroV[2 * i - 2][2 * tamC - 4] != "X") {
                        tabuleiroF[2 * i - 2][2 * tamC - 4] = tabuleiroV[2 * i - 2][2 * tamC - 4];
                        mostra_0(i - 1, tamC - 2);
                    }
                    if (tabuleiroF[2 * i][2 * tamC - 4] == " " && tabuleiroV[2 * i][2 * tamC - 4] != "X") {
                        tabuleiroF[2 * i][2 * tamC - 4] = tabuleiroV[2 * i][2 * tamC - 4];
                        mostra_0(i, tamC - 2);
                    }
                    if (tabuleiroF[2 * i + 2][2 * tamC - 4] == " " && tabuleiroV[2 * i + 2][2 * tamC - 4] != "X") {
                        tabuleiroF[2 * i + 2][2 * tamC - 4] = tabuleiroV[2 * i + 2][2 * tamC - 4];
                        mostra_0(i + 1, tamC - 2);
                    }
                }
                else if (casa == lados && j == 0) {
                    if (tabuleiroF[2 * i][2] == " " && tabuleiroV[2 * i][2] != "X") {
                        tabuleiroF[2 * i][2] = tabuleiroV[2 * i][2];
                        mostra_0(i, 1);
                    }
                    if (tabuleiroF[2 * i + 2][2] == " " && tabuleiroV[2 * i + 2][2] != "X") {
                        tabuleiroF[2 * i + 2][2] = tabuleiroV[2 * i + 2][2];
                        mostra_0(i + 1, 1);
                    }
                    if (tabuleiroF[2 * i - 2][2] == " " && tabuleiroV[2 * i - 2][2] != "X") {
                        tabuleiroF[2 * i - 2][2] = tabuleiroV[2 * i - 2][2];
                        mostra_0(i - 1, 1);
                    }
                    if (tabuleiroF[2 * i - 2][0] == " " && tabuleiroV[2 * i - 2][0] != "X") {
                        tabuleiroF[2 * i - 2][0] = tabuleiroV[2 * i - 2][0];
                        mostra_0(i - 1, 0);
                    }
                    if (tabuleiroF[2 * i + 2][0] == " " && tabuleiroV[2 * i + 2][0] != "X") {
                        tabuleiroF[2 * i + 2][0] = tabuleiroV[2 * i + 2][0];
                        mostra_0(i + 1, 0);
                    }
                }
            }
        }
    }

        bool boom(int i, int j){
            if(tabuleiroV[2*i][2*j]=="X"){
                cout<<"BOOM!!!!! Voce perdeu!"<<endl;
                return 1;}
            else
                return 0;
        }
        void montagem_verd(){
            int num_casa=0;
            for(int i=0;i<2*tamL-1;i+=2){
                for(int j=0; j<2*tamC-1; j+=2){
                    if(tabuleiroV[i][j]=="X"){
                    }
                    else
                    {   lugar casa;
                        casa=verificar_lugar(i,j);
                        if ( casa == normal){
                            if(tabuleiroV[i+2][j+2]=="X")
                               {num_casa+=1;}
                            if(tabuleiroV[i+2][j]=="X")
                                {num_casa+=1;}
                            if(tabuleiroV[i+2][j-2]=="X")
                                {num_casa+=1;}
                            if(tabuleiroV[i][j+2]=="X")
                               {num_casa+=1;}
                            if(tabuleiroV[i][j-2]=="X")
                                {num_casa+=1;}
                            if(tabuleiroV[i-2][j+2]=="X")
                                {num_casa+=1;}
                            if(tabuleiroV[i-2][j]=="X")
                               {num_casa+=1;}
                            if(tabuleiroV[i-2][j-2]=="X")
                                {num_casa+=1;}
                            tabuleiroV[i][j]=to_string(num_casa);
                            num_casa=0;
                        }
                       else if ( casa == lados){
                            if(i==2*tamL-2){
                                if(tabuleiroV[i-2][j+2]=="X")
                                    {num_casa+=1;}
                                if(tabuleiroV[i-2][j]=="X")
                                   {num_casa+=1;}
                                if(tabuleiroV[i-2][j-2]=="X")
                                   {num_casa+=1;}
                                if(tabuleiroV[i][j+2]=="X")
                                   {num_casa+=1;}
                                if(tabuleiroV[i][j-2]=="X")
                                    {num_casa+=1;}
                                tabuleiroV[i][j]=to_string(num_casa);
                                num_casa=0;}

                           else if(i==0){
                                if(tabuleiroV[i+2][j+2]=="X")
                                   {num_casa+=1;}
                                if(tabuleiroV[i+2][j]=="X")
                                    {num_casa+=1;}
                                if(tabuleiroV[i+2][j-2]=="X")
                                    {num_casa+=1;}
                                if(tabuleiroV[i][j+2]=="X")
                                   {num_casa+=1;}
                                if(tabuleiroV[i][j-2]=="X")
                                   {num_casa+=1;}
                                tabuleiroV[i][j]=to_string(num_casa);
                                num_casa=0;}
                            else if(j==0){
                                if(tabuleiroV[i-2][j+2]=="X")
                                    {num_casa+=1;}
                                if(tabuleiroV[i][j+2]=="X")
                                    {num_casa+=1;}
                                if(tabuleiroV[i+2][j+2]=="X")
                                    {num_casa+=1;}
                                if(tabuleiroV[i+2][j]=="X")
                                    {num_casa+=1;}
                                if(tabuleiroV[i-2][j]=="X")
                                    {num_casa+=1;}
                                tabuleiroV[i][j]=to_string(num_casa);
                                num_casa=0;}
                           else {
                                if(tabuleiroV[i-2][j-2]=="X")
                                    {num_casa+=1;}
                                if(tabuleiroV[i][j-2]=="X")
                                    {num_casa+=1;}
                                if(tabuleiroV[i+2][j-2]=="X")
                                   {num_casa+=1;}
                                if(tabuleiroV[i+2][j]=="X")
                                   {num_casa+=1;}
                                if(tabuleiroV[i-2][j]=="X")
                                    {num_casa+=1;}
                                tabuleiroV[i][j]=to_string(num_casa);
                                num_casa=0;}
                        }
                        else {
                            if(i==0 && j==0){
                                if(tabuleiroV[i+2][j]=="X")
                                    {num_casa+=1;}
                                if(tabuleiroV[i+2][j+2]=="X")
                                   {num_casa+=1;}
                                if(tabuleiroV[i][j+2]=="X")
                                    {num_casa+=1;}
                                tabuleiroV[i][j]=to_string(num_casa);
                                num_casa=0;
                            }
                           else if(i==0 && j==2*tamC-2){
                                if(tabuleiroV[i+2][j]=="X")
                                    {num_casa+=1;}
                                if(tabuleiroV[i+2][j-2]=="X")
                                    {num_casa+=1;};
                                if(tabuleiroV[i][j-2]=="X")
                                    {num_casa+=1;}
                                tabuleiroV[i][j]=to_string(num_casa);
                                num_casa=0;
                            }
                           else if(i==2*tamL-2 && j==0){
                                if(tabuleiroV[i][j+2]=="X")
                                    {num_casa+=1;}
                                if(tabuleiroV[i-2][j+2]=="X")
                                   {num_casa+=1;}
                                if(tabuleiroV[i-2][j]=="X")
                                    {num_casa+=1;}
                                tabuleiroV[i][j]=to_string(num_casa);
                                num_casa=0;
                            }
                           else {
                                if(tabuleiroV[i][j-2]=="X")
                                    {num_casa+=1;}
                                if(tabuleiroV[i-2][j-2]=="X")
                                    {num_casa+=1;}
                                if(tabuleiroV[i-2][j]=="X")
                                    {num_casa+=1;}
                                tabuleiroV[i][j]=to_string(num_casa);
                                num_casa=0;
                            }
                        }
                    }}}
        }
    public:

    CM(int n, int l , int c):num_bomba(n), tamL(l), tamC(c){
        if(n<tamL*tamC)
            num_bomba=n;
        else
            num_bomba=1;

        for(int i=0; i< 2*tamL-1; i++){
            tabuleiroV[i]=new string[2*tamC-1];
            tabuleiroF[i]=new string[2*tamC-1];}
        for(int i=1; i<2*tamL-1; i+=2)
                {for(int j=0; j<2*tamC-1; j++){
                    tabuleiroV[i][j]='-';
                    tabuleiroF[i][j]='-';}}
        for(int j=0; j<2*tamL-1; j+=2)
                {for(int i=1; i<2*tamC-1; i+=2) {
                    tabuleiroV[j][i]='|';
                    tabuleiroF[j][i]='|';} }
        for(int j=0; j<2*tamL-1; j+=2)
                {for(int i=0; i<2*tamC-1; i+=2) {
                    tabuleiroV[j][i]=' ';
                    tabuleiroF[j][i]=' ';}  }
            
    }

    ~CM(){
        for(int i=0; i<2*tamL-1;i++){
                delete [] tabuleiroV[i];
                delete [] tabuleiroF[i];
                } 
            delete [] tabuleiroV;
            delete [] tabuleiroF;
    }
   
    void imprimir(){
        for(int i=0; i<2*tamL-1; i++){
            for(int j=0; j<2*tamC-1; j++)
                cout<<tabuleiroF[i][j];
            cout<<endl;
        }
    }

    void sortear_bombas(){
        int bomb_adc=0;
        int consulta[num_bomba];
        for(int i=0; i< num_bomba; i++)
            consulta[i]=-1;
        while(bomb_adc!=num_bomba){
            inicio:
            int a = rand() % tamL;
            int b = rand() % tamC;
            for(int i=0; i< num_bomba; i++){
                if(consulta[i]==10*a+b)
                    goto inicio;
            }
            tabuleiroV[2*a][2*b]="X";
            bomb_adc+=1;

            }
        montagem_verd();
        }
    void jogar(){
        int x,y;
        bool b=0;
        imprimir();
        sortear_bombas();
        do{
        repete:
        cout<<"escolha as coordenadas disponiveis para seu lance!"<<endl;
        cin>>x>>y;
        cout<<endl;
        system("cls");
        situacao jogada=verificar_casa(x,y);
        if(jogada==invalida){
            char a;
            cout<<"voce deseja continuar jogando?S/N"<<endl;
            cin>>a;
            if(a=='S'||a=='s')
                goto repete;
            else
                cout<<"obrigado por jogar!"<<endl;
        }
        else{
            mostra_0(x,y);
            tabuleiroF[2*x][2*y]=tabuleiroV[2*x][2*y];
            b=boom(x,y);
            imprimir();}
        }while(verificar_vitoria()==0 && b!=1);
        cout<<"obrigado por jogar!"<<endl;
    }

};

int main(){
    srand(time(nullptr));
    CM cm(1,10,14);
    cout<<"Vamos jogar um campo minado!!"<< endl;
    cm.jogar();
}