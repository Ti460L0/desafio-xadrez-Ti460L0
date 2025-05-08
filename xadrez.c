#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.
void tabuleiro(int linha, int coluna)
{
    // Imprimir as colunas (A...H) acima do tabuleiro
    printf(" # | "); // Espaço para alinhar os números
    for (int i = 0; i < coluna; i++)
    {
        printf(" %c   ", 'A' + i); // Imprime as colunas (A, B, C, ...)
       
            printf("| ");
        
        
    }
    printf("\n");
    printf("_____________________________________________________________\n");
    // Imprimir as linhas do tabuleiro
    
    for (int j = 0; j < linha; j++)
    {
        // Imprimir o número da linha antes de cada linha do tabuleiro
        printf(" %d ", 8 - j); // As linhas são numeradas de 1 a 8, de baixo para cima
        printf("|");
        
        
        // Imprimir os espaços representando as casas do tabuleiro
        for (int i = 0; i < coluna; i++)
        {
            printf("  %c%d  |", 'A' + i, 8 - j); // Usando o ponto (.) como um marcador genérico para as casas
            
            
        }
        printf("\n");
    }
}


int main()
{
    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.
    const int bispo = 2;
    const int torre = 3;
    const int rainha = 8;
    const int linha = 8;
    const int coluna = 8;

    tabuleiro(linha, coluna);
    

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.
    

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.

    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    return 0;
}
