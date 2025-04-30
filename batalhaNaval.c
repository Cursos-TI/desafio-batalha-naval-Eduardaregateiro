#include <stdio.h>

// Desafio Batalha Naval - MateCheck

int main() {
    // Nível Novato - Posicionamento dos Navios
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    // Criando o tabuleiro {Matriz 10x10}
    int tabuleiro[10][10] = {0}; // Inicializa a matriz com zeros

    // exibindo o tabuleiro
    printf("  * Tabuleiro Batalha Naval * \n\n");
    printf("    "); // Espaços iniciais para alinhar as colunas
    for (int y = 0; y < 10; y++)
    {
        printf(" %c ", linha[y]); // imprimir os numeros das colunas
    }

    printf("\n");

    for (int x = 0; x < 10; x++)
    {
        printf(" %2d ", x + 1); // Imprimir números ao invés de letras na lateral das linhas
        for (int y = 0; y < 10; y++)
        {
            if (x == 2 && (y == 3 || y == 4 || y == 5)) //Definir os números das colunas D, E e F para que exibam o número 3.
            
            {
                printf(" 3 ");
            }
            else if ((x == 4 || x == 5 || x == 6) && (y == 7)) //Definir os números da coluna H para que o número 3 apareça nas linhas 5, 6 e 7.
           
            {
                printf(" 3 ");
            }
            else
            {
                printf(" 0 "); // Exibir símbolo para representar células vazias
            }
        }

        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
