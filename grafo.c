#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

static int **matriz = NULL;
static int n_vertices = 0;
static int eh_direcionado = 0;

int grafo_init(int N, int direcionado) {
    if (N <= 0) return 0;

    n_vertices = N;
    eh_direcionado = direcionado;

    matriz = malloc(N * sizeof(int *));
    if (!matriz) return 0;

    for (int i = 0; i < N; i++) {
        matriz[i] = calloc(N, sizeof(int));
        if (!matriz[i]) return 0;
    }
    return 1;
}

void grafo_set_aresta(int i, int j) {
    if (!matriz || i < 0 || j < 0 || i >= n_vertices || j >= n_vertices) return;

    matriz[i][j] = 1;
    if (!eh_direcionado)
        matriz[j][i] = 1;
}

int grafo_existe_aresta(int i, int j) {
    if (!matriz || i < 0 || j < 0 || i >= n_vertices || j >= n_vertices)
        return 0;
    return matriz[i][j];
}

int grafo_num_vertices(void) {
    return n_vertices;
}

void grafo_print(void) {
    if (!matriz) return;
    printf("Matriz de adjacencia (%d vertices):\n", n_vertices);
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void grafo_free(void) {
    if (!matriz) return;
    for (int i = 0; i < n_vertices; i++)
        free(matriz[i]);
    free(matriz);
    matriz = NULL;
    n_vertices = 0;
}
