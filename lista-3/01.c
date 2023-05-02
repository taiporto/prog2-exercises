#include <stdio.h>

/*  Implemente a função calcula_circulo, que calcula a área e a circunferência de um círculo de raio
r. Essa função deve obedecer o protótipo:
void calc_circulo(float r, float * circunferencia, float * area);
Fórmulas:
A = π r2 ; c = 2 π r ; π = 3.14159265
Note que essa passagem dos 2 últimos parâmetros é uma passagem por referência. */

#define PI 3.14159265

void calc_circulo(float r, float * circunferencia, float * area);

int main(){
  float raio, circunferencia, area;

  printf("Insira o raio do círculo: ");
  scanf("%f", &raio);

  calc_circulo(raio, &circunferencia, &area);

  printf("A circunferência do círculo é %.2f\n", circunferencia);
  printf("A área do círculo é %.2f\n", area);
}

void calc_circulo(float r, float *circunferencia, float *area) {
  *circunferencia = (PI * 2 * r);
  *area = PI * (r*r);
}