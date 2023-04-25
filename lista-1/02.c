#include <stdio.h>

/** Fazer um programa que recebe 3 valores inteiros do usuário e mostra o maior deles, o
menor deles, os valores pares e a média. */

int retorna_maior(int val1, int val2, int val3) {

  if(val1 >= val2 && val1 >= val3) {
    return val1;
  }

  if(val2 >= val1 && val2 >= val3) {
    return val2;
  }

  return val3;
}

int retorna_menor(int val1, int val2, int val3) {
  if(val1 < val2 && val1 < val3) {
    return val1;
  }

  if(val2 < val1 && val2 < val3) {
    return val2;
  }

  return val3;
}

void imprime_pares(int val1, int val2, int val3){
  if(val1 % 2 == 0) {
    printf("%d é par\n", val1);
  }
  if(val2 % 2 == 0) {
    printf("%d é par\n", val2);
  }
  if(val3 % 2 == 0) {
    printf("%d é par\n", val3);
  }
}

int calcula_media(int val1, int val2, int val3) {
  float v1 = (float) val1;
  float v2 = (float) val2;
  float v3 = (float) val3;

  return (v1+v2+v3)/3.0;
}

int main() {

  int val1, val2, val3;

  printf("Insira o primeiro valor inteiro: ");
  scanf("%d", &val1);
  printf("Insira o segundo valor inteiro: ");
  scanf("%d", &val2);
  printf("Insira o terceiro valor inteiro: ");
  scanf("%d", &val3);

  printf("O maior valor é %d\n", retorna_maior(val1, val2, val3));
  printf("O menor valor é %d\n", retorna_menor(val1, val2, val3));

  imprime_pares(val1, val2, val3);

  printf("A média entre os três valores é %d\n", calcula_media(val1, val2, val3));
}


