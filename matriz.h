#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct Setor setor;
typedef struct Matriz matriz;

//funções para jogador
void mover(setor*, matriz*);
/*
*Verifica se há posições disponíveis. Se sim,muda as coordenadas do setor para a  posição. Se não, retorna a anterior
*Caso a anterior seja 0,0 e não existam mais posições possíveis ,para a execução
*/
setor* iniciaSetor(void);
//cria um setor

//Funções para tabuleiro
matriz* iniciaMatriz();
//cria uma matriz
void preencheMatriz(matriz*);
//preenche a matriz com os valores que se deseja
#endif