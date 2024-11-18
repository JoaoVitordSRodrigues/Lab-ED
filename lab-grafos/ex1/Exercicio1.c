#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void arestas(int n, int adj[][MAX]) {
    printf("Arestas do grafo:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { // Inclui j >= i para grafos não-direcionados
            if (adj[i][j] == 1) {
                printf("(%d, %d)\n", i, j);
            }
        }
    }
}

bool ehDigrafo(int n, int adj[][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] != adj[j][i]) {
                return true; // Se adj[i][j] != adj[j][i], é um dígrafo
            }
        }
    }
    return false;
}

void grauVertices(int n, int adj[][MAX]) {
    printf("Grau dos vértices:\n");
    for (int i = 0; i < n; i++) {
        int grau = 0;
        for (int j = 0; j < n; j++) {
            grau += adj[i][j];
        }
        printf("Vértice %d: Grau %d\n", i, grau);
    }
}

void listaAdjacencia(int n, int adj[][MAX]) {
    printf("Lista de adjacências:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Função DFS para verificar se o grafo é conexo
void dfs(int v, bool adj[][MAX], bool visited[], int n) {
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, adj, visited, n);
        }
    }
}

// Função para verificar se o grafo é conexo
bool ehConexo(int n, int adj[][MAX]) {
    bool visited[MAX] = {false};
    dfs(0, adj, visited, n);  // Começa a DFS a partir do vértice 0

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;  // Se algum vértice não for visitado, o grafo é desconexo
        }
    }
    return true;
}

// Função auxiliar para detectar ciclos
bool dfsCiclo(int v, bool adj[][MAX], bool visited[], bool recStack[], int n) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1) {
            if (!visited[i] && dfsCiclo(i, adj, visited, recStack, n)) {
                return true;
            }
            if (recStack[i]) {
                return true;  // Encontrou um ciclo
            }
        }
    }
    recStack[v] = false;
    return false;
}

// Função para verificar se o grafo é cíclico
bool ehCiclico(int n, int adj[][MAX]) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};  // Para detectar ciclos

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfsCiclo(i, adj, visited, recStack, n)) {
            return true;  // Se encontrar um ciclo
        }
    }
    return false;
}

int main() {
    int n;
    int adj[MAX][MAX];

    FILE *file = fopen("Ex1.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê o número de vértices
    if (fscanf(file, "%d", &n) != 1) {
        printf("Erro ao ler o número de vértices.\n");
        fclose(file);
        return 1;
    }

    // Verifica se o número de vértices é válido
    if (n <= 0) {
        printf("Número de vértices inválido.\n");
        fclose(file);
        return 1;
    }

    // Lê a matriz de adjacência a partir do arquivo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fscanf(file, "%d", &adj[i][j]) != 1) {
                printf("Erro ao ler a matriz de adjacência.\n");
                fclose(file);
                return 1;
            }
        }
    }

    fclose(file);

    // Pergunta a)
    arestas(n, adj);

    // Pergunta b)
    printf("É um dígrafo? %s\n", ehDigrafo(n, adj) ? "Sim" : "Não");

    // Pergunta c)
    grauVertices(n, adj);

    // Pergunta d)
    printf("O grafo é %s\n", ehConexo(n, adj) ? "conexo" : "desconexo");

    // Pergunta e)
    printf("O grafo é %s\n", ehCiclico(n, adj) ? "cíclico" : "acíclico");

    // Pergunta f)
    listaAdjacencia(n, adj);

    return 0;
}
