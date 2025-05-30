#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABULEIRO_TAM 8

// Converte letra para índice de coluna
int colunaLetraParaIndice(char letra) {
    return letra - 'A';
}

void imprimirTabuleiro(int startRow, int startCol, int endRow, int endCol) {
    printf("    ");
    for (int i = 0; i < TABULEIRO_TAM; i++)
        printf("   %c   ", 'A' + i);

    printf("\n   -------------------------------------------------------\n");
    for (int i = 0; i < TABULEIRO_TAM; i++) {
        printf(" %d |", 1 + i);
        for (int j = 0; j < TABULEIRO_TAM; j++) {
            if (i == startRow && j == startCol)
                printf("   o   ");
            else if (i == endRow && j == endCol)
                printf("   X   ");
            else
                printf("   .   ");
        }
        printf("\n\n");
    }

    printf("Posição inicial: %c%d\n", 'A' + startCol, 8 - startRow);
    printf("Posição final:   %c%d\n", 'A' + endCol, 8 - endRow);
}

void movimentos() {
    int continuar = 1;

    while (continuar) {
        int startRow = 4, startCol = 4; // Centro do tabuleiro (E4)
        int endRow = -1, endCol = -1;
        int casas, peca, direcao;

        printf("\nEscolha uma peça para testar o movimento:\n");
        printf("1 - Bispo\n");
        printf("2 - Torre\n");
        printf("3 - Rainha\n");
        printf("4 - Cavalo\n");
        scanf("%d", &peca);

        switch (peca) {
        case 1: // Bispo
            printf("\nMovimentos válidos: diagonais\n");
            printf("1 - Cima Direita\n2 - Cima Esquerda\n3 - Baixo Direita\n4 - Baixo Esquerda\n");
            printf("Escolha a direção: ");
            scanf("%d", &direcao);
            break;

        case 2: // Torre
            printf("\nMovimentos válidos: verticais e horizontais\n");
            printf("1 - Cima\n2 - Baixo\n3 - Direita\n4 - Esquerda\n");
            printf("Escolha a direção: ");
            scanf("%d", &direcao);
            break;

        case 3: // Rainha
            printf("\nMovimentos válidos: diagonais, verticais e horizontais\n");
            printf("1 - Cima\n2 - Baixo\n3 - Direita\n4 - Esquerda\n");
            printf("5 - Cima Direita\n6 - Cima Esquerda\n7 - Baixo Direita\n8 - Baixo Esquerda\n");
            printf("Escolha a direção: ");
            scanf("%d", &direcao);
            break;

        case 4: // Cavalo
            printf("\nMovimentos válidos do cavalo:\n");
            printf("1 - 2 cima, 1 direita\n2 - 2 cima, 1 esquerda\n3 - 2 baixo, 1 direita\n4 - 2 baixo, 1 esquerda\n");
            printf("5 - 1 cima, 2 direita\n6 - 1 cima, 2 esquerda\n7 - 1 baixo, 2 direita\n8 - 1 baixo, 2 esquerda\n");
            printf("Escolha a direção: ");
            scanf("%d", &direcao);
            break;

        default:
            printf("Peça inválida.\n");
            continue;
        }

        if (peca != 4) {
            printf("Quantas casas deseja mover? ");
            scanf("%d", &casas);
        }

        // Cálculo de movimento
        switch (peca) {
        case 1: // Bispo
            switch (direcao) {
                case 1: endRow = startRow - casas; endCol = startCol + casas; break;
                case 2: endRow = startRow - casas; endCol = startCol - casas; break;
                case 3: endRow = startRow + casas; endCol = startCol + casas; break;
                case 4: endRow = startRow + casas; endCol = startCol - casas; break;
                default: printf("Direção inválida.\n"); continue;
            }
            break;

        case 2: // Torre
            switch (direcao) {
                case 1: endRow = startRow - casas; endCol = startCol; break;
                case 2: endRow = startRow + casas; endCol = startCol; break;
                case 3: endRow = startRow; endCol = startCol + casas; break;
                case 4: endRow = startRow; endCol = startCol - casas; break;
                default: printf("Direção inválida.\n"); continue;
            }
            break;

        case 3: // Rainha
            switch (direcao) {
                case 1: endRow = startRow - casas; endCol = startCol; break;
                case 2: endRow = startRow + casas; endCol = startCol; break;
                case 3: endRow = startRow; endCol = startCol + casas; break;
                case 4: endRow = startRow; endCol = startCol - casas; break;
                case 5: endRow = startRow - casas; endCol = startCol + casas; break;
                case 6: endRow = startRow - casas; endCol = startCol - casas; break;
                case 7: endRow = startRow + casas; endCol = startCol + casas; break;
                case 8: endRow = startRow + casas; endCol = startCol - casas; break;
                default: printf("Direção inválida.\n"); continue;
            }
            break;

        case 4: // Cavalo
            switch (direcao) {
                case 1: endRow = startRow - 2; endCol = startCol + 1; break;
                case 2: endRow = startRow - 2; endCol = startCol - 1; break;
                case 3: endRow = startRow + 2; endCol = startCol + 1; break;
                case 4: endRow = startRow + 2; endCol = startCol - 1; break;
                case 5: endRow = startRow - 1; endCol = startCol + 2; break;
                case 6: endRow = startRow - 1; endCol = startCol - 2; break;
                case 7: endRow = startRow + 1; endCol = startCol + 2; break;
                case 8: endRow = startRow + 1; endCol = startCol - 2; break;
                default: printf("Direção inválida.\n"); continue;
            }
            break;
        }

        // Validação de tabuleiro
        if (endRow < 0 || endRow >= TABULEIRO_TAM || endCol < 0 || endCol >= TABULEIRO_TAM) {
            printf("Movimento inválido! A peça saiu do tabuleiro.\n");
        } else {
            imprimirTabuleiro(startRow, startCol, endRow, endCol);
        }

        printf("\nDeseja tentar novamente? (1 - Sim / 0 - Não): ");
        scanf("%d", &continuar);
    }
}

int main(void) {
    movimentos();
    return 0;
}
