#include "matriz.h"

int main() {
    Matriz matriz;
    char player1 = 'X';
    char player2 = 'O';
    char player_atual;
    int posicao;
    int tempo;

    Asterisco(AMARELO);
    Titulo(AZUL);

    tempo = Jogar();

    /* Loop que mantém o jogo ativo. */
    while(tempo){
        switch (tempo){
            /* Inicia o jogo. */
            case 1:
                Inicializa(&matriz);
                tempo = EscolhaPlayer() + 1;
                Imprime(&matriz);
                break;

            /*Player X jogando.*/
            case 2:
                printf("\033[%d;%dm\t" "PLAYER: %c" "\033[m\n\n", BOLD, AMARELO, player1);
                player_atual = player1;
                posicao = Posicao();
                if(Inserir(&matriz, player_atual, posicao)) tempo = 3;
                Imprime(&matriz);

                if(FimJogo(&matriz)) tempo = 4;
                break;

            /*Player 0 jogando.*/
            case 3:
                printf("\033[%d;%dm\t" "PLAYER: %c" "\033[m\n\n", BOLD, AZUL, player2 );
                player_atual = player2;
                posicao = Posicao();
                if(Inserir(&matriz, player_atual, posicao)) tempo = 2;
                Imprime(&matriz);
                if(FimJogo(&matriz)) tempo = 4;
                break;

            /*Finaliza o jogo.*/
            case 4:
                tempo = JogarNovamente();
                break;
        }
    }
    Asterisco(AMARELO);
    return 0;
}