#include <stdio.h>
#include <stdlib.h>

/*TAD que contem a matriz do jogo.*/
typedef struct{
    char jogo[5][5];
} Matriz;

void Inicializa(Matriz* matriz);
/*Funcao que inicializa o jogo com espacos onde coloca X ou 0 e tracinhos que formam uma hashtag, formato do jogo da velha.*/
int Comeco();
/*Funcao que printa o inicio do jogo.*/
void Print(Matriz* matriz);
/*Funcao que printa a matriz do jogo.*/
int Inserir(Matriz* matriz, char vez, int posicao1, int posicao2);
/*Funcao que insere o caractere do jogador na posicao escolhida.
  Retorna um quando insere e zero quando nao e uma posicao valida ou o local ja esta preenchido.*/
int Check(Matriz* matriz);
/*Funcao que checa se ha espacos vazios.
  Se nao houver quer dizer que esta completamente cheio.
  Retorna um quando cheio e zero quando ainda ha espaco vazio.*/
int Ganhou(Matriz* matriz);
/*Funcao que confere se alguem ganhou.
  Conferindo todas as possibilidades de combinacoes de locais.
  Retornando um se 0 ganhou, dois se X ganhou e zero se ninguem ganhou.*/
int Quem_ganhou(Matriz* matriz);
/*Funcao que printa o resultado do jogo.
  X ganhou, 0 ganhou ou deu velha.
  Dando a opcao de jogar novamente.*/
int Escolha_Player();
/*Funcao que da a opcao de qual caractere comecar.
  X ou 0.*/