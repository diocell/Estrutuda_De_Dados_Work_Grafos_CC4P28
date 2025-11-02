#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "bfs.h"
#include "locale.h"

// Declaração (vem de io_grafo.c)
int ler_grafo_stdin(int *N, int *S, int *T);

// Função auxiliar: reconstrói e imprime o caminho usando o vetor pai[]
void imprimir_caminho(int S, int T, int pai[]) {
    setlocale(LC_ALL, "");

    int caminho[1000];
    int tamanho = 0;
    int atual = T;

    // Reconstroi caminho do destino até a origem
    while (atual != -1) {
        caminho[tamanho++] = atual;
        atual = pai[atual];
    }

    // Caminho foi construído de trás pra frente → inverter
    printf("Caminho BFS de %d ate %d:\n", S, T);
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
        fprintf(stderr, "Erro de memória.\n");
        return 1;
    }

    printf("Executando BFS...\n");
    int achou = bfs_caminho(S, T, pai);

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
