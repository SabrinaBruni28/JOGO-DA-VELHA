#include <stdio.h>
#include <stdlib.h>
#include "TerminalFormat.h"

/*TAD que contem a matriz do jogo.*/
typedef struct{
    char jogo[3][3];
} Matriz;

/*Funcao que inicializa o jogo com espacos onde coloca X ou 0 e tracinhos que formam uma hashtag, formato do jogo da velha.*/
void Inicializa(Matriz* matriz);

void Titulo(int n);

int Jogar();

/*Funcao que printa a matriz do jogo.*/
void Imprime(Matriz* matriz);

/*Funcao que insere o caractere do jogador na posicao escolhida.
  Retorna um quando insere e zero quando nao e uma posicao valida ou o local ja esta preenchido.*/
int Inserir(Matriz* matriz, char vez, int posicao);

/*Funcao que checa se há espaços vazios.
  Se não houver quer dizer que está completamente cheio.
  Retorna um quando cheio e zero quando ainda há espaço vazio.*/
int CheckPreenchido(Matriz* matriz);

/*Funcao que confere se alguém ganhou.
  Conferindo todas as possibilidades de combinações de locais.
  Retornando 1 se X ganhou, 2 se O ganhou, 0 se deu velha e -1 se não deu em nada. */
int AlguemGanhou(Matriz* matriz);

/*Funcao que printa o resultado do jogo.
  X ganhou, O ganhou ou deu velha.
  Dando a opção de jogar novamente.*/
int FimJogo(Matriz* matriz);

/*Funcao que da a opção de qual caractere começar.
  X ou 0.*/
int EscolhaPlayer();

char* WhichOne(Matriz* matriz, int i, int j);

int JogarNovamente();

void Asterisco(int n);
int Posicao();
int ERRO(int n);