// Vamos supor que várias pedras do jogo de xadrez estão no tabuleiro. Para
// facilitar a indicação das peças, vamos convencionar: 1 – peões 3 – torres 5 –
// reis 0 – ausência de peças 2 – cavalos 4 – bispos 6 – rainhas O tabuleiro é o
// seguinte: 1 3 0 5 4 0 2 1 1 0 1 0 0 1 0 0 0 0 0 0 1 0 6 0 1 0 0 1 1 0 0 1 0 1
// 0 4 0 0 1 0 0 0 3 1 0 0 1 1 1 0 6 6 0 0 1 0 1 0 5 0 1 1 0 6 a) Construa um
// programa que determine a soma total de peões e bispos e a quantidade de
// posições com ausência de peças; b) Escreva outro programa que determine qual
// a quantidade de cada tipo de peça no tabuleiro.

#define TAM_TABULEIRO 8
#define PEAO 1
#define CAVALO 2
#define TORRE 3
#define BISPO 4
#define REI 5
#define RAINHA 6

int main() {
  int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {
      {1, 3, 0, 5, 4, 0, 2, 1}, {1, 0, 1, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 1, 0, 6, 0}, {1, 0, 0, 1, 1, 0, 0, 1},
      {0, 1, 0, 4, 0, 0, 1, 0}, {0, 0, 3, 1, 0, 0, 1, 1},
      {1, 0, 6, 6, 0, 0, 1, 0}, {1, 0, 5, 0, 1, 1, 0, 6}};
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