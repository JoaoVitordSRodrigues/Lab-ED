// #include <stdio.h>
// #include <unistd.h> // Para usar getcwd

// void grafoCompleto(int n) {
//     // Exibe a matriz de adjacência para o grafo completo K_n
//     printf("Matriz de adjacência para K%d:\n", n);
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (i != j) {
//                 printf("1 ");  // Se não for o mesmo vértice, é uma aresta
//             } else {
//                 printf("0 ");  // Não há aresta para o próprio vértice
//             }
//         }
//         printf("\n");
//     }

//     // Exibe a lista de adjacência para o grafo completo K_n
//     printf("Lista de adjacência para K%d:\n", n);
//     for (int i = 0; i < n; i++) {
//         printf("%d: ", i);
//         for (int j = 0; j < n; j++) {
//             if (i != j) {
//                 printf("%d ", j);  // Lista todos os vizinhos, exceto o próprio vértice
//             }
//         }
//         printf("\n");
//     }
// }

// int main() {
//     int n;
//     char cwd[1024];

//     // Obter e imprimir o diretório atual
//     if (getcwd(cwd, sizeof(cwd)) != NULL) {
//         printf("Diretório atual: %s\n", cwd);
//     } else {
//         perror("Erro ao obter o diretório atual");
//         return 1;
//     }

//     // Abrir o arquivo de entrada
//     FILE *file = fopen("Ex2.txt", "r"); // Tenta abrir o arquivo

//     if (file == NULL) {
//         printf("Erro ao abrir o arquivo de entrada. Certifique-se de que 'Ex2.txt' está no diretório indicado.\n");
//         return 1;
//     }

//     // Ler o número de vértices do arquivo
//     if (fscanf(file, "%d", &n) != 1) {
//         printf("Erro ao ler o número de vértices do arquivo.\n");
//         fclose(file);
//         return 1;
//     }
//     fclose(file);  // Fechar o arquivo após a leitura

//     // Exibir o grafo completo com a matriz e lista de adjacência
//     grafoCompleto(n);

//     return 0;
// }
