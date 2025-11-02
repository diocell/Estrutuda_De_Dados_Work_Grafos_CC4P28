#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "bfs.h"

#define INF -1

// Implementação da busca em largura (BFS) para caminho mínimo
int bfs_caminho(int S, int T, int pai[]) {
    int N = grafo_num_vertices();
    if (N <= 0) return 0;

    int *visitado = calloc(N, sizeof(int));
    if (!visitado) return 0;

    for (int i = 0; i < N; i++)
        pai[i] = INF;

    int *fila = malloc(N * sizeof(int));
    if (!fila) {
        free(visitado);
        return 0;
    }

    int inicio = 0, fim = 0;

    // Enfileira vértice inicial
    fila[fim++] = S;
    visitado[S] = 1;
    pai[S] = -1; // sem predecessor

    while (inicio < fim) {
        int atual = fila[inicio++];

        if (atual == T) {
            free(fila);
            free(visitado);
            return 1; // Encontrou destino
        }

        for (int v = 0; v < N; v++) {
            if (grafo_existe_aresta(atual, v) && !visitado[v]) {
                visitado[v] = 1;
                pai[v] = atual;
                fila[fim++] = v;
            }
        }
    }

    free(fila);
    free(visitado);
    return 0; // Não há caminho
}
