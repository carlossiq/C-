#include "Heroi.h"

void display(string);

int main()
{
    //SH
    SuperHeroi spiderMan("Homem-Aranha", "Peter Park");
    SuperHeroi superMan("Super-Homem", "Clark Kent");    
    SuperHeroi captainAmerica("Capitao America", "Steven Rogers");    
    SuperHeroi flash("Flash", "Barry Allen");    
    SuperHeroi greenLantern("Lanterna-Verde", "Hal Jordan");    
    SuperHeroi ironMan("Homem de Ferro", "Tony Stark");    

    //VILOES
    Vilao greenGoblin("Duende Verde", "Normal Osborn", 2);    
    Vilao lexLuthor("Lex Luthor", "Lex Luthor", 3);    
    Vilao bizarro("Bizarro", "Bizarro", 5);    
    Vilao octpus("Octopus", "Otto Octavius", 4);

    //PODERES
    Superpoder teia("soltar teia", 3);
    Superpoder andarParedes("andar em paredes", 2);
    Superpoder sentidoApurado("sentido apurado", 1);

    Superpoder voar("voar", 3);
    Superpoder forca("forca", 5);
    Superpoder raioX("visao de raio x", 4);
    Superpoder soproCongelante("sopro congelante", 4);
    
    Superpoder superSoldado("supersoldado", 3);
    Superpoder escudo("escudo", 3);

    Superpoder velocidade5("velocidade", 5);

    Superpoder anel("anel magico", 5);

    Superpoder aramdura("armadura", 4);
    Superpoder dispositivos("dispositivos eletronicos", 2);

    Superpoder mente("mente agucada", 5);

    Superpoder tentaculos("tentaculos indestrutiveis", 5);
    Superpoder velocidade1("velocidade", 1);

    //ATRIBUTO DOS PODERES
    spiderMan.adicionaSuperpoder(teia);
    spiderMan.adicionaSuperpoder(andarParedes);
    spiderMan.adicionaSuperpoder(sentidoApurado);

    superMan.adicionaSuperpoder(voar);
    superMan.adicionaSuperpoder(forca);
    superMan.adicionaSuperpoder(raioX);
    superMan.adicionaSuperpoder(soproCongelante);

    captainAmerica.adicionaSuperpoder(superSoldado);
    captainAmerica.adicionaSuperpoder(escudo);

    flash.adicionaSuperpoder(velocidade5);

    greenLantern.adicionaSuperpoder(anel);

    ironMan.adicionaSuperpoder(aramdura);

    lexLuthor.adicionaSuperpoder(mente);

    bizarro.adicionaSuperpoder(voar);
    bizarro.adicionaSuperpoder(forca);
    bizarro.adicionaSuperpoder(raioX);
    bizarro.adicionaSuperpoder(soproCongelante);

    octpus.adicionaSuperpoder(tentaculos);
    octpus.adicionaSuperpoder(velocidade1);

    //SIMULAÇÃO
    Confronto confronto;
    cout << "Combate entre " <<  spiderMan.getNome() << " e " << greenGoblin.getNome() << endl;
    display(confronto.enfrentar(spiderMan,greenGoblin));
    
    cout << "Combate entre " <<  superMan.getNome() << " e " << lexLuthor.getNome() << endl;
    display(confronto.enfrentar(superMan,lexLuthor));
    
    cout << "Combate entre " <<  flash.getNome() << " e " << bizarro.getNome() << endl;
    display(confronto.enfrentar(flash,bizarro));
    
    cout << "Combate entre " <<  greenLantern.getNome() << " e " << octpus.getNome() << endl;
    display(confronto.enfrentar(greenLantern,octpus));
    
    cout << "Combate entre " <<  ironMan.getNome() << " e " << greenGoblin.getNome() << endl;
    display(confronto.enfrentar(ironMan,greenGoblin));
    
    cout << "Combate entre " <<  captainAmerica.getNome() << " e " << bizarro.getNome() << endl;
    display(confronto.enfrentar(captainAmerica,bizarro));

    return 0;
}

void display(string confronto)
{
    if(confronto == "Empate") cout << "Empate!" << endl;
    else cout << confronto << " venceu o confronto!" << endl << endl;
}