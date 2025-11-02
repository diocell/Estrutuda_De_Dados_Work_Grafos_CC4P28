#include <stdio.h>
#include "grafo.h"

int ler_grafo_stdin(int *N, int *S, int *T);

int main(void) {
    int N, S, T;

    if (!ler_grafo_stdin(&N, &S, &T)) {
        fprintf(stderr, "Erro na leitura do grafo.\n");
        return 1;
    }

    printf("Grafo lido com sucesso!\n");
    printf("Vertices: %d\n", N);
    printf("Inicio (S): %d\n", S);
    printf("Objetivo (T): %d\n\n", T);

    grafo_print();

    grafo_free();
    return 0;
}
