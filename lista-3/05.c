#include <stdio.h>
#include <stdlib.h>

/* Implemente a função max_vet, que recebe como parâmetro um vetor de números de ponto
flutuante (vet) de tamanho n e retorna o maior número armazenado nesse vetor. Essa função deve obedecer o protótipo: float max_vet (int n, float * vet);
Faça também a função main. */

float max_vet (int n, float * vet);

int main() {
  int tam_vetor;
  float *vetor, maior_valor;

  printf("Insira o tamanho desejado para o vetor: ");
  scanf("%d", &tam_vetor);

  vetor = (float *) malloc(tam_vetor * sizeof(float));

  for(int i = 0; i < tam_vetor; i++){
    printf("Insira o valor do %dº item: ", i+1);
    scanf("%f", &vetor[i]);
  }

  maior_valor = max_vet(tam_vetor, vetor);

  printf("O maior valor é: %f\n", maior_valor);
}

float max_vet(int n, float *vet) {
  float maior_valor = 0;

  for(int i = 0; i < n; i++){
    if(vet[i] >= maior_valor){
      maior_valor = vet[i];
    }
  }

  return maior_valor;
}