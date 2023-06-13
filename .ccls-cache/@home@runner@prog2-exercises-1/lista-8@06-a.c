#include <stdio.h>

#define TAM_TABULEIRO 8
#define VAZIO 0
#define PEAO 1
#define CAVALO 2
#define TORRE 3
#define BISPO 4
#define REI 5
#define RAINHA 6

int contaPeca(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int peca);

int main() {
  int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {
      {1, 3, 0, 5, 4, 0, 2, 1}, {1, 0, 1, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 1, 0, 6, 0}, {1, 0, 0, 1, 1, 0, 0, 1},
      {0, 1, 0, 4, 0, 0, 1, 0}, {0, 0, 3, 1, 0, 0, 1, 1},
      {1, 0, 6, 6, 0, 0, 1, 0}, {1, 0, 5, 0, 1, 1, 0, 6}};

  int contador_peoes, contador_bispos, contador_vazios;

  contador_peoes = contaPeca(tabuleiro, PEAO);
  contador_bispos = contaPeca(tabuleiro, BISPO);
  contador_vazios = contaPeca(tabuleiro, VAZIO);

  printf("Quantidade de peoes e bispos somados: %d\n",
         contador_peoes + contador_bispos);
  printf("Quantidade de espaços vazios: %d\n", contador_vazios);
}

int contaPeca(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int peca) {
  int contador = 0;

  for (int i = 0; i < TAM_TABULEIRO; i++) {
    for (int j = 0; j < TAM_TABULEIRO; j++) {
      if (tabuleiro[i][j] == peca)
        contador++;
    }
  }

  return contador;
}