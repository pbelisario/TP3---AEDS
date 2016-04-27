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

void comecaJogo(setor* jogador){
	jogador->x = 0;
	jogador->y = 0;
}

matriz* iniciaMatriz() {
  //Objetivo: inicia uma matriz vazia
	matriz* m = (matriz*) malloc (sizeof(matriz));
	return m;
}

void preencheMatrizCom01(matriz *m){
  //Objetivo : preenche a matriz com 0's e 1's, sendo que a posição inicial é sempre 1
  int i, j, r;
  for(i=0; i< TAM; i++)
    for(j=0; j< TAM; j++){
      r = rand()%10;
      //chance de ter caminho é maior
      if(r<8)
        m->tabuleiro[i][j].caminho = 1;
      else
        m->tabuleiro[i][j].caminho = 0;
    }
  m->tabuleiro[0][0].caminho = 1; //posição inicial
}

void mover(setor* jogador, matriz* tabuleiro, pilha* movimentos){
	//Objetivo: Realizar o movimento do jogador no jogo
  //primeiro marca-se a posicção atual como visitada
  tabuleiro->tabuleiro[jogador->x][jogador->y].visitado = 1;
	//para mover para baixo é necessário verificar se o jogador nao está no canto de baixo
	if(jogador->x != (TAM - 1)){
		//se existe caminho que não foi visitado a baixo
		if(tabuleiro->tabuleiro[jogador->x + 1][jogador->y].caminho == 1 && tabuleiro->tabuleiro[jogador->x + 1][jogador->y].visitado == 0){
			//salva a posição atual na pilha
			camada* mov = iniciaCamada();
			preencheCamada(jogador->x, jogador->y, mov);
			empilhar(mov, movimentos);
			jogador->x = jogador->x + 1;
			printf("Moveu para baixo.\n");
      return; //vai para a proxima iteração
		}
	}
	//para mover para a direita é necessário verificar se o jogador nao está no canto esquerdo
	if(jogador->y != (TAM -1)){
		//se existe caminho que não foi visitado para a direita
		if(tabuleiro->tabuleiro[jogador->x][jogador->y + 1].caminho == 1 && tabuleiro->tabuleiro[jogador->x][jogador->y + 1].visitado == 0){
			//salva a posição atual na pilha
			camada* mov = iniciaCamada();
			preencheCamada(jogador->x, jogador->y, mov);
			empilhar(mov, movimentos);
			jogador->y = jogador->y + 1;
			printf("Moveu para a direita.\n");
      return; //vai para a proxima iteração
		}
	}
	//para mover para a cima é necessário verificar se o jogador nao esta no canto de cima
	if(jogador->x != 0){
		//se existe caminho que nao foi visitado para cima
		if(tabuleiro->tabuleiro[jogador->x - 1][jogador->y].caminho == 1 && tabuleiro->tabuleiro[jogador->x - 1][jogador->y].visitado == 0){
			camada* mov = iniciaCamada();
			preencheCamada(jogador->x, jogador->y, mov);
			empilhar(mov, movimentos);
			jogador->x = jogador->x - 1;
			printf("Moveu para cima.\n");
      return; //vai para a proxima iteração
		}
	}
	//para mover para a esquerda verifica-se se o jogador n esta na primeira coluna
	if(jogador->y != 0){
		//se existe caminho que nao foi visitado para a esquerda
		if(tabuleiro->tabuleiro[jogador->x][jogador->y - 1].caminho == 1 && tabuleiro->tabuleiro[jogador->x][jogador->y - 1].visitado == 0){
			camada* mov = iniciaCamada();
			preencheCamada(jogador->x, jogador->y, mov);
			empilhar(mov, movimentos);
			jogador->y = jogador->y - 1;
			printf("Moveu para a esquerda.\n");
      return; //vai para a proxima iteração
		}
	}
  //as linhas abaixo se referem à não haver uma posição viável para frente
  //nesse caso deve-se voltar uma posição, dado que a posição atual ja foi marcada como visitada
  //lembrando que a posição anterior está na pilha
  //caso a posição atual seja (0, 0), ou seja, pilhaVazia=1, não faz sentido voltar
  if(pilhaVazia(movimentos)){
  	printf("Não existem mais posições disponíveis.\nFim de jogo.\n");
    jogador->x = -1; //atribui esse valor para indicar termino do jogo
  	return;
  }
  jogador->x = getPosicaoxDaCamadaDaPilha(movimentos);
  jogador->y = getPosicaoyDaCamadaDaPilha(movimentos);
  printf("Jogador voltou uma posição.\n");
  desempilhar(movimentos);
}

void imprimeMatriz(matriz* m){
	//Objetivo: Verificar graficamente se a matriz foi preenchida corretamente
	int i, j;
	for(i=0; i< TAM; i++){
		for(j=0; j< TAM; j++){
      if(m->tabuleiro[i][j].visitado == 1)
        printf("*  ");
      else
			   printf("%d  ", m->tabuleiro[i][j].caminho);
		}
		printf("\n");
	}
}

int fimDeJogo(setor* jogador){
	//Objetivo: Retorna 1 se o jogo tiver acabado e 0 senao
	if(jogador->x == (TAM-1) && jogador->y==(TAM - 1)){
		printf("O jogador alcançou o fim do jogo.\n");
		return 1;
	}
  else{
    if(jogador->x == -1){
      printf("Não há caminhos possíveis para se vencer o jogo.\n");
      return 1;   //-1 pois é uma posição inexistente que estou usando para mostrar que acabou
    }
  }
	return 0;
}


//gets utilizados para acessar valores em outros arquivos
int getXJogador(setor* jogador){
	return jogador->x;
}

int getYJogador(setor* jogador){
	return jogador->y;
}
