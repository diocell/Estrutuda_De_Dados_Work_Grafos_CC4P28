#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "dfs.h"

// Declaração (vem de io_grafo.c)
int ler_grafo_stdin(int *N, int *S, int *T);

// Reconstrói e imprime o caminho
void imprimir_caminho(int S, int T, int pai[]) {
    int caminho[1000];
    int tamanho = 0;
    int atual = T;

    while (atual != -1) {
        caminho[tamanho++] = atual;
        atual = pai[atual];
    }

    printf("Caminho DFS de %d ate %d:\n", S, T);
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%d", caminho[i]);
        if (i > 0) printf(" -> ");
    }
    printf("\nComprimento do caminho: %d arestas\n", tamanho - 1);
}

int main(void) {
    int N, S, T;

    if (!ler_grafo_stdin(&N, &S, &T)) {
        fprintf(stderr, "Erro na leitura do grafo.\n");
        return 1;
    }

    int *pai = malloc(N * sizeof(int));
    if (!pai) {
        fprintf(stderr, "Erro de memoria.\n");
        return 1;
    }

    printf("Executando DFS...\n");
    int achou = dfs_caminho(S, T, pai);

    if (achou) {
        printf("Caminho encontrado!\n\n");
        imprimir_caminho(S, T, pai);
    } else {
        printf("Não existe caminho entre %d e %d.\n", S, T);
    }

    free(pai);
    grafo_free();
    return 0;
}
