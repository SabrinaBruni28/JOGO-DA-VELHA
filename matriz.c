#include "matriz.h"

void Inicializa(Matriz* matriz){
    int i,j;
    for(i=0; i<5; i++)
        for(j=0; j<5; j++)
            matriz->jogo[i][j] = ' ';
    for(i=0; i<5; i++){
        matriz->jogo[1][i] = '-';
        matriz->jogo[3][i] = '-';
    }
    for(i=1; i<5; i+=2)
        for(j=0; j<5; j+=2)
            matriz->jogo[j][i] = '|';

}
int Comeco(){
    int a;
    printf("\033[1;36m****************************************************************************************\033[m\n");
    printf("\t\033[1;35m### JOGO DA VELHA ###\033[m\n");
    printf("\n\033[1m1-Jogar\n2-Sair\033[m\n");
    scanf("%d", &a);
    if(a == 1) return a;
     printf("\033[1;36m****************************************************************************************\033[m\n");
    return 0;
}
void Print(Matriz* matriz){
    int i,j;
    printf("\n\n\t");
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(matriz->jogo[i][j]=='X')
                printf("\033[1;33m%c \033[1;33m", matriz->jogo[i][j]);
            else if(matriz->jogo[i][j]=='O')
                printf("\033[1;34m%c \033[1;33m", matriz->jogo[i][j]);
            else
                printf("\033[1;37m%c \033[1;33m", matriz->jogo[i][j]);
        }
        printf("\n\t");
    }
    printf("\n\n");
}
int Inserir(Matriz* matriz, char vez, int posicao1, int posicao2){
    if(posicao1 > 3 || posicao2 > 3 || posicao1 < 1 || posicao2 < 1){
        printf("\n\033[1;4;31mINSIRA UMA POSICAO VALIDA!!\033[m\n");
        return 0;
    }
    if(posicao1==1) posicao1 = 0;
    else if(posicao1==3) posicao1 = 4;

    if(posicao2==1) posicao2 = 0;
    else if(posicao2==3) posicao2 = 4;

    if(matriz->jogo[posicao1][posicao2] == 'X' || matriz->jogo[posicao1][posicao2] == 'O') {
        printf("\n\033[1;4;31mLOCAL JA PREENCHIDO!!!\033[m\n");
        return 0;
    }
    matriz->jogo[posicao1][posicao2] = vez;
    return 1;
}

int Check(Matriz* matriz){
    int i,j;
    int vazio = 0;
    for(i=0; i<5; i+=2){
        for(j=0; j<5; j+=2){
            if(matriz->jogo[i][j] == ' ')
                vazio++;
        }
    }
    if(vazio == 0) return 1;
    return 0;
}
int Ganhou(Matriz* matriz){
    int i,j;
    int igual_X = 0; 
    int igual_O = 0;
    j=0;
    while(j<5){
        for(i=0; i<5; i+=2){
            if(matriz->jogo[i][j] == 'X')
                igual_X++;
            else if(matriz->jogo[i][j] == 'O')
                igual_O++;
        }
        if(igual_O == 3) return 1;
        igual_O = 0;
        if(igual_X == 3) return 2;
        igual_X = 0;
        j+=2;
    }
    j=0;
    while(j<5){
        for(i=0; i<5; i+=2){
            if(matriz->jogo[j][i] == 'X')
                igual_X++;
            else if(matriz->jogo[j][i] == 'O')
                igual_O++;
        }
        if(igual_O == 3) return 1;
        igual_O = 0;
        if(igual_X == 3) return 2;
        igual_X = 0;
        j+=2;
    }
    
    for(i=0; i<5; i+=2){
        if(matriz->jogo[i][i] == 'X')
            igual_X++;
        else if(matriz->jogo[i][i] == 'O')
            igual_O++;
    }
    if(igual_O == 3) return 1;
    igual_O = 0;
    if(igual_X == 3) return 2;
    igual_X = 0;
    
    j=0;
    for(i=4; i>=0; i-=2){
        if(matriz->jogo[i][j] == 'X')
            igual_X++;
        else if(matriz->jogo[i][j] == 'O')
            igual_O++;
        j+=2;
    }
    if(igual_O == 3) return 1;
    igual_O = 0;
    if(igual_X == 3) return 2;
    igual_X = 0;
    
    return 0;
}

int Quem_ganhou(Matriz* matriz){
    int opcao;
    int ganhador = Ganhou(matriz);
    if(ganhador == 1) printf("\033[1;34mPLAYER (O) GANHOU!!!!!!\033[m\n\n");
    else if(ganhador == 2) printf("\033[1;33mPLAYER (X) GANHOU!!!!!!\033[m\n\n");
    else printf("\033[1;32mDEU VELHA!!!\033[m\n");
    printf("\n\033[1m1- Jogar novamente\n2- Sair\033[m\n");
    scanf("%d", &opcao);
    if(opcao==1) return 1;
    printf("\033[1;36m****************************************************************************************\033[m\n");
    return 0;
}
int Escolha_Player(){
    int a;
    printf("\n\033[1m# Qual voce quer?\033[m");
    printf(" \033[1;33m 1)X \033[m \033[1;34m 2)O\033[m\n");
    scanf("%d", &a);
    if(a == 1) return 2;
    else if(a == 2) return 3;   
}