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
    /*Laco que funciona como uma maquina de estados.*/
    while(tempo){
        switch (tempo){
            /*Inicia o jogo.*/
            case 1:
                Inicializa(&matriz);
                tempo = Escolha_Player();
                Print(&matriz);
                break;
            /*Player X jogando.*/
            case 2:
                printf("\033[1;33mPLAYER: X\n\033[m");
                player_atual = player1;
                printf("\033[1mPosicoes: \033[m");
                scanf("%d %d", &posicao1, &posicao2);
                if(Inserir(&matriz,player_atual,posicao1, posicao2)) tempo = 3;
                Print(&matriz);
                if(Check(&matriz) || Ganhou(&matriz)) tempo = 4;
                break;
            /*Player 0 jogando.*/
            case 3:
                printf("\033[1;34mPLAYER: O\033[m\n");
                player_atual = player2;
                printf("\033[1mPosicoes: \033[m");
                scanf("%d %d", &posicao1, &posicao2);
                if(Inserir(&matriz,player_atual,posicao1, posicao2)) tempo = 2;
                Print(&matriz);
                if(Check(&matriz) || Ganhou(&matriz) ) tempo = 4;
                break;
            /*finaliza o jogo.*/
            case 4:
                tempo = Quem_ganhou(&matriz);
                break;
        }
    }
    return 0;
}