// #include <stdio.h>

// #define MAX 100

// // Função para completar a matriz de adjacência
// void completarMatriz(int n, int adj[][MAX]) {
//     // Preencher a parte superior da matriz aproveitando a simetria
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < i; j++) {
//             adj[j][i] = adj[i][j]; // Atribui o valor simétrico
//         }
//     }

//     // Exibir a matriz completa
//     printf("Matriz completa:\n");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("%d ", adj[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     int n;
//     FILE *file = fopen("Ex4.txt", "r"); // Abrindo o arquivo para leitura

//     if (file == NULL) {
//         printf("Erro ao abrir o arquivo.\n");
//         return 1;
//     }

//     // Lendo a dimensão da matriz
//     if (fscanf(file, "%d", &n) != 1) {
//         printf("Erro ao ler a dimensão da matriz.\n");
//         fclose(file);
//         return 1;
//     }

//     printf("Número de vértices: %d\n", n);  // Debug: Verificando se a dimensão foi lida corretamente

//     int adj[MAX][MAX];

//     // Lendo a matriz triangular inferior do arquivo
//     for (int i = 0; i < n; i++) {
//         printf("Lendo linha %d\n", i + 1);  // Debug: Verificando em que linha o código está
//         for (int j = 0; j <= i; j++) {
//             if (fscanf(file, "%d", &adj[i][j]) != 1) {
//                 printf("Erro ao ler os dados da matriz na posição (%d, %d).\n", i, j); // Erro de leitura específico
//                 fclose(file);
//                 return 1;
//             }
//         }
//     }

//     fclose(file); // Fechando o arquivo após a leitura

//     // Completar a matriz e exibir a matriz completa
//     completarMatriz(n, adj);

//     return 0;
// }
