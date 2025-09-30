#include <stdio.h>

// declarando o campo
#define linha 10
#define coluna 10

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

     // tabelas numéricas e alfabéticas para organizar o campo
    int tabelaNumerica[linha] = {0,1,2,3,4,5,6,7,8,9};
    char tabelaAlfabetica[10] = {'A','B','C','D','E','F','G','H','I','J'};

    int campo[linha][coluna]; // campo de batalha
    // inicia o campo vazio com apenas água
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++)  {
            campo[i][j] = 0;
        }
    } // Loop para colocar o campo vazio

    int navio1[3] = {3,3,3}, // horizontal
    navio2[3] = {3,3,3}, // vertical
    navio3[3] = {3,3,3}, // diagonal
    navio4[3] = {3,3,3}; // diagonal

    int linha1 = 2, coluna1 = 2,
    linha2 = 1, coluna2 = 0,
    linha3 = 7, coluna3 = 7,
    linah4 = 3, coluna4 = 6;


    // coloca navio1 horizontalmente
    for (int n1 = 0; n1 < 3; n1++) {
        campo[linha1][coluna1 + n1] = navio1[n1]; // colocamos o i para percorrer o array navio1 e coluna1 para colocar ele horizontalmente
    }

    // coloca navio2 verticalmente 
    for (int n2 = 0; n2 < 3; n2++){
        campo[linha2 + n2][coluna2] = navio2[n2]; // colocamos o i para percorrer o array navio2 e linha2 para colocar ele verticalmente
    }

    // coloca navio3 diagonal para cima
    for (int n3 = 0; n3 < 3; n3++){
        campo[linha3+n3][coluna3+n3] = navio3[n3];
    }

    // coloca navio4 diagonal para baixo
    for (int n4 = 0; n4 < 3; n4++){
        campo[linah4-n4][coluna4+n4] = navio4[n4];
    }


    // Cria o campo visualmente 

    printf("Campo de Batalha Naval\n");

    // loop para criar o mapa

    for (int i = 0; i < linha; i++){
        printf("%c ", tabelaAlfabetica[i]);
    }

    printf("\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", campo[i][j]);
        }
        printf("  %d", tabelaNumerica[i]);
        printf("\n");
    }

    return 0;
}
