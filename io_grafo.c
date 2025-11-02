#include <stdio.h>
#include "grafo.h"

int ler_grafo_stdin(int *N, int *S, int *T) {
    if (scanf("%d", N) != 1) return 0;
    if (scanf("%d %d", S, T) != 2) return 0;

    if (!grafo_init(*N, 0)) {
        fprintf(stderr, "Erro ao inicializar grafo.\n");
        return 0;
    }

    for (int i = 0; i < *N; i++) {
        for (int j = 0; j < *N; j++) {
            int valor;
            if (scanf("%d", &valor) != 1) return 0;
            if (valor == 1)
                grafo_set_aresta(i, j);
        }
    }

    return 1;
}
