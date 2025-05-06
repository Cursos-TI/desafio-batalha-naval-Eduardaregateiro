#include <stdio.h>

// Desafio Batalha Naval - MateCheck

#define TAMANHO 10 // Definição do tamanho do tabuleiro

void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO], int cone[TAMANHO][TAMANHO], int cruz[TAMANHO][TAMANHO], int octaedro[TAMANHO][TAMANHO], int areaAfetada[TAMANHO][TAMANHO])
{
    printf("\n  * Tabuleiro Batalha Naval * \n\n");
    printf("    "); // Espaços iniciais para alinhar colunas

    char linha[TAMANHO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    for (int y = 0; y < TAMANHO; y++)
    {
        printf(" %c ", linha[y]); // Imprime cabeçalho das colunas
    }
    printf("\n");

    for (int x = 0; x < TAMANHO; x++)
    {
        printf(" %2d ", x + 1); // Numeração das linhas
        for (int y = 0; y < TAMANHO; y++)
        {
            int valor = tabuleiro[x][y] + cone[x][y] + cruz[x][y] + octaedro[x][y] + areaAfetada[x][y]; // Combina efeitos no tabuleiro
            printf(" %d ", valor);
        }
        printf("\n");
    }
}
// Exibir o cone representado pelo número 3
void preencherCone(int matriz[TAMANHO][TAMANHO], int linha, int coluna)
{
    matriz[linha][coluna] = 3; // Define o valor da posição central do cone
    if (linha + 1 < TAMANHO)   // Preenche a segunda linha do cone, garantindo que esteja dentro dos limites da matriz

    {
        matriz[linha + 1][coluna - 1] = matriz[linha + 1][coluna] = matriz[linha + 1][coluna + 1] = 3; //ponto esquerda, central e direita 
    }
    if (linha + 2 < TAMANHO)     // Preenche a terceira linha do cone, ampliando a base, com verificação dos limites da matriz
    {
        for (int i = coluna - 2; i <= coluna + 2; i++)
        {
            if (i >= 0 && i < TAMANHO) // Garante que a coluna está dentro dos limites
                matriz[linha + 2][i] = 3; // Marca a terceira linha do cone

        }
    }
}
// Exibir a cruz representado pelo número 3
void preencherCruz(int matriz[TAMANHO][TAMANHO], int linha, int coluna)
{
    for (int i = -2; i <= 2; i++)// Percorre um intervalo de -2 a 2 para marcar a cruz

    {
        if (linha + i >= 0 && linha + i < TAMANHO) // Verifica se a posição vertical está dentro dos limites antes de preencher
            matriz[linha + i][coluna] = 3;
        if (coluna + i >= 0 && coluna + i < TAMANHO) // Verifica se a posição horizontal está dentro dos limites antes de preencher
            matriz[linha][coluna + i] = 3;
    }
}
// Exibir o octaedro representado pelo número 3
void preencherOctaedro(int matriz[TAMANHO][TAMANHO], int linha, int coluna)
{
    matriz[linha][coluna] = 3; // Define o valor da posição central
    if (linha - 1 >= 0)        // Validação de segurança para não sair do tabuleiro na parte de cima
        matriz[linha - 1][coluna] = 3;
    if (linha + 1 < TAMANHO)  // Validação para evitar ultrapassar limites na parte de baixo
        matriz[linha + 1][coluna] = 3;
    if (coluna - 1 >= 0)      // Validação para evitar ultrapassar limites à esquerda
        matriz[linha][coluna - 1] = 3;
    if (coluna + 1 < TAMANHO) // Validação para evitar ultrapassar limites à direita
        matriz[linha][coluna + 1] = 3;
        
}
// Exibir a área impactada representada pelo número 5
void marcarAreaAfetada(int (matriz)[TAMANHO][TAMANHO], int linha, int coluna)
{
    matriz [linha][coluna] = 5; //insere no tabuleiro a area afetada
}

int main()
{
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa o tabuleiro com zeros
    int cone[TAMANHO][TAMANHO] = {0}, cruz[TAMANHO][TAMANHO] = {0}, octaedro[TAMANHO][TAMANHO] = {0}, areaAfetada[TAMANHO][TAMANHO] = {0}; // acrescentando cone, cruz e octaedro

    // Aplicando habilidades separadas nas matrizes correspondentes
    preencherCone(cone, 5, 2); // cone: linha 6 coluna C
    preencherCruz(cruz, 2, 3); // cruz: linha 3 coluna D
    preencherOctaedro(octaedro, 3, 7); // octaedro: linha 4 coluna H
    marcarAreaAfetada(areaAfetada, 9, 9); // Area afetada: linha 10 coluna J
    marcarAreaAfetada(areaAfetada, 8, 8); // Area afetada: linha 9 coluna I
    marcarAreaAfetada(areaAfetada, 7, 9); // Area afetada: linha 8 coluna J
    marcarAreaAfetada(areaAfetada, 9, 6); // Area afetada: linha 10 coluna G

    // Exibindo o tabuleiro com todas as habilidades aplicadas
    imprimirTabuleiro(tabuleiro, cone, cruz, octaedro, areaAfetada);

    return 0;
}