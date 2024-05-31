#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// função comprar carta do topo do baralho para a mão do jogador; a carta deve ser retirada do baralho; se a mão estiver cheia emitir aviso e impedir;
// assuma uma função que embaralhe o baralho; retorna 1 se o baralho foi corretamente embaralhado ou 0 se ele não foi;
// se receber um valor de 0 ao embaralhar, deve imprimir erro ao embaralhar com return -1;
// assuma que há uma função que converte o número de uma carta para seu nome conhecido string

int embaralhar(int baralho[]);
char *toString(int numeroCarta);
int comprarCarta(int baralho[], int hand[], int *cartasBaralho, int *cartasMao);

void printCartas(int cartas[], int numero);
void menu()
{
    puts("[1] Embaralhar");
    puts("[1] Comprar");
}

int main()
{
    // vetor de 52 cartas de inteiros
    int numeroDeCartasNoBaralho = 52;
    int baralho[] = {23, 1, 47, 8, 15, 36, 52, 29, 5, 12, 43, 7, 28, 41, 14, 34, 9, 21, 50, 13, 2, 31, 49, 4, 19, 48, 26, 37, 16, 10, 25, 39, 45, 3, 35, 20, 44, 18, 6, 33, 46, 30, 17, 27, 22, 51, 11, 32, 24, 42, 38, 40};
    
    // vetor de 5 posições que representa a mão de um jogador
    int numeroDeCartasNaMao = 0;
    int hand[] = {0, 0, 0, 0, 0};

    int opcao, vezDeJogar = 0;

    while(1)
    {
        scanf("%d", &opcao); fflush(stdin);
        switch (opcao)
        {
        case 0:
            printf("Opcao invalida. Insira novamente: \n");
            break;

        case 1:
            embaralhar(baralho);        
            printf("Embaralhado.\n");

        case 2:
            comprarCarta(baralho, hand, &numeroDeCartasNoBaralho, &numeroDeCartasNaMao);
        }
    }
    

    return 0;
}

int embaralhar(int baralho[])               { return 1; }

char *toString(int numeroCarta)             { return "Carta"; }

int comprarCarta(int baralho[], int hand[], int *cartasBaralho, int *cartasMao)
{
    if(*cartasMao == 5)
    {
        printf("Mao cheia!\n");
        return 0;       
    }
    else
    {
        if(*cartasBaralho <= 52)
        {
            hand[*cartasMao] = baralho[*cartasBaralho - 1];
            (*cartasBaralho)--;
            (*cartasMao)++;
            return 1;
        }
        else return 0;
    }
}

void printCartas(int cartas[], int numero)
{
    if(numero == 0) printf("Sem cartas!\n");
    else
    {
        for(int i = 0; i < numero; i++)
        {
            printf("%d ", cartas[i]);
        }
        printf("\n");
    }
}