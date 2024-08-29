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
	TPilha FAux, FPVazia(&FAux);
	int n = Pilha->tamanho;
	for(int i = 0; i<n; i++){
		Desempilhar(Pilha,&FAux);
		ImprimirProduto(x);
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
void InverterPilha(TPilha *Pilha){
	TPilha* Aux;
	FPVazia(&Aux);
	TProduto x;

	while(!Vazia(*Pilha)){
		Desempilhar(Pilha, &x);
		Empilhar(x, &Aux);
	}
	ImprimirPilha(&Aux);
	while(!Vazia(*Aux)){
		Desempilhar(&Aux, &x);
		Empilhar(x, Pilha);
}
	free(Aux.topo);
}
void ConverterBinárioInverso(TPilha *Pilha, int n){
	FPVazia(Pilha);
	TProduto x;
	while(n > 0){
		x = n%2;
		Empilhar(Pilha, x);
		n = n/2;
	}
	while(!Vazia(Pilha)){
		Desempilhar(x, Pilha);
		ImprimirPilha(Pilha);


	}
}



/*    for(int i = 0; i < n ;i++) {
        Desenfileirar(Fila, binario);

        strcpy(binario2, binario); //binario2 = binario;
        strcat(binario,"0");
        printf("%s\n", binario);

        strcpy(binario, binario2); //binario = binario2;
        strcat(binario, "1");
        printf("%s\n", binario);

        Enfileirar(binario2, Fila);*/
	if(n == 0){
		printf("%d", n);
	} else {
		printf("%d", n%2);
	}



}