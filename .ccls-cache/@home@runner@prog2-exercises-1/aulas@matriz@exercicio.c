#include <stdio.h>

#define n 3
#define RIO 0
#define MACAE 1
#define NITEROI 2

float calculaValorDaRota(int cidades[n], float valores[n][n]);

int main() {
  float precos[n][n] = {{3.4, 5.4, 2.0}, {4.5, 6.7, 9}, {3.4, 5.6, 7.3}};
  float valor_total;
  int cidades[n] = {NITEROI, MACAE, RIO};

  valor_total = calculaValorDaRota(cidades, precos);
  printf("Valor total: %.2f\n", valor_total);
}

float calculaValorDaRota(int cidades[n], float valores[n][n]) {
  float somatorio = 0;

  for (int i = 0; i < n; i++) {
    if (i == 2) {
      somatorio += valores[cidades[i]][cidades[0]];
      return somatorio;
    }
    somatorio += valores[cidades[i]][cidades[i + 1]];
    printf("%.2f\n", somatorio);
  }

  return somatorio;
}