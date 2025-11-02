#ifndef BFS_H
#define BFS_H

// Executa BFS a partir de S até T
// Retorna 1 se encontrou caminho, 0 caso contrário.
// Preenche o vetor pai[v] com o predecessor de v no caminho.
int bfs_caminho(int S, int T, int pai[]);

#endif
