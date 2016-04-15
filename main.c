#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"
#include "pilha.h"

int main(){
	matriz *testem = iniciaMatriz();
	printf("Matriz iniciada\n");
	setor *testes = iniciaSetor();
	printf("Setor iniciado\n");
	preencheMatrizCom01(testem);
}
