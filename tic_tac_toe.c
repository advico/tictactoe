#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

// Funções
void inicializarTabuleiro(char tabuleiro[SIZE][SIZE]);
void exibirTabuleiro(char tabuleiro[SIZE][SIZE]);
int verificarVitoria(char tabuleiro[SIZE][SIZE]);
int verificarEmpate(char tabuleiro[SIZE][SIZE]);
void realizarJogada(char tabuleiro[SIZE][SIZE], char jogador);

int main() {
    char tabuleiro[SIZE][SIZE];
    char jogadorAtual = 'X';
    int vitoria = 0;

    inicializarTabuleiro(tabuleiro);

    while (1) {
        system("clear || cls");
        exibirTabuleiro(tabuleiro);

        realizarJogada(tabuleiro, jogadorAtual);

        if (verificarVitoria(tabuleiro)) {
            system("clear || cls");
            exibirTabuleiro(tabuleiro);
            printf("\nParabéns! O jogador %c venceu!\n", jogadorAtual);
            break;
        }

        if (verificarEmpate(tabuleiro)) {
            system("clear || cls");
            exibirTabuleiro(tabuleiro);
            printf("\nEmpate! O tabuleiro está cheio.\n");
            break;
        }

        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    return 0;
}

void inicializarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibirTabuleiro(char tabuleiro[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

int verificarVitoria(char tabuleiro[SIZE][SIZE]) {
    // Verifica linhas
    for (int i = 0; i < SIZE; i++) {
        if (tabuleiro[i][0] != ' ' &&
            tabuleiro[i][0] == tabuleiro[i][1] &&
            tabuleiro[i][1] == tabuleiro[i][2]) {
            return 1;
        }
    }

    // Verifica colunas
    for (int i = 0; i < SIZE; i++) {
        if (tabuleiro[0][i] != ' ' &&
            tabuleiro[0][i] == tabuleiro[1][i] &&
            tabuleiro[1][i] == tabuleiro[2][i]) {
            return 1;
        }
    }

    // Verifica diagonais
    if (tabuleiro[0][0] != ' ' &&
        tabuleiro[0][0] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][2]) {
        return 1;
    }

    if (tabuleiro[0][2] != ' ' &&
        tabuleiro[0][2] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][0]) {
        return 1;
    }

    return 0;
}

int verificarEmpate(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void realizarJogada(char tabuleiro[SIZE][SIZE], char jogador) {
    int linha, coluna;

    while (1) {
        printf("Jogador %c, escolha sua jogada (linha e coluna): ", jogador);
        scanf("%d %d", &linha, &coluna);

        if (linha >= 1 && linha <= SIZE && coluna >= 1 && coluna <= SIZE && tabuleiro[linha - 1][coluna - 1] == ' ') {
            tabuleiro[linha - 1][coluna - 1] = jogador;
            break;
        } else {
            printf("Jogada inválida! Tente novamente.\n");
        }
    }
}
