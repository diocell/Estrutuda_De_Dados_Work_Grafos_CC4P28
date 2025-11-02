# 🌳 Estrutura de Dados – Trabalho CC4P28 – GRAFOS

Trabalho desenvolvido para a disciplina Estrutura de Dados (CC4P28), com o objetivo de compreender, implementar e comparar os algoritmos de busca em grafos:
BFS (Busca em Largura) e DFS (Busca em Profundidade).

O problema baseia-se em um labirinto representado por grafo, onde cada vértice é uma célula caminhável e cada aresta indica uma ligação entre células.
O programa principal permite ler o grafo, encontrar caminhos entre dois vértices e comparar os resultados obtidos pelos dois métodos de busca.

## 🚀 Compilação e Execução

### 🔹 Teste de leitura da matriz de adjacência
```bash
gcc -Wall -Wextra -O2 -Iinclude src/teste_leitura.c src/grafo.c src/io_grafo.c -o teste_leitura.exe
.\teste_leitura.exe
```

### 🔹 Caminho mínimo com BFS (Busca em Largura)
```bash
gcc -Wall -Wextra -O2 -Iinclude src/teste_bfs.c src/bfs.c src/grafo.c src/io_grafo.c -o teste_bfs.exe
.\teste_bfs.exe
```

### 🔹 Caminho qualquer com DFS (Busca em Profundidade)
```bash
gcc -Wall -Wextra -O2 -Iinclude src/teste_dfs.c src/dfs.c src/grafo.c src/io_grafo.c -o teste_dfs.exe
.\teste_dfs.exe
```

### 🔹 Programa Integrado – Menu do Labirinto
```bash
gcc -Wall -Wextra -O2 -Iinclude src/labirinto.c src/bfs.c src/dfs.c src/grafo.c src/io_grafo.c src/caminho.c -o labirinto.exe
.\labirinto.exe
```

💡 Obs.:
Para testar com os arquivos .in, execute no Prompt de Comando (CMD):

```bash
labirinto.exe < testes\teste_simples.in
```

## 🧪 Conjuntos de Testes

### 🔸 Teste 1 — Grafo simples e conexo
Arquivo: testes/teste_simples.in
Resultado esperado:
BFS → 0 → 2 → 3 → 5 (3 arestas)
DFS → 0 → 1 → 3 → 5 (3 arestas)

### 🔸 Teste 2 — Múltiplos caminhos
Arquivo: testes/teste_multiplos.in
Resultado esperado:
BFS → 0 → 2 → 4 → 6 (3 arestas)
DFS → 0 → 1 → 3 → 5 → 6 (4 arestas)

### 🔸 Teste 3 — Sem caminho viável
Arquivo: testes/teste_sem_caminho.in
Resultado esperado:
BFS → “Nenhum caminho encontrado.”
DFS → “Nenhum caminho encontrado.”


👥 Integrantes
🔹Diogo Canevarollo – G88EGH6
🔹Igor Beltramello – G058AI0
