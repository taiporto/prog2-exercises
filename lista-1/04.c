#include <stdio.h>

/* Validar as notas de 3 provas fornecidas por um
professor e indicar: a média, se está aprovado/reprovado e se tem direito de realizar a VS.
Inicialmente, faça um programa que recebe como entrada as 3 notas e mostre os
resultados solicitados. Posteriormente, coloque o código de cálculo da média em uma
função. Em um passo seguinte, realize os controles necessários para não receber notas
inválidas. */

float calcula_media(float n1, float n2, float n3);

void define_nota(int ordem, float *nota) {
  int validacao = 0;
  
  do {
    printf("Insira a %dª nota: ", ordem);
    validacao = scanf("%f", *nota);

    while( (ch=getchar())!='\n' && ch!=EOF );

    if(validacao != 1) { printf("Nota invalida\n"); }
  } while(validacao != 1);
}

int main() {

  char ch;
  float *n1, *n2, *n3, media;

  n1 = (int *) malloc(sizeof(int));
  n2 = (int *) malloc(sizeof(int));
  n3 = (int *) malloc(sizeof(int));

  define_nota(1, n1);
  define_nota(2, n2);
  define_nota(3, n3);

  // do{
  //   printf("Insira a primeira nota: ");
  //   validacao = scanf("%f", &n1);

  //   while( (ch=getchar())!='\n' && ch!=EOF );

  //   if(validacao != 1) { printf("Nota invalida\n"); }
  // } while(validacao != 1);

  // validacao = 0;

  // do{
  //   printf("Insira a segunda nota: ");
  //   validacao = scanf("%f", &n2);

  //   while( (ch=getchar())!='\n' && ch!=EOF );

  //   if(validacao != 1) { printf("Nota invalida\n"); }
  // } while(validacao != 1);

  // validacao = 0;

  // do{
  //   printf("Insira a terceira nota: ");
  //   validacao = scanf("%f", &n3);

  //   while( (ch=getchar())!='\n' && ch!=EOF );

  //   if(validacao != 1) { printf("Nota invalida\n"); }
  // } while(validacao != 1);

  media = calcula_media(n1, n2, n3);

  if(media < 4) {
    printf("Aluno reprovado")
  }

  if(media >= 4 && media < 6) {
    printf("Aluno em VS");
  }

  if(media >= 6) {
    printf("Aluno aprovado");
  }
}

float calcula_media(float n1, float n2, float n3) {
  return (n1+n2+n3) / 3;
}