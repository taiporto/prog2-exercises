#include <stdio.h>

/* Fazer um programa que recebe um símbolo de operação do usuário (+, -, / ou *) e dois
números reais. O programa deve retornar o resultado da operação recebida sobre estes
dois números. */

float soma(float a, float b) {
  return a + b;
}

float subtracao(float a, float b) {
  return a - b;
}

float multiplicacao(float a, float b) {
  return a * b;
}

float divisao(float a, float b) {
  return a / b;
}

int main() {

  float a, b, resultado;
  char operation;

  printf("Insira um número: ");
  scanf("%f", &a);

  printf("Insira outro número: ");
  scanf("%f", &b);

  printf("Insira a operação desejada entre eles (+;-;*;/): ");
  scanf(" %c", &operation);

  switch (operation)
  {
  case '+':
    resultado = soma(a, b);
    break;

  case '-':
    resultado = subtracao(a, b);
    break;

  case '*':
    resultado = multiplicacao(a, b);
    break;

  case '/':
    resultado = divisao(a, b);
    break;
  
  default:
    break;
  }

  printf("Resultado: %.2f\n", resultado);
}
