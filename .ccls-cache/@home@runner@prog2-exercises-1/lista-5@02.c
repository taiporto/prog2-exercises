// Mostre e explique (comentando as linhas de código) o que será impresso na
// tela:
#include <stdio.h>
#include <string.h>

int main(void) {
  char texto[] = "foi muito facil"; // cria uma string de tamanho determinado
                                    // dinamicamente pelo valor recebido
  int i;
  for (i = 0; texto[i] != '\0';
       i++) { // itera a string i a i até que o texto chegue ao final
    if (texto[i] == ' ') // se o caracter achado nessa iteração for um espaço,
                         // para o for e guarda o valor de i
      break;
  }
  i++; // Adiciona 1 ao valor anterior de i (indice do primeiro espaço)
  for (; texto[i] != '\0';
       i++) { // itera a string i a i até o final dela novamente, mas a partir
              // do primeiro  caracter depois do espaço (valor do índice
              // representado pelo valor de i)
    printf("%c",
           texto[i]); // imprime caracter por caracter, imprimindo "muito facil"
  }
}