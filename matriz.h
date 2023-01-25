#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char jogo[5][5];
} Matriz;

void Inicializa(Matriz* matriz);
void Print(Matriz* matriz);
int Inserir(Matriz* matriz, char vez, int posicao1, int posicao2);
int Check(Matriz* matriz);
int Ganhou(Matriz* matriz);
int Quem_ganhou(Matriz* matriz);
int Comeco();
int Escolha_Player();