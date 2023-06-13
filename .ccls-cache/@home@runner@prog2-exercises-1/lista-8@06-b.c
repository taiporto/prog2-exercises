#include <stdio.h>

#define TAM_TABULEIRO 8
#define QTD_PECAS 6
#define VAZIO 0
#define PEAO 1
#define CAVALO 2
#define TORRE 3
#define BISPO 4
#define REI 5
#define RAINHA 6

typedef struct contador {
  int peao;
  int cavalo;
  int torre;
  int bispo;
  int rei;
  int rainha;
} Contador;

Contador contaPecas(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);

int main() {
  int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {
      {1, 3, 0, 5, 4, 0, 2, 1}, {1, 0, 1, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 1, 0, 6, 0}, {1, 0, 0, 1, 1, 0, 0, 1},
      {0, 1, 0, 4, 0, 0, 1, 0}, {0, 0, 3, 1, 0, 0, 1, 1},
      {1, 0, 6, 6, 0, 0, 1, 0}, {1, 0, 5, 0, 1, 1, 0, 6}};

  Contador contador;

  contador = contaPecas(tabuleiro);

  printf("Pecas:\n\nPeoes: %d\nCavalos: %d\nTorres: %d\nBispos: %d\nReis: "
         "%d\nRainhas: %d\n",
         contador.peao, contador.cavalo, contador.torre, contador.bispo,
         contador.rei, contador.rainha);
}

Contador contaPecas(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {

  Contador contador = {0, 0, 0, 0, 0, 0};

  for (int i = 0; i < TAM_TABULEIRO; i++) {
    for (int j = 0; j < TAM_TABULEIRO; j++) {
      switch (tabuleiro[i][j]) {
      case PEAO:
        contador.peao++;
        break;
      case CAVALO:
        contador.cavalo++;
        break;
      case TORRE:
        contador.torre++;
        break;
      case BISPO:
        contador.bispo++;
        break;
      case REI:
        contador.rei++;
        break;
      case RAINHA:
        contador.rainha++;
        break;
      }
    }
  }

  return contador;
}