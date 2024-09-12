// Created by Angélica on 22/08/2024.
#ifndef PILHA_H
#define PILHA_H

typedef struct {
    char nome [100];
    char descricao[100];
    int  codigo;
    int quantidade;
    float preco;
    float valor;
}TProduto;

typedef struct celula {
    TProduto item;
    struct celula* prox;
} TCelula;

typedef struct pilha{
    TCelula* topo;
    TCelula* fundo;
    int tamanho;
}TPilha;

void FPVazia(TPilha *Pilha);
int Vazia(TPilha Pilha);
void Empilhar(TPilha *Pilha, TProduto x);
void Desempilhar(TPilha *Pilha, TProduto *Item);
void LerProdutoPilha(TProduto *Item);
void ImprimirProduto(TProduto Item);
void ImprimirPilha(TPilha *Pilha);
void LiberarPilha(TPilha *Pilha);
int PesquisarPilha(TPilha *Pilha, TProduto *Item);
void InverterPilha(TPilha *Pilha);
void ConverterBinárioInverso(TPilha *Pilha, int n);
void TorreHanoi(TPilha *Pilha, TCelula disco);
int maiorSubString(char expressao[]);


#endif //PILHA_H
