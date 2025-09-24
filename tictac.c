#include <stdio.h>
#include <stdlib.h>

#define X 1
#define O 0
#define EMPTY -1

int checkwin(int tabuleiro[3][3]);
void printabuleiro(int t[3][3]);

int main() {
    int vencedor = -1; // -1 significa que ninguem venceu
    int i,j;
    int jogador = X;
    int tabuleiro[3][3];
    int rodadas = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = EMPTY;
        }
    }

    while(vencedor == -1 && rodadas <= 9){
        printabuleiro(tabuleiro);
        printf("Selecione a posicao (linha-coluna) que deseja jogar, jogador %c \n", (jogador == X) ? 'X' : 'O');
        scanf("%d %d", &i, &j);

        if(i > 2 || i < 0 || j > 2 || j < 0){
            printf("Posicao invalida \n");
            continue;
        }
        if (tabuleiro[i][j] != EMPTY){
            printf("Posicao ja ocupada \n");
            continue;
        }

        tabuleiro[i][j] = jogador;
        vencedor = checkwin(tabuleiro);
        
        rodadas++;
        if(rodadas % 2 == 0)    {
            jogador = O;
        } else {
            jogador = X;
        }


        

    }
    if(vencedor != -1){
        printf("O jogador %c venceu!\n", (vencedor == X) ? 'X' : 'O');
    } else {
        printf("Deu velha\n");
    }
    return 0;
}


int checkwin(int t[3][3]) {
    for(int i = 0; i < 3; i++){
        if(t[i][0] == t[i][1] && t[i][1] == t[i][2] && t[i][0] != EMPTY) return t[i][0];
        if(t[0][i] == t[1][i] && t[1][i] == t[2][i] && t[0][i] != EMPTY) return t[0][i];
    }
    if(t[0][0] == t[1][1] && t[1][1] == t[2][2] && t[0][0] != EMPTY) return t[0][0];
    if(t[0][2] == t[1][1] && t[1][1] == t[2][0] && t[0][2] != EMPTY) return t[0][2];
    return -1;
}



void printabuleiro(int t[3][3]) {
    for (int i = 0; i < 3; i++){
        for ( int j = 0; j < 3; j++){
            if(t[i][j] == EMPTY) {
                printf("| |");
            } else {
                printf("|%c|", t[i][j] == X ? 'X' : 'O');
            }
        }
        printf("\n");
    }
}
