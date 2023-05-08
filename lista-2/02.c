#include <stdio.h>

/* Faça um programa que calcule e imprima a soma dos n primeiros números naturais
ímpares. O usuário do programa deve fornecer quantos números devem ser somados. */

int soma_n_impares(int n);

int main() {
  int n, soma;

  printf("Insira o número de ímpares a serem somados: ");
  scanf("%d", &n);

  soma = soma_n_impares(n);

  printf("Soma: %d\n", soma);
}

int soma_n_impares(int n){
  int soma = 0, contador = 0, impar = 1;

  while(contador < n){
    soma+=impar;

    impar+=2;
    contador++;
  }

  return soma;
}
