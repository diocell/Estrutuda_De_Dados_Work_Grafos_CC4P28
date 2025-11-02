#ifndef CAMINHO_H
#define CAMINHO_H

// Reconstrói caminho de S até T a partir do vetor pai[]
// Retorna o tamanho do caminho (número de vértices no caminho)
// ou 0 se não houver caminho.
int reconstruir_caminho(int S, int T, const int pai[], int caminho[], int max_len);

// Imprime o caminho reconstruído (ordem S -> ... -> T)
void imprimir_caminho(int S, int T, const int caminho[], int tamanho, const char *rotulo);

#endif
