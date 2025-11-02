#ifndef DFS_H
#define DFS_H

// Executa DFS de S até T (recursiva ou iterativa)
// Retorna 1 se encontrou caminho, 0 caso contrário
// Preenche o vetor pai[v] com o predecessor de v no caminho.
int dfs_caminho(int S, int T, int pai[]);

#endif
