#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

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

    int campo[10][10]; // campo de batalha
    // inicia o campo vazio com apenas água
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)  {
            campo[i][j] = 0;
        }
    } // Loop para colocar o campo vazio

    int navio1[3] = {3,3,3}, // horizontal
    navio2[3] = {3,3,3}; // vertical

    int linha1 = 2, coluna1 = 2,
    linha2 = 5, coluna2 = 5;

    // coloca navio1 horizontalmente
    for (int i = 0; i < 3; i++) {
        campo[linha1][coluna1 + i] = navio1[i]; // colocamos o i para percorrer o array navio1 e coluna1 para colocar ele horizontalmente
    }

    // coloca navio2 verticalmente 
    for (int i = 0; i < 3; i++){
        campo[linha2 + i][coluna2] = navio2[i]; // colocamos o i para percorrer o array navio2 e linha2 para colocar ele verticalmente
    }

    // Cria o campo visualmente 

    printf("Campo de Batalha Naval\n");

    // loop para criar o mapa
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", campo[i][j]);
        }
        printf("\n");
    }

    return 0;
}
