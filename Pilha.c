// Created by Angélica on 22/08/2024.

#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

void FPVazia(TPilha *Pilha){
    Pilha->topo = (TCelula*)malloc(sizeof(TCelula));
    Pilha->fundo = Pilha->topo;
    Pilha->topo->prox = NULL;
    Pilha->tamanho = 0;
}
int Vazia(TPilha Pilha){
    return (Pilha.topo == Pilha.fundo);
}
void Empilhar(TPilha *Pilha, TProduto x){
    TCelula* Aux = (TCelula*)malloc(sizeof(TCelula));
    Pilha->topo->item = x;
    Aux->prox = Pilha->topo;
    Pilha->topo = Aux;
    Pilha->tamanho++;
}

void Desempilhar(TPilha *Pilha, TProduto *Item){
    TCelula* q;
    if(Vazia(*Pilha){
        printf("Erro: pilha vazia.");
        return;
    } else {
        q = Pilha->topo;
        Pilha->topo = Pilha->topo->prox;
        *Item = q->prox->item;
        free(q);
        Pilha->tamnho--;
      }
}
void ImprimirProduto(TProduto Item){
    printf("Nome:%s", Item.nome);
    printf("Nome:%s", Item.descricao);
    printf("Nome:%d", Item.codigo);
    printf("Nome:%.2f",Item.valor);
}
void ImprimirPilha(TPilha *Pilha){
	TProduto x;
	TPilha FAux, FPVazia(&FAux);
	int n = Pilha->tamanho;
	for(int i = 0; i<n; i++){
		Desempilha(Pilha,FAux);
		ImprimirProduto(x);
		}
		free(FAux);
	}
void LiberarPilha(TPilha *Pilha){
	TProduto x;
	while(!Vazia(Pilha){
		Desempilha(Pilha, &Pilha->topo->prox->item);

		free(Pilha->fundo);

}
int PesquisarPilha(TPilha *Pilha, TProduto *Item){
	TPilha PAux;
	FPVazia(&PAux);
	TProduto x;
	int flag = 0;
	while(!Vazia(*Pilha){
		Desempilhar(&Pilha, &x);
		Empilhar(x,&PAux);
	}
	while(!Vazia(PAux){
		Desempilhar(&PAux,&x);
		Empilhar(x,Pilha);
	}
	if(flag == 0){
		Item.codigo = -1;
	}
	return flag;
}