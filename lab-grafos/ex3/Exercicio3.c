// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 100

// // Função para exibir as arestas ponderadas do grafo
// void arestasPonderadas(int n, int adj[][MAX]) {
//     printf("Arestas do grafo com pesos:\n");
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {  // Arestas não repetidas (grafo simples)
//             if (adj[i][j] != 0) {  // Se houver uma aresta (peso diferente de 0)
//                 printf("(%d, %d) - Peso: %d\n", i, j, adj[i][j]);
//             }
//         }
//     }
// }

// int main() {
//     int n;
//     int adj[MAX][MAX];
//     FILE *file = fopen("Ex3.txt", "r");

//     if (file == NULL) {
//         printf("Erro ao abrir o arquivo! Certifique-se de que 'Ex3.txt' está no diretório correto.\n");
//         return 1;
//     }

//     // Lê o número de vértices
//     if (fscanf(file, "%d", &n) != 1) {
//         printf("Erro ao ler o número de vértices do arquivo.\n");
//         fclose(file);
//         return 1;
//     }

//     // Lê a matriz de adjacência do arquivo
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (fscanf(file, "%d", &adj[i][j]) != 1) {
//                 printf("Erro ao ler a matriz de adjacência.\n");
//                 fclose(file);
//                 return 1;
//             }
//         }
//     }

//     fclose(file);

//     // Exibe as arestas ponderadas
//     arestasPonderadas(n, adj);

//     return 0;
// }
