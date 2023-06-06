// Um cadastro de pessoas é representado por um vetor de ponteiros para o tipo
// Pessoa, conforme descrito a seguir: struct pessoa { int codigo; char
// nome[81];
// };
// typedef struct pessoa Pessoa;
// Considere que esse vetor está em ordem crescente de código, e, além disso, o
// código é a identificação única da pessoa. Aplicando a técnica de busca
// binária, implemente uma função que verifique se um código fornecido como
// parâmetro existe no vetor. A função retorna o ponteiro para esta pessoa
// (Pessoa *). Caso contrário, a função deve retornar NULL. A função recebe como
// parâmetros o ponteiro vet, para o primeiro elemento do vetor, o inteiro n,
// que representa o tamanho do vetor, e o código. Seu protótipo é:
// Pessoa* busca(int n, Pessoa** vet, int codigo);
// Faça também um programa para testar essa função.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 81

typedef struct pessoa {
  int codigo;
  char nome[TAM_NOME];
} Pessoa;

Pessoa *busca(int n, Pessoa **vet, int codigo);

int main() {
  Pessoa *pessoas, *pessoa_buscada;
  int numero_pessoas, codigo_para_buscar;

  printf("Insira o número desejado de pessoas: ");
  scanf("%d", &numero_pessoas);

  pessoas = (Pessoa *)malloc(numero_pessoas * sizeof(Pessoa));

  if (pessoas == NULL) {
    printf("Memoria insuficiente");
    exit(1);
  }

  for (int i = 0; i < numero_pessoas; i++) {
    printf("Insira o nome da pessoa %d: ", i + 1);
    scanf(" %80[^\n]", pessoas[i].nome);

    printf("Insira o código da pessoa %d: ", i + 1);
    scanf("%d", &pessoas[i].codigo);
  }

  for (int i = 0; i < numero_pessoas; i++) {
    printf("Pessoa: \n");
    printf("Nome: %s  Código: %d\n\n", pessoas[i].nome, pessoas[i].codigo);
  }

  printf("Insira um código de pessoa para buscar: ");
  scanf("%d", &codigo_para_buscar);

  pessoa_buscada = busca(numero_pessoas, &pessoas, codigo_para_buscar);

  if (pessoa_buscada == NULL) {
    printf("Pessoa não encontrada.");
  } else {
    printf("Pessoa: \n");
    printf("Nome: %s  Código: %d\n\n", pessoa_buscada->nome,
           pessoa_buscada->codigo);
  }
}

Pessoa *busca(int n, Pessoa **vet, int codigo) {
  int inicio = 0, fim = n - 1;

  while (inicio <= fim) {
    int metade = (inicio + fim) / 2;

    if (codigo < (*vet)[metade].codigo) {
      fim = metade - 1;
    } else if (codigo > (*vet)[metade].codigo) {
      inicio = metade + 1;
    } else {
      return &(*vet)[metade];
    }
  }

  return NULL;
}