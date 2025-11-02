#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "dfs.h"

#define NAO_VISITADO 0
#define VISITADO 1

static int *visitado = NULL;
static int *pai_global = NULL;
static int destino_encontrado = 0;
static int T_global = -1;

// Função recursiva auxiliar
static void dfs_visitar(int atual) {
    if (destino_encontrado) return; // já achou o destino

    visitado[atual] = VISITADO;

    if (atual == T_global) {
        destino_encontrado = 1;
        return;
    }

    int N = grafo_num_vertices();
    for (int v = 0; v < N; v++) {
        if (grafo_existe_aresta(atual, v) && visitado[v] == NAO_VISITADO) {
            pai_global[v] = atual;
            dfs_visitar(v);
        }
    }
}

int dfs_caminho(int S, int T, int pai[]) {
    int N = grafo_num_vertices();
    if (N <= 0) return 0;

    visitado = calloc(N, sizeof(int));
    if (!visitado) return 0;

    for (int i = 0; i < N; i++)
        pai[i] = -1;

    pai_global = pai;
    T_global = T;
    destino_encontrado = 0;

    dfs_visitar(S);

    free(visitado);

    return destino_encontrado;
}
