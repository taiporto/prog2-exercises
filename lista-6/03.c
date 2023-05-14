#include <stdio.h>
#include <stdlib.h>

#define MEDIA 5.0

int *aprovados(int n, int *mat, float *notas, int *tam);
void trata_erro_memoria();

int main() {

  int qtdAlunos;
  int *tam, *matriculas, *alunosAprovados;
  float *notas;

  tam = (int *)malloc(sizeof(int));

  if (tam == NULL) {
    trata_erro_memoria();
  }

  printf("Insira a quantidade de alunos na turma: ");
  scanf("%d", &qtdAlunos);

  matriculas = (int *)malloc(qtdAlunos * sizeof(int));
  notas = (float *)malloc(qtdAlunos * sizeof(float));

  if (matriculas == NULL || notas == NULL) {
    trata_erro_memoria();
  }

  for (int i = 0; i < qtdAlunos; i++) {
    printf("Insira o número de matricula do aluno %d: ", i + 1);
    scanf("%d", &matriculas[i]);

    printf("Insira a nota do participante %d: ", i + 1);
    scanf("%f", &notas[i]);
  }

  alunosAprovados = aprovados(qtdAlunos, matriculas, notas, tam);

  free(matriculas);
  free(notas);

  if (*tam > 1) {
    printf("Aprovados:\n");

    for (int i = 0; i < *tam; i++) {
      printf("Aluno %d\n", alunosAprovados[i]);
    }
  } else {
    printf("Aprovado: %d\n", alunosAprovados[0]);
  }

  free(tam);
  free(alunosAprovados);
}

int *aprovados(int n, int *mat, float *notas, int *tam) {

  int qtdAprovados = 0, *aprovados, *status;

  status = (int *)malloc(n * sizeof(int));

  if (status == NULL) {
    trata_erro_memoria();
  }

  for (int i = 0; i < n; i++) {
    if (notas[i] >= MEDIA) {
      status[i] = 1;
      qtdAprovados++;
    } else {
      status[i] = 0;
    }
  }

  aprovados = (int *)malloc(qtdAprovados * sizeof(int));

  if (aprovados == NULL) {
    trata_erro_memoria();
  }

  for (int i = 0, index_aprovados = 0; i < n; i++) {
    if (status[i] == 1) {
      aprovados[index_aprovados] = mat[i];
      index_aprovados++;
    }
  }

  *tam = qtdAprovados;

  return aprovados;
}

void trata_erro_memoria() {
  printf("Memoria insuficiente\n");
  exit(1);
}