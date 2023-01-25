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
    printf("****************************************************************************************\n");
    printf("\t### JOGO DA VELHA ###\n");
    printf("1-Jogar.\n2-Sair.\n");
    scanf("%d", &a);
    if(a == 1) return a;
     printf("****************************************************************************************\n");
    return 0;
}
void Print(Matriz* matriz){
    int i,j;
    printf("\n\n\t");
    for(i=0; i<5; i++){
        for(j=0; j<5; j++)
            printf("%c ", matriz->jogo[i][j]);
        printf("\n\t");
    }
    printf("\n\n");
}
int Inserir(Matriz* matriz, char vez, int posicao1, int posicao2){
    if(posicao1 > 3 || posicao2 > 3 || posicao1 < 1 || posicao2 < 1){
        printf("\nINSIRA UMA POSICAO VALIDA!!\n");
        return 0;
    }
    if(posicao1==1) posicao1 = 0;
    else if(posicao1==3) posicao1 = 4;

    if(posicao2==1) posicao2 = 0;
    else if(posicao2==3) posicao2 = 4;

    if(matriz->jogo[posicao1][posicao2] == 'X' || matriz->jogo[posicao1][posicao2] == 'O') {
        printf("\nLOCAL JA PREENCHIDO!!!\n");
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

    for(i=0; i<5; i+=2){
        if(matriz->jogo[i][0] == 'X')
            igual_X++;
        else if(matriz->jogo[i][0] == 'O')
            igual_O++;
    }
    if(igual_O == 3) return 1;
    igual_O = 0;
    if(igual_X == 3) return 2;
    igual_X = 0;
    
    for(i=0; i<5; i+=2){
        if(matriz->jogo[i][2] == 'X')
            igual_X++;
        else if(matriz->jogo[i][2] == 'O')
            igual_O++;
    }
    if(igual_O == 3) return 1;
    igual_O = 0;
    if(igual_X == 3) return 2;
    igual_X = 0;
    
    for(i=0; i<5; i+=2){
        if(matriz->jogo[i][4] == 'X')
            igual_X++;
        else if(matriz->jogo[i][4] == 'O')
            igual_O++;
    }
    if(igual_O == 3) return 1;
    igual_O = 0;
    if(igual_X == 3) return 2;
    igual_X = 0;
    
    for(i=0; i<5; i+=2){
        if(matriz->jogo[0][i] == 'X')
            igual_X++;
        else if(matriz->jogo[0][i] == 'O')
            igual_O++;
    }
    if(igual_O == 3) return 1;
    igual_O = 0;
    if(igual_X == 3) return 2;
    igual_X = 0;
    
    for(i=0; i<5; i+=2){
        if(matriz->jogo[2][i] == 'X')
            igual_X++;
        else if(matriz->jogo[2][i] == 'O')
            igual_O++;
    }
    if(igual_O == 3) return 1;
    igual_O = 0;
    if(igual_X == 3) return 2;
    igual_X = 0;
    
    for(i=0; i<5; i+=2){
        if(matriz->jogo[4][i] == 'X')
            igual_X++;
        else if(matriz->jogo[4][i] == 'O')
            igual_O++;
    }
    if(igual_O == 3) return 1;
    igual_O = 0;
    if(igual_X == 3) return 2;
    igual_X = 0;
    
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
    if(ganhador == 1) printf("PLAYER (O) GANHOU!!!!!!\n\n");
    else if(ganhador == 2) printf("PLAYER (X) GANHOU!!!!!!\n\n");
    else printf("DEU VELHA!!!\n");
    printf("\n1- Jogar novamente.\n2- Sair.\n");
    scanf("%d", &opcao);
    if(opcao==1) return 1;
    printf("****************************************************************************************\n");
    return 0;
}
int Escolha_Player(){
    int a;
    printf("\n# Qual voce quer?");
    printf("  1)X   2)O\n");
    scanf("%d", &a);
    if(a == 1) return 2;
    else if(a == 2) return 3;   
}