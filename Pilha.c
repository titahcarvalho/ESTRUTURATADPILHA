// Created by Angélica on 22/08/2024.

#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

#include <math.h>
#include <string.h>

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
    if(Vazia(*Pilha)){
        printf("Erro: pilha vazia.");
        return;
    } else {
        q = Pilha->topo;
        Pilha->topo = Pilha->topo->prox;
        *Item = q->prox->item;
        free(q);
        Pilha->tamanho--;
      }
}
void LerProdutoPilha(TProduto *Item){
    printf("\n----------------------------------" );
    printf("\nOpcao 'Inserir Produto' selecionado.\n" );
    printf("\nDigite o codigo do produto:" );
    scanf("%d",&Item->codigo);
    getchar();
    printf("\nDigite a descricao do produto:");
    fgets(Item->descricao,100,stdin);
    printf("\nDigite o nome do produto:");
    fgets(Item->nome,100,stdin);
    printf("\nDigite a quantidade do produto em estoque:");
    scanf("%d",&Item->quantidade);
    getchar();
    printf("\nDigite o valor do produto:");
    scanf("%f",&Item->preco);
    getchar();

}
void ImprimirProduto(TProduto Item){
    printf("Nome:%s", Item.nome);
    printf("Nome:%s", Item.descricao);
    printf("Nome:%d", Item.codigo);
    printf("Nome:%.2f",Item.valor);
}
void ImprimirPilha(TPilha *Pilha){
	TProduto x;
	TPilha FAux;
	FPVazia(&FAux);
	int n = Pilha->tamanho;
	for(int i = 0; i<n; i++){
		Desempilhar(Pilha,&x);
		ImprimirProduto(x);
		Empilhar(&FAux, x);
		}
	while(!Vazia(FAux)) {
		Desempilhar(&FAux, &x);
		Empilhar(Pilha, x);
	}
		free(&FAux);
	}
void LiberarPilha(TPilha *Pilha){
	TProduto x;
	while(!Vazia(*Pilha)){
		Desempilhar(Pilha, &Pilha->topo->prox->item);

		free(Pilha->fundo);

}
int PesquisarPilha(TPilha *Pilha, TProduto *Item);
	TPilha PAux;
	FPVazia(&PAux);
	TProduto x;
	int flag = 0;
	while(!Vazia(*Pilha)){
		Desempilhar(&Pilha, &x);
		Empilhar(&x,&PAux);
	}
	while(!Vazia(PAux)){
		Desempilhar(&PAux,&x);
		Empilhar(x,Pilha);
	}
	if(flag == 0){
		item.codigo = -1;
	}
	return flag;
}
//QUESTÃO 1---------------------------------------------------------------------------------------------------------
void InverterPilha(TPilha *Pilha){
	TPilha Aux;
	FPVazia(&Aux);
	TProduto x;

	while (!Vazia(*Pilha)) {
		Desempilhar(Pilha, &x);
		Empilhar(&Aux, x);
	}
	// ImprimirPilha(&Aux);
	while (!Vazia(Aux)) {
		Desempilhar(&Aux, &x);
		Empilhar(Pilha, x);
	}
	free(Aux.topo);
}
// QUESTÃO 2 ---------------------------------------------------------------------------------------------------------
void ConverterBinárioInverso(TPilha *Pilha, int n){
	FPVazia(Pilha);
	TProduto x;
	while(n > 0){
		x = n%2;
		Empilhar(Pilha, x);
		n = n/2;
	}
	while(!Vazia(*Pilha)){
		Desempilhar(Pilha, &x);
		ImprimirPilha(Pilha);
	}
}

// QUESTÃO 3 ---------------------------------------------------------------------------------------------------------
void TorreHanoi(TPilha *Pilha, TCelula disco) {
	TPilha* Aux;
	TPilha* Destino;
	FPVazia(&Aux);
	FPVazia(&Destino);
	int n; //numero total de movimentos
	n = (1 << disco) -1; //operador de deslocamento para a exponenciação ou biblioteca POW em math.h
	if(disco%2 == 0) {
		TPilha* temp = Destino;
		Destino = Aux;
		Aux = temp;

		printf("O n° de movimentos total pela quantidade par de discos é %d", n);

	} else {
		printf("O n° de movimentos total pela quantidade ímpar de discos é %d", n);
	}
	for(int i = 1; i <= n; i++)  {
		if(i%3 == 1) {
			TCelula topo = Desempilhar(Pilha);
			Empilhar(Destino, topo); // movimentar entre Pilha e Destino se i % 1 == 1
		} else if (i%3 == 2) {
			TCelula topo = Desempilhar(Pilha);
			Empilhar(Aux, topo);
		} else if (i%3 == 0) {
			TCelula topo = Desempilhar(Aux);
			Empilhar(Destino, topo);
		}

	}

}

// QUESTÃO 4 ---------------------------------------------------------------------------------------------------------
/*int maiorSubString(char expressao[]) {
	int n = strlen(expressao);
	int maxLen = 0;

	TPilha Pilha;
	FPVazia(&Pilha);
	TProduto x;
	x.nome[0] = -1;
	x.nome[1] = '\0';
	Empilhar(&Pilha,x);

	for(int i = 0; i<n; i++) {
		TProduto y;
		y.nome[0] = expressao;
		y.nome[1] = '\0';
		if(expressao[i] == '(') {
			Empilhar(&Pilha, y);
		}else if(expressao[i] == ')') {
			if(Vazia(Pilha)) {
				y.nome[0] = i;
				Empilhar(&Pilha,y);
			} else {
				TProduto z;
				Desempilhar(&Pilha, z);
				if(Vazia(Pilha)) {
					y.nome[0] = i;
					Empilhar(&Pilha,z);
				}else {
					int lenAtual = i - z.nome[0];
					if(lenAtual>maxLen) {
						maxLen>lenAtual;
					}
				}
			}
		}
	}

}*/
//QUESTÃO 4 ---------------------------------------------------------------------------------------------------------
void QuantParenteses(char expressao[]) {
	TPilha Pilha1;
	FPVazia(&Pilha1);

	TProduto x;
	int flag = 0;
	int t = strlen(expressao);
	int parentEsquerda=0;
	int parentesquerdaDesempilha=0;
	int parentDireita=0;
	int parentDireitaDesempilha=0;
	for(int i = 0; i<t;i++) {
		if(expressao[i] == '(') {
			parentDireita++;
		} else if(expressao[i]==')') {
			parentEsquerda++;
		}
	}
	if(parentDireita != parentEsquerda) {
		if(parentEsquerda < parentDireita) {
			parentDireita = parentEsquerda;
		}else {
			parentEsquerda = parentDireita;
		}
	}
	for(int i = 0; i<t; i++) {
		x.nome = expressao[i];
		if(expressao[i] == '(' && parentesquerdaDesempilha < parentEsquerda) {
			Empilhar(x, &Pilha1);
			parentesquerdaDesempilha++;
			flag = 1;
		} else if(expressao[i] == ')' && parentDireitaDesempilha < parentDireita) {
			Empilhar(x,&Pilha1);
			parentDireitaDesempilha++;
		}
	}
	printf("\Saída: %d\n", (parentesquerdaDesempilha+parentDireitaDesempilha));
	ImprimirPilha(&Pilha1);
	LiberarPilha(&Pilha1);
}

// QUESTÃO 5 ---------------------------------------------------------------------------------------------------------
