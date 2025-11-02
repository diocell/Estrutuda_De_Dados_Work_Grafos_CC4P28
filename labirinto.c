#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "bfs.h"
#include "dfs.h"
#include "caminho.h"

// Declaração (vem de io_grafo.c)
int ler_grafo_stdin(int *N, int *S, int *T);

#define MAX_VERTICES 1000

// Estrutura para armazenar último caminho encontrado
typedef struct {
    int tipo; // 0 = nenhum, 1 = BFS, 2 = DFS
    int S, T;
    int pai[MAX_VERTICES];
    int comprimento;
    int visitados;
    int encontrado;
} CaminhoInfo;

int main(void) {
    int N, S, T;
    if (!ler_grafo_stdin(&N, &S, &T)) {
        fprintf(stderr, "Erro na leitura do grafo.\n");
        return 1;
    }

    CaminhoInfo info = {0};
    info.S = S;
    info.T = T;

    int opcao;

    do {
        printf("\n=== LABIRINTO (GRAFO) ===\n");
        printf("1. Imprimir matriz de adjacencia\n");
        printf("2. Executar BFS (caminho minimo)\n");
        printf("3. Executar DFS (um caminho)\n");
        printf("4. Mostrar ultimo caminho encontrado\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        if (scanf("%d", &opcao) != 1) break;

        switch (opcao) {
            case 1:
                printf("\n");
                grafo_print();
                break;

            case 2: {
                printf("\nExecutando BFS de %d ate %d...\n", S, T);
                int *pai = malloc(N * sizeof(int));
                if (!pai) {
                    fprintf(stderr, "Erro de memoria.\n");
                    break;
                }

                int achou = bfs_caminho(S, T, pai);
                info.tipo = 1;
                info.encontrado = achou;
                info.visitados = N; // estimativa
                info.comprimento = 0;

                if (achou) {
                    for (int i = 0; i < N; i++)
                        info.pai[i] = pai[i];

                    int caminho[MAX_VERTICES];
                    int tamanho = reconstruir_caminho(S, T, pai, caminho, MAX_VERTICES);
                    info.comprimento = tamanho - 1;

                    imprimir_caminho(S, T, caminho, tamanho, "BFS (minimo)");
                } else {
                    printf("Nenhum caminho encontrado via BFS.\n");
                }

                free(pai);
                break;
            }

            case 3: {
                printf("\nExecutando DFS de %d ate %d...\n", S, T);
                int *pai = malloc(N * sizeof(int));
                if (!pai) {
                    fprintf(stderr, "Erro de memoria.\n");
                    break;
                }

                int achou = dfs_caminho(S, T, pai);
                info.tipo = 2;
                info.encontrado = achou;
                info.visitados = N; // estimativa
                info.comprimento = 0;

                if (achou) {
                    for (int i = 0; i < N; i++)
                        info.pai[i] = pai[i];

                    int caminho[MAX_VERTICES];
                    int tamanho = reconstruir_caminho(S, T, pai, caminho, MAX_VERTICES);
                    info.comprimento = tamanho - 1;

                    imprimir_caminho(S, T, caminho, tamanho, "DFS (qualquer)");
                } else {
                    printf("Nenhum caminho encontrado via DFS.\n");
                }

                free(pai);
                break;
            }

            case 4:
                if (info.tipo == 0 || !info.encontrado) {
                    printf("\nNenhum caminho encontrado ainda.\n");
                } else {
                    int caminho[MAX_VERTICES];
                    int tamanho = reconstruir_caminho(info.S, info.T, info.pai, caminho, MAX_VERTICES);
                    imprimir_caminho(info.S, info.T, caminho, tamanho,
                                     info.tipo == 1 ? "BFS (minimo)" : "DFS (qualquer)");
                    printf("Nos visitados (estimado): %d\n", info.visitados);
                }
                break;

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    grafo_free();
    return 0;
}
