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
	setor* set = (setor*) malloc (sizeof(setor));
	return set;
}

matriz* iniciaMatriz() {
	matriz* m = (matriz*) malloc (sizeof(matriz));
	return m;
}

void mover(setor* jogador, matriz* tabuleiro, pilha* movimentos){
	//para mover para a direita é necessário verificar se o jogador nao está no canto direito
	if(jogador->x != (TAM - 1)){
		//se existe caminho que não foi visitado à direita
		if(tabuleiro->tabuleiro[jogador->x + 1][jogador->y].caminho == 1 && tabuleiro->tabuleiro[jogador->x + 1][jogador->y].visitado == 0){
			camada* mov = iniciaCamada();
			preencheCamada(jogador->x, jogador->y, mov);
			empilhar(mov, movimentos);
			jogador->x = jogador->x + 1;
			printf("Moveu para a direita.");
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
		}
	}

	//falta os senao agora
}