#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"
#define TAM 10

struct Camada{
  int x,y;		//posicoes no tabuleiro
};

struct Pilha{
	camada posicoes[TAM];
	int topo = 0;
};

pilha* iniciaPilha() {
	pilha* p = (pilha*) malloc (sizeof(pilha));
	return p;
}

camada* iniciaCamada() {
	camada* c = (camada*) malloc (sizeof(camada));
	return c;
}

int pilhaVazia(pilha* p){
	if(p->topo == 0){
		printf("Pilha vazia!");
		return 1;
	}
	return ;
}

int pilhaCheia(pilha* p){
	if(p->topo == TAM){
		printf("Pilha cheia!");
		return 1;
	}
	return 0;
}

void empilhar(camada* c, pilha* p){
	if(pilhaCheia(p)){
		return;
	}
	p->posicoes[p->topo] = c;
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