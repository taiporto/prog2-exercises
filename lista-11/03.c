// 3. Crie uma lista encadeada onde cada elemento contém informações de um
// aluno. Crie funções para o gerenciamento da lista: imprimir, excluir, incluir
// e alterar. Aplique essas funções a partir de uma lista carregado do arquivo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
  int matricula;
  char nome[81];
  struct aluno *prox;
} Aluno;

Aluno *cria_lista();
void imprime_lista(Aluno *lista);
Aluno *exclui_aluno(Aluno *lista, int num_matricula);
Aluno *inclui_aluno(Aluno *lista, int matricula_aluno, char nome_aluno[81]);
Aluno *altera_aluno(Aluno *lista, int matricula_aluno, char novo_nome[81]);

int main() {
  Aluno *lista;
  FILE *fp;
  int matricula;
  char aluno[81];

  lista = cria_lista();

  fp = fopen("alunos.txt", "r");

  if (fp == NULL) {
    printf("Arquivo nao pode ser aberto");
    exit(1);
  }

  while (fscanf(fp, "%d  %s", &matricula, aluno) == 2) {
    lista = inclui_aluno(lista, matricula, aluno);
  }

  imprime_lista(lista);

  lista = exclui_aluno(lista, 3);

  imprime_lista(lista);

  lista = altera_aluno(lista, 1, "Tai Porto");

  imprime_lista(lista);
}

Aluno *cria_lista() { return NULL; }

void imprime_lista(Aluno *lista) {
  Aluno *iterador = lista;

  while (iterador != NULL) {
    printf("Matricula: %d\nAluno: %s\n\n", iterador->matricula, iterador->nome);
    iterador = iterador->prox;
  }
  printf("\n\n");
}

Aluno *exclui_aluno(Aluno *lista, int num_matricula) {
  Aluno *iterador = lista, *anterior, *temp;

  while (iterador != NULL && iterador->matricula != num_matricula) {
    anterior = iterador;
    iterador = iterador->prox;
  }

  if (iterador->matricula != num_matricula)
    return lista;

  if (iterador == NULL) {
    lista = anterior;
    free(iterador);
    return lista;
  }

  anterior->prox = iterador->prox;
  free(iterador);
  return lista;
}

Aluno *inclui_aluno(Aluno *lista, int matricula_aluno, char *nome_aluno) {
  Aluno *nova_lista = (Aluno *)malloc(sizeof(Aluno));

  strcpy(nova_lista->nome, nome_aluno);
  nova_lista->matricula = matricula_aluno;

  nova_lista->prox = lista;

  return nova_lista;
}

Aluno *altera_aluno(Aluno *lista, int matricula_aluno, char *novo_nome) {
  Aluno *iterador = lista;

  while (iterador != NULL && iterador->matricula != matricula_aluno) {
    iterador = iterador->prox;
  }

  if (iterador->matricula != matricula_aluno) {
    printf("Aluno nao encontrado");
    return lista;
  }

  strcpy(iterador->nome, novo_nome);

  return lista;
}