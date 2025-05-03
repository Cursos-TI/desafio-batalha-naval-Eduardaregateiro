#include <stdio.h>

// Desafio Batalha Naval - MateCheck

#define TAMANHO 10 // Definição do tamanho do tabuleiro

void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n  * Tabuleiro Batalha Naval * \n\n");
    printf("    "); // Espaços iniciais para alinhar colunas

    char linha[TAMANHO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    for (int y = 0; y < TAMANHO; y++) {
        printf(" %c ", linha[y]); // Imprime cabeçalho das colunas
    }
    printf("\n");

    for (int x = 0; x < TAMANHO; x++) {
        printf(" %2d ", x + 1); // Numeração das linhas
        for (int y = 0; y < TAMANHO; y++) {
            printf(" %d ", tabuleiro[x][y]); // Exibe o tabuleiro
        }
        printf("\n");
    }
}

void posicionarNavioDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, int direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 0 && linha - i >= 0 && coluna + i < TAMANHO) { // Diagonal superior direita ↗
            tabuleiro[linha - i][coluna + i] = 3;
        } else if (direcao == 1 && linha + i < TAMANHO && coluna - i >= 0) { // Diagonal inferior esquerda ↙
            tabuleiro[linha + i][coluna - i] = 3;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa o tabuleiro com zeros

    // Posiciona navios horizontais fixos
    tabuleiro[2][3] = tabuleiro[2][4] = tabuleiro[2][5] = 3; // Navio horizontal
    tabuleiro[4][7] = tabuleiro[5][7] = tabuleiro[6][7] = 3; // Navio vertical

    // Posiciona dois navios na diagonal
    posicionarNavioDiagonal(tabuleiro, 7, 2, 3, 0); // Navio na diagonal superior direita ↗
    posicionarNavioDiagonal(tabuleiro, 2, 8, 3, 1); // Navio na diagonal inferior esquerda ↙

    // Exibe o tabuleiro atualizado
    imprimirTabuleiro(tabuleiro);

    return 0;
}
