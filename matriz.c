#include "matriz.h"

void Inicializa(Matriz* matriz){
    int i,j;

    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            matriz->jogo[i][j] = ' ';
}

void Titulo(int n){
    printf("\n\t\t\t\033[%d;%dm" "     ----------------------------------------------------"   "\033[m\n", BOLD, n);
    printf("\t\t\t\t\t\033[%dm" "    JOGO DA VELHA    "    "\033[m ", BOLD);
    printf("\n\t\t\t\033[%d;%dm" "     ----------------------------------------------------"   "\033[m\n", BOLD, n);
}

int Jogar(){
    int a;
    printf("\n\033[%dm\t" "1- Jogar         2- Sair" "\033[m\n" "\tR: ", BOLD);
    ERRO(scanf("%d", &a));
    if (a != 1) return 0;
    return a;
}

void Imprime(Matriz* matriz){
    int i,j;
    printf("\n\n\t\t");
    printf(" %s | %s | %s ", WhichOne(matriz, 0, 0), WhichOne(matriz, 0, 1), WhichOne(matriz, 0, 2));

    printf("\n\t\t");
    printf(" - - - - - ");

    printf("\n\t\t");
    printf(" %s | %s | %s ", WhichOne(matriz, 1, 0), WhichOne(matriz, 1, 1), WhichOne(matriz, 1, 2));
    
    printf("\n\t\t");
    printf(" - - - - - ");
    
    printf("\n\t\t");
    printf(" %s | %s | %s ", WhichOne(matriz, 2, 0), WhichOne(matriz, 2, 1), WhichOne(matriz, 2, 2));
    
    printf("\n\n\n");
}

char* WhichOne(Matriz* matriz, int i, int j){

    if(matriz->jogo[i][j]=='X')
        return "\033[1;33mX\033[m";

    else if(matriz->jogo[i][j]=='O')
        return "\033[1;34mO\033[m";

    else
        return " ";
}

int Inserir(Matriz* matriz, char vez, int posicao){
    int i, j;

    if(posicao < 1 || posicao > 9){
        printf("\n\033[%d;%d;%dm\t" "INSIRA UMA POSIÇÃO VÁLIDA!!" "\033[m\n\n", BOLD, VERMELHO, PISCAR );
        return 0;
    }

    if( posicao <= 3 ) {
        i = 0;
        j = posicao - 1;
    }

    else if (posicao <= 6 ) {
        i = 1;
        j = posicao - 4;
    }

    else if (posicao <= 9 ){
        i = 2; 
        j = posicao - 7;
    }

    if( matriz->jogo[i][j] == 'X' || matriz->jogo[i][j] == 'O' ) {
        printf( "\n\033[%d;%d;%dm\t" "LOCAL JÁ PREENCHIDO!!!" "\033[m\n\n", BOLD, VERMELHO, PISCAR );
        return 0;
    }

    matriz->jogo[i][j] = vez;
    return 1;
}

int CheckPreenchido(Matriz* matriz){
    int i,j;

    for( i = 0; i < 3; i++ )
        for( j = 0; j < 3; j++ )
            if( matriz->jogo[i][j] == ' ' ) return 0;

    return 1;
}

int AlguemGanhou(Matriz* matriz){

    /* O = 2; X = 1; Velha = 0; */
    int i, j;

    for( i = 0; i < 3; i++ ){
        /* Completou uma linha */
        if(matriz->jogo[i][0] == 'X' && matriz->jogo[i][1] == 'X' && matriz->jogo[i][2] == 'X') return 1;
        else if(matriz->jogo[i][0] == 'O' && matriz->jogo[i][1] == 'O' && matriz->jogo[i][2] == 'O') return 2;

        /* Completou uma coluna */
        else if(matriz->jogo[0][i] == 'X' && matriz->jogo[1][i] == 'X' && matriz->jogo[2][i] == 'X') return 1;
        else if(matriz->jogo[0][i] == 'O' && matriz->jogo[1][i] == 'O' && matriz->jogo[2][i] == 'O') return 2;

    }
    /* Completou diagonal direta */
    if(matriz->jogo[0][0] == 'X' && matriz->jogo[1][1] == 'X' && matriz->jogo[2][2] == 'X') return 1;
    else if(matriz->jogo[0][0] == 'O' && matriz->jogo[1][1] == 'O' && matriz->jogo[2][2] == 'O') return 2;

    /* Completou diagonal reversa */
    else if(matriz->jogo[0][2] == 'X' && matriz->jogo[1][1] == 'X' && matriz->jogo[2][0] == 'X') return 1;
    else if(matriz->jogo[0][2] == 'O' && matriz->jogo[1][1] == 'O' && matriz->jogo[2][0] == 'O') return 2;

    if( CheckPreenchido(matriz) ) return 0;
    return -1;
}

int FimJogo(Matriz* matriz){
    int ganhador = AlguemGanhou(matriz);

    if ( ganhador == 0) printf( "\033[%d;%dm\t" "##### DEU VELHA! #####" "\033[m\n\n", BOLD, VERDE );
    
    else if(ganhador == 1) printf( "\033[%d;%dm\t" "##### PLAYER (X) GANHOU! #####" "\033[m\n\n", BOLD, AMARELO );

    else if(ganhador == 2) printf( "\033[%d;%dm\t" "##### PLAYER (O) GANHOU! #####" "\033[m\n\n", BOLD, AZUL );

    else return 0;

    return 1;
}

int JogarNovamente(){
    int a;
    printf("\n\033[%dm\t" "1- Jogar novamente       2- Sair" "\033[m\n" "\tR: ", BOLD);
    ERRO(scanf("%d", &a));
    if (a != 1) return 0;
    return a;
}

int EscolhaPlayer(){
    int a;
    printf("\n\033[%dm\t" "# Qual você quer?" "\033[m", BOLD);
    printf(" \033[%d;%dm\t" "1)X" "\033[m" "\033[%d;%dm\t" "2)O" "\033[m\n" "\tR: ", BOLD, AMARELO, BOLD, AZUL);
    ERRO(scanf("%d", &a));
    if(a != 1 && a != 2) return 0;
    return a; 
}

void Asterisco(int n){
    printf("\n\033[%d;%dm"  "******************************************************************************************************************************************************************"    "\033[m\n", BOLD, n);
}

int Posicao(){
    int a;
    printf("\033[%dm\t" "Posição: " "\033[m\n" "\tR: ", BOLD);
    ERRO(scanf("%d", &a));
    return a;
}

int ERRO(int n){
    if(!n){
        printf("\n\t\033[%d;%d;%dm"   "@@@@@@@ ERRO FATAL :( @@@@@@@@"    "\033[m\n", PISCAR, BOLD, VERMELHO);
        Asterisco(AMARELO);
        exit(0);
        return 1;
    }
    return 0;
}