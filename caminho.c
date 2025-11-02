#include <stdio.h>
#include "caminho.h"

// Reconstrói caminho partindo de T até S, e depois inverte a ordem
int reconstruir_caminho(int S, int T, const int pai[], int caminho[], int max_len) {
    int tamanho = 0;
    int atual = T;

    while (atual != -1 && tamanho < max_len) {
        caminho[tamanho++] = atual;
        atual = pai[atual];
    }

    if (tamanho == 0 || caminho[tamanho - 1] != S)
        return 0; // não chegou até S → sem caminho

    // Inverter ordem (de S -> ... -> T)
    for (int i = 0; i < tamanho / 2; i++) {
        int tmp = caminho[i];
        caminho[i] = caminho[tamanho - 1 - i];
        caminho[tamanho - 1 - i] = tmp;
    }

    return tamanho;
}

void imprimir_caminho(int S, int T, const int caminho[], int tamanho, const char *rotulo) {
    if (tamanho == 0) {
        printf("Não existe caminho entre %d e %d.\n", S, T);
        return;
    }

    printf("\n=== CAMINHO %s ===\n", rotulo ? rotulo : "");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", caminho[i]);
        if (i < tamanho - 1) printf(" -> ");
    }
    printf("\nComprimento do caminho: %d arestas\n\n", tamanho - 1);
}
