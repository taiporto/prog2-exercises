#include <stdio.h>

/* Implementar a função INVERTE que recebe um número unsigned int como parâmetro
e retorna este número escrito ao contrário. Ex: 431 <-> 134. */

unsigned int INVERTE(unsigned int num);

int main() {
	unsigned int numero_original;

  printf("Insira um numero inteiro positivo:\n");
  
 	scanf("%u", &numero_original);

	printf("%u", INVERTE(numero_original));
}

unsigned int INVERTE(unsigned int num){
  unsigned int num_invertido = 0;
  
  while(num > 0){
    unsigned int algarismo = num % 10;
    num_invertido = (num_invertido * 10) + algarismo;
    num /= 10;
  }

  return num_invertido;
}