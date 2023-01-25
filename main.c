#include "matriz.h"

int main(){
    Matriz matriz;
    char player1 = 'X';
    char player2 = 'O';
    char player_atual;
    int posicao1,posicao2;
    int tempo;
    int opcao;
    tempo = Comeco();
    while(tempo){
        switch (tempo)
        {
        case 1:
            Inicializa(&matriz);
            tempo = Escolha_Player();
            Print(&matriz);
            break;
        case 2:
            printf("PLAYER: X\n");
            player_atual = player1;
            printf("Posicoes: ");
            scanf("%d %d", &posicao1, &posicao2);
            if(Inserir(&matriz,player_atual,posicao1, posicao2)) tempo = 3;
            Print(&matriz);
            if(Check(&matriz) || Ganhou(&matriz)) tempo = 4;
            break;
        case 3:
            printf("PLAYER: O\n");
            player_atual = player2;
            printf("Posicoes: ");
            scanf("%d %d", &posicao1, &posicao2);
            if(Inserir(&matriz,player_atual,posicao1, posicao2)) tempo = 2;
            Print(&matriz);
            if(Check(&matriz) || Ganhou(&matriz) ) tempo = 4;
            break;
        case 4:
            tempo = Quem_ganhou(&matriz);
            break;
        }
    }
    return 0;
}