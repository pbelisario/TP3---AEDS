#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matriz.h"
#include "pilha.h"

int main(){
	int k=0;
	srand((unsigned) time(NULL)); //para alterar o preenchimento da matriz
	matriz *m = iniciaMatriz();
	printf("Matriz iniciada\n");
	setor *jogador = iniciaSetor();
	printf("Setor iniciado\n");
	pilha *p = iniciaPilha();
	preencheMatrizCom01(m);
	imprimeMatriz(m);
	comecaJogo();
	while(!fimDeJogo(jogador)){
		printf("Posição do jogador : x = %d y = %d\n", getXJogador(jogador), getYJogador(jogador));
		mover(jogador, m, p);
	}
}
