// Fazer um programa para cadastro e diálogo de login. O programa deve:
// a. Cadastrar um nome de usuário via teclado. O nome de usuário tem, no
// máximo, 8 caracteres, sendo válidos somente os caracteres numéricos e as
// letras maiúsculas ou minúsculas. Somente os caracteres válidos devem ser
// exibidos no console durante a digitação do nome de usuário. b. Cadastrar uma
// senha do usuário via teclado. Esta segue as mesmas regras do nome de usuário,
// com a diferença de que são exibidos somente asteriscos no console à medida
// que a senha é digitada. c. Receber um novo nome de usuário e uma nova senha,
// utilizando os mesmos procedimentos descritos nos itens a e b. d. Comparar o
// nome de usuário cadastrado com o recebido posteriormente e a senha cadastrada
// com a senha recebida. Caso sejam idênticos, informar “OK”, do contrário,
// informar “Acesso negado”.

#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define MAX_CHARS 9

// Custom getchar() implementation to filter out invalid characters (From ChatGPT)
int getchar_filtered(const char* allowedChars) {
  int ch;
  struct termios oldTermios, newTermios;
  tcgetattr(STDIN_FILENO, &oldTermios);
  newTermios = oldTermios;
  newTermios.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldTermios);
  
  while (strchr(allowedChars, ch) == NULL) {
      ch = getchar();
  }
  return ch;
}

int main() {
  char usuario[MAX_CHARS], senha[MAX_CHARS], usuario_login[MAX_CHARS],
      senha_login[MAX_CHARS], ch;
  int i = 0;

  printf("Insira seu nome de usuário: ");

  // From ChatGPT
  while ((ch = getchar_filtered("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")) != '\n') {
    if (i < sizeof(usuario) - 1) {
      usuario[i++] = ch;
      putchar(ch); // Display the allowed character
    }
  }

  strcat(usuario, "\0");

  printf("Insira sua senha: ");

  // From ChatGPT
  while ((ch = getchar_filtered("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")) != '\n') {
    if (i < sizeof(senha) - 1) {
      senha[i++] = ch;
      putchar(ch); // Display the allowed character
    }
  }

  strcat(senha, "\0");

  printf("Usuário registrado!\n");

  printf("Login\n\n");

  printf("Usuario: ");
  
  // From ChatGPT
  while ((ch = getchar_filtered("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")) != '\n') {
    if (i < sizeof(usuario_login) - 1) {
      usuario_login[i++] = ch;
      putchar(ch); // Display the allowed character
    }
  }

  strcat(usuario_login, "\0");

  printf("Senha: ");

  // From ChatGPT
  while ((ch = getchar_filtered("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")) != '\n') {
    if (i < sizeof(senha_login) - 1) {
      senha_login[i++] = ch;
      putchar(ch); // Display the allowed character
    }
  }
  strcat(senha_login, "\0");

  if (strcmp(usuario, usuario_login) != 0 || strcmp(senha, senha_login) != 0) {
    printf("Acesso negado\n");
    return 1;
  }

  printf("OK\n");
}