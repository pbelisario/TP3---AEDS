#ifndef MATRIZ_H
#define MATRIZ_H

#include "pilha.h"

typedef struct Setor setor;
typedef struct Matriz matriz;

//funções para jogador
void mover(setor*, matriz*, pilha*);

//Verifica se há posições disponíveis. Se sim,muda as coordenadas do setor para a  posição. Se não, retorna a anterior
//Caso a anterior seja 0,0 e não existam mais posições possíveis ,para a execução

void comecaJogo(setor* jogador);
//posiciona o jogador na primeira posição

//Funções para tabuleiro
matriz* iniciaMatriz();
//cria uma matriz
void preencheMatrizCom01(matriz *m);
//preenche a matriz com 0's e 1's

//Funções de utilidade
setor* iniciaSetor(void);
//cria um setor

int fimDeJogo(setor* jogador);
//indica se o jogo terminou
#endif
