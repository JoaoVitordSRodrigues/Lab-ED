public class FilaCircular {
    private Object[] fila;  // Vetor para armazenar os elementos da fila
    private int frente;      // Apontador para o "índice anterior ao primeiro"
    private int finalFila;   // Apontador para o "último elemento"
    private int tamanho;     // Contador para o número de elementos na fila
    private int capacidade;  // Capacidade máxima da fila

    // Construtor para criar a fila com uma capacidade inicial
    public FilaCircular(int capacidade) {
        this.capacidade = capacidade;
        fila = new Object[capacidade];
        frente = 0;
        finalFila = 0;
        tamanho = 0;
    }

    // Método para verificar se a fila está vazia
    public boolean vazia() {
        return tamanho == 0;
    }

    // Método para verificar se a fila está cheia
    public boolean cheia() {
        return tamanho == capacidade;
    }

    // Método para enfileirar um elemento
    public void enfileira(Object obj) {
        if (cheia()) {
            System.out.println("Fila cheia, não é possível enfileirar.");
            return;
        }
        fila[finalFila] = obj;
        finalFila = (finalFila + 1) % capacidade;  // Atualiza o final, fazendo a rotação
        tamanho++;
    }

    // Método para desenfileirar um elemento
    public Object desenfileira() {
        if (vazia()) {
            System.out.println("Fila vazia, não é possível desenfileirar.");
            return null;
        }
        frente = (frente + 1) % capacidade;  // Avança para a próxima posição
        Object obj = fila[frente];
        tamanho--;
        return obj;
    }

    // Método para retornar o primeiro elemento da fila sem removê-lo
    public Object cabeca() {
        if (vazia()) {
            System.out.println("Fila vazia.");
            return null;
        }
        return fila[(frente + 1) % capacidade];
    }

    // Método para retornar o último elemento da fila sem removê-lo
    public Object cauda() {
        if (vazia()) {
            System.out.println("Fila vazia.");
            return null;
        }
        return fila[(finalFila - 1 + capacidade) % capacidade];
    }

    // Método para mostrar todos os elementos da fila
    public void mostrarFila() {
        if (vazia()) {
            System.out.println("Fila vazia.");
            return;
        }
        int i = (frente + 1) % capacidade;
        for (int count = 0; count < tamanho; count++) {
            System.out.print(fila[i] + " ");
            i = (i + 1) % capacidade;
        }
        System.out.println();
    }

    // Método para pesquisar um elemento na fila
    public boolean pesquisa(Object obj) {
        if (vazia()) {
            return false;
        }
        int i = (frente + 1) % capacidade;
        for (int count = 0; count < tamanho; count++) {
            if (fila[i].equals(obj)) {
                return true;
            }
            i = (i + 1) % capacidade;
        }
        return false;
    }

    // Método para retornar o tamanho da fila
    public int tamanho() {
        return tamanho;
    }
}
