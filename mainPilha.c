#include "Pilha.h"
#include "Pilha.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

    int escolha = 0;
    TProduto x,y;
    TPilha P1;
    FPVazia(&P1);

    while(escolha != 4 ){
        printf("\n|| MENU ||\n");
        printf("|1| Empilhar produtos:\n");
        printf("|2| Pesquisar um produto:\n");
        printf("|3| Imprimir produtos.\n");
        printf("|4| Sair.\n");
        printf("Escolha uma das acoes:");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                LerProdutoPilha(&x);
                Empilhar(x, P1);
            break;

            case 2:
                printf("\nDigite o codigo para pesquisar um produto especifico:");
                scanf("%d", &y.codigo);
            int p = PesquisarPilha(&P1, &y);

            if (p) {
                printf("\nProduto %d encontrado!", y.codigo);
                printf("\nNome: %s", y.nome);
                printf("\nDescricao: %s", y.descricao);
                printf("\nQuantidade: %d", y.quantidade);
                printf("\nValor: $%.2f", y.preco);
            }
            printf("Produto %d nao encontrado.", y.codigo);

            break;

            case 3:
                printf("\n----------------------- Produtos na Pilha:-----------------------");
                ImprimirPilha(&P1);
            break;
            case 4:

            break;
            case 5:

                printf("\nEncerrando...aperta no enter para fechar a Tela");
            LiberarPilha(&P1);
            break;

            default:
                printf("\nOpcao invalida. Tente novamente.");
            break;
        }
    }

    return 0;
}
