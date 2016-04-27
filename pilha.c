#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"
#include "matriz.h"
#define TAM 1000

struct Camada{
  int x,y;		//posicoes no tabuleiro
};

struct Pilha{
	camada posicoes[TAM];
	int topo;
};

//Os objetivos das funções estão no header

pilha* iniciaPilha() {
	pilha* p = (pilha*) malloc (sizeof(pilha));
  p->topo = 0;
	return p;
}

camada* iniciaCamada() {
	camada* c = (camada*) malloc (sizeof(camada));
	return c;
}

int pilhaVazia(pilha* p){
	if(p->topo == 0){
		printf("Pilha vazia!\n");
		return 1;
	}
	return 0;
}

int pilhaCheia(pilha* p){
	if(p->topo == TAM){
		printf("Pilha cheia!\n");
		return 1;
	}
	return 0;
}

void empilhar(camada* c, pilha* p){
	if(pilhaCheia(p)){
		//return;
	}
	p->posicoes[p->topo] = *c;
	p->topo++;
}

void desempilhar(pilha* p){
  if(pilhaVazia(p)){
		return;
	}
	p->topo--;
}

void preencheCamada(int x, int y, camada* c){
	c->x = x;
	c->y = y;
}

//gets necessários para acessar variáveis em outros arquivos

int getPosicaoxDaCamadaDaPilha(pilha *p){
  return p->posicoes[p->topo - 1].x;
}

int getPosicaoyDaCamadaDaPilha(pilha *p){
  return p->posicoes[p->topo - 1].y;
}
