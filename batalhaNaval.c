#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para imprimir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se um navio pode ser posicionado
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    if (direcao == 'H') {
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != AGUA) return 0;
        }
    } else if (direcao == 'V') {
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != AGUA) return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    if (direcao == 'H') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (direcao == 'V') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas dos navios (fixas no código)
    int linhaH = 2, colunaH = 3; // navio horizontal
    int linhaV = 5, colunaV = 6; // navio vertical

    // Valida e posiciona os navios
    if (podePosicionar(tabuleiro, linhaH, colunaH, 'H')) {
        posicionarNavio(tabuleiro, linhaH, colunaH, 'H');
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
    }

    if (podePosicionar(tabuleiro, linhaV, colunaV, 'V')) {
        posicionarNavio(tabuleiro, linhaV, colunaV, 'V');
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro com os navios
    exibirTabuleiro(tabuleiro);

    return 0;
}