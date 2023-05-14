#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char *compactar(char *s);
void *trata_erro_memoria();

int main() {
  char cadeia[MAX_SIZE], *cadeiaCompactada;

  printf("Insira uma cadeia de caracteres: ");
  fgets(cadeia, MAX_SIZE, stdin);

  cadeiaCompactada = compactar(cadeia);

  printf("%s\n", cadeiaCompactada);
}

char *compactar(char *s) {
  if (strlen(s) == 0 || s == NULL) {
    printf("string esta vazia");
    return NULL;
  }

  int tamString = strlen(s);
  int inicio = 0, fim = tamString - 1;

  while (s[inicio] == ' ')
    inicio++;

  while (s[fim] == ' ')
    fim--;

  tamString = fim - inicio + 1;

  char *stringCompactada = (char *)malloc((tamString + 1) * sizeof(char));

  if (stringCompactada == NULL) {
    return trata_erro_memoria();
  }

  for (int i = 0; i < tamString; i++) {
    stringCompactada[i] = s[inicio + i];
  }

  stringCompactada[tamString] = '\0';

  return stringCompactada;
}

void *trata_erro_memoria() {
  printf("Memoria insuficiente\n");
  return NULL;
}