#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matriz.h"
#include "pilha.h"

int main(){
	srand((unsigned) time(NULL)); //para alterar o preenchimento da matriz
	matriz *testem = iniciaMatriz();
	printf("Matriz iniciada\n");
	setor *testes = iniciaSetor();
	printf("Setor iniciado\n");
	preencheMatrizCom01(testem);
	imprimeMatriz(testem);
	
}
