#ifndef GRAFO_H
#define GRAFO_H

// Inicializa um grafo com N vértices
// direcionado = 0 → não direcionado; 1 → direcionado
int grafo_init(int N, int direcionado);

// Define uma aresta entre i e j
void grafo_set_aresta(int i, int j);

// Verifica se existe aresta entre i e j
int grafo_existe_aresta(int i, int j);

// Retorna o número de vértices
int grafo_num_vertices(void);

// Imprime a matriz de adjacência
void grafo_print(void);

// Libera memória alocada
void grafo_free(void);

#endif
