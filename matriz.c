#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"
#include "pilha.h"
#define TAM 10

struct Setor{
  int x, y;
  int caminho, visitado;
  //1 = sim, 0 = nao
};

struct Matriz{
	int size;
	setor tabuleiro[TAM][TAM];
};

setor* iniciaSetor() {
  //Objetivo: inicia um setor vazio
	setor* set = (setor*) malloc (sizeof(setor));
	return set;
}

matriz* iniciaMatriz() {
  //Objetivo: inicia uma matriz vazia
	matriz* m = (matriz*) malloc (sizeof(matriz));
	return m;
}

void preencheMatrizCom01(matriz *m){
  //Objetivo : preenche a matriz com 0's e 1's, sendo que a posição inicial é sempre 1
  int i, j;
  for(i=0; i< TAM; i++)
    for(j=0; j< TAM; j++)
      m->tabuleiro[i][j].caminho = rand()%2;
  m->tabuleiro[0][0].caminho = 1; //posição inicial
}

void mover(setor* jogador, matriz* tabuleiro, pilha* movimentos){
  //primeiro marca-se a posicção atual como visitada
  tabuleiro->tabuleiro[jogador->x][jogador->y].visitado = 1;
	//para mover para a direita é necessário verificar se o jogador nao está no canto direito
	if(jogador->x != (TAM - 1)){
		//se existe caminho que não foi visitado à direita
		if(tabuleiro->tabuleiro[jogador->x + 1][jogador->y].caminho == 1 && tabuleiro->tabuleiro[jogador->x + 1][jogador->y].visitado == 0){
			camada* mov = iniciaCamada();
			preencheCamada(jogador->x, jogador->y, mov);
			empilhar(mov, movimentos);
			jogador->x = jogador->x + 1;
			printf("Moveu para a direita.");
      return; //vai para a proxima iteração
		}
	}
	//para mover para baixo é necessário verificar se o jogador nao está no fundo do tabuleiro
	if(jogador->y != (TAM -1)){
		//se existe caminho que não foi visitado para baixo
		if(tabuleiro->tabuleiro[jogador->x][jogador->y + 1].caminho == 1 && tabuleiro->tabuleiro[jogador->x][jogador->y + 1].visitado == 0){
			camada* mov = iniciaCamada();
			preencheCamada(jogador->x, jogador->y, mov);
			empilhar(mov, movimentos);
			jogador->y = jogador->y + 1;
			printf("Moveu para baixo.");
      return; //vai para a proxima iteração
		}
	}
	//para mover para a esquerda é necessário verificar se o jogador nao esta no canto esquerdo
	if(jogador->x != 0){
		//se existe caminho que nao foi visitado para a esquerda
		if(tabuleiro->tabuleiro[jogador->x - 1][jogador->y].caminho == 1 && tabuleiro->tabuleiro[jogador->x - 1][jogador->y].visitado == 0){
			camada* mov = iniciaCamada();
			preencheCamada(jogador->x, jogador->y, mov);
			empilhar(mov, movimentos);
			jogador->x = jogador->x - 1;
			printf("Moveu para a esquerda.");
      return; //vai para a proxima iteração
		}
	}
	//para mover para cima verifica-se se o jogador n esta na primeira linha
	if(jogador->y != 0){
		//se existe caminho que nao foi visitado para cima
		if(tabuleiro->tabuleiro[jogador->x][jogador->y - 1].caminho == 1 && tabuleiro->tabuleiro[jogador->x][jogador->y - 1].visitado == 0){
			camada* mov = iniciaCamada();
			preencheCamada(jogador->x, jogador->y, mov);
			empilhar(mov, movimentos);
			jogador->x = jogador->y - 1;
			printf("Moveu para cima.");
      return; //vai para a proxima iteração
		}
	}
  //as linhas abaixo se referem à não haver uma posição viável para frente
  //nesse caso deve-se voltar uma posição, dado que a posição atual ja foi marcada como visitada
  //lembrando que a posição anterior está na pilha
  jogador->x = getPosicaoxDaCamadaDaPilha(movimentos);
  jogador->y = getPosicaoyDaCamadaDaPilha(movimentos);
}
