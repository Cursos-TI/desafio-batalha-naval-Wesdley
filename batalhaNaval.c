#include <stdio.h>

// declarando o campo
#define linha 10
#define  hab 5

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
    int tabelaNumerica[size] = {0,1,2,3,4,5,6,7,8,9};
    char tabelaAlfabetica[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int campo[size][size]; // campo de batalha

    // inicia o campo vazio com apenas água
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)  {
            campo[i][j] = 0;
        }
    } // Loop para colocar o campo vazio

    int navio1[3] = {3,3,3}; // horizontal
    int navio2[3] = {3,3,3}; // vertical
    int navio3[3] = {3,3,3}; // diagonal
    int navio4[3] = {3,3,3}; // diagonal

    int linha1 = 2, coluna1 = 2;
    int linha2 = 1, coluna2 = 0;
    int linha3 = 7, coluna3 = 7;
    int linha4 = 3, coluna4 = 6; 

    // coloca navio1 horizontalmente
    for (int n1 = 0; n1 < 3; n1++) {
        campo[linha1][coluna1 + n1] = navio1[n1];
    }

    // coloca navio2 verticalmente 
    for (int n2 = 0; n2 < 3; n2++){
        campo[linha2 + n2][coluna2] = navio2[n2];
    }

    // coloca navio3 diagonal para cima
    for (int n3 = 0; n3 < 3; n3++){
        campo[linha3+n3][coluna3+n3] = navio3[n3];
    }

    // coloca navio4 diagonal para baixo
    for (int n4 = 0; n4 < 3; n4++){
        campo[linha4-n4][coluna4+n4] = navio4[n4];
    }

    // CRIA AS HABILIDADES
    int habilidadeCone[hab][hab];
    int habilidadeCruz[hab][hab];
    int habilidadeOctaedro[hab][hab];

    // Cria o CONE
    for (int i = 0; i < hab; i++) {
        for (int j = 0; j < hab; j++) {
            if (i < 3 && j >= (2 - i) && j <= (2 + i)) {
                habilidadeCone[i][j] = 1;
            } else {
                habilidadeCone[i][j] = 0;
            }
        }
    }

    // Cria a CRUZ
    for (int i = 0; i < hab; i++) {
        for (int j = 0; j < hab; j++) {
            if (i < 3 && (i == 1 || j == 2)) {
                habilidadeCruz[i][j] = 1;
            } else {
                habilidadeCruz[i][j] = 0;
            }
        }
    }

    // Cria o OCTAEDRO
    for (int i = 0; i < hab; i++) {
        for (int j = 0; j < hab; j++) {
            int centro_i = 1;
            int centro_j = 2;
        
            int dist_i, dist_j;

            if (i >= centro_i) {
                dist_i = i - centro_i;
            } else {
                dist_i = centro_i - i;
            }

            if (j >= centro_j) {
                dist_j = j - centro_j;
            } else {
                dist_j = centro_j - j;
            }

            int distancia = dist_i + dist_j;
        
            if (distancia <= 1) {
                habilidadeOctaedro[i][j] = 1;
            } else {
                habilidadeOctaedro[i][j] = 0;
            }
        }
    }

    // APLICA O CONE NO CAMPO (centrado em 5,5)
    int origem_cone_i = 5, origem_cone_j = 5;
    for (int i = 0; i < hab; i++) {
        for (int j = 0; j < hab; j++) {
            if (habilidadeCone[i][j] == 1) {
                int campo_i = origem_cone_i - 2 + i;
                int campo_j = origem_cone_j - 2 + j;
                
                // Verifica se está dentro dos limites
                if (campo_i >= 0 && campo_i < size && campo_j >= 0 && campo_j < size) {
                    // Só marca se não for navio
                    if (campo[campo_i][campo_j] != 3) {
                        campo[campo_i][campo_j] = 5;
                    }
                }
            }
        }
    }

    // APLICA A CRUZ NO CAMPO (centrada em 2,7)
    int origem_cruz_i = 2, origem_cruz_j = 7;
    for (int i = 0; i < hab; i++) {
        for (int j = 0; j < hab; j++) {
            if (habilidadeCruz[i][j] == 1) {
                int campo_i = origem_cruz_i - 1 + i;
                int campo_j = origem_cruz_j - 2 + j;
                
                if (campo_i >= 0 && campo_i < size && campo_j >= 0 && campo_j < size) {
                    if (campo[campo_i][campo_j] != 3) {
                        campo[campo_i][campo_j] = 5;
                    }
                }
            }
        }
    }

    // APLICA O OCTAEDRO NO CAMPO (centrado em 8,3)
    int origem_oct_i = 8, origem_oct_j = 3;
    for (int i = 0; i < hab; i++) {
        for (int j = 0; j < hab; j++) {
            if (habilidadeOctaedro[i][j] == 1) {
                int campo_i = origem_oct_i - 1 + i;
                int campo_j = origem_oct_j - 2 + j;
                
                if (campo_i >= 0 && campo_i < size && campo_j >= 0 && campo_j < size) {
                    if (campo[campo_i][campo_j] != 3) {
                        campo[campo_i][campo_j] = 5;
                    }
                }
            }
        }
    }

    // Cria o campo visualmente 
    printf("Campo de Batalha Naval com Habilidades\n");
    printf("Legenda: 0=Agua  3=Navio  5=Habilidade\n\n");

    // Imprime cabeçalho com letras
    printf("  ");
    for (int i = 0; i < size; i++){
        printf("%c ", tabelaAlfabetica[i]);
    }
    printf("\n");

    // Imprime o campo com números nas laterais
    for (int i = 0; i < size; i++) {
        printf("%d ", tabelaNumerica[i]);
        for (int j = 0; j < size; j++) {
            printf("%d ", campo[i][j]);
        }
        printf("\n");
    }

    return 0;
}
