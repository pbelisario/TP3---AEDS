#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matriz.h"
#include "pilha.h"

int main(){
	srand((unsigned) time(NULL)); //para alterar o preenchimento da matriz
	matriz *m = iniciaMatriz();
	setor *jogador = iniciaSetor();
	pilha *p = iniciaPilha();
	preencheMatrizCom01(m);
	imprimeMatriz(m);
	comecaJogo(jogador);
	printf("Posição do jogador : x = %d y = %d\n", getXJogador(jogador), getYJogador(jogador));
	while(!fimDeJogo(jogador)){
		mover(jogador, m, p);
	}
	if(getXJogador(jogador) == 9&& getYJogador(jogador) == 9)	//jogo bem sucedido
		imprimeMatriz(m);
	//imprime o caminho
	free(m);
	free(jogador);
	free(p);
	return 0;
}
