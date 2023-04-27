#include <stdio.h>
#include <stdlib.h>

int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam);
void trata_erro_memoria();

int main() {

  int qtdParticipantes, peso1, peso2;
  int *participantes, *vencedores, *tam;
  float *notasPrimeiroTeste, *notasSegundoTeste;

  tam = malloc(sizeof(int));
  *tam = 0;

  printf("Insira o peso do primeiro teste: ");
  scanf("%d", &peso1);

  printf("Insira o peso do segundo teste: ");
  scanf("%d", &peso2);

  printf("Insira a quantidade de participantes: ");
  scanf("%d", &qtdParticipantes);

  participantes = (int *) malloc(qtdParticipantes * sizeof(int));
  notasPrimeiroTeste = (float *) malloc(qtdParticipantes * sizeof(float));
  notasSegundoTeste = (float *) malloc(qtdParticipantes * sizeof(float));

  if(participantes == NULL || notasPrimeiroTeste == NULL || notasSegundoTeste == NULL){
    trata_erro_memoria();
	  exit(1);
  }

  for(int i = 0; i < qtdParticipantes; i++) {
    printf("Insira o número de inscrição do participante %d: ", i+1);
    scanf("%d", &participantes[i]);

    printf("Insira a primeira nota do participante %d: ", i+1);
    scanf("%f", &notasPrimeiroTeste[i]);

    printf("Insira a segunda nota do participante %d: ", i+1);
    scanf("%f", &notasSegundoTeste[i]);
  }

  vencedores = premiados(qtdParticipantes, participantes, notasPrimeiroTeste, peso1, notasSegundoTeste, peso2, tam);

  free(participantes);
  free(notasPrimeiroTeste);
  free(notasSegundoTeste);

  if(*tam > 1){
    printf("Vencedores:\n");
  
    for(int i = 0; i < *tam; i++) {
      printf("Participante %d\n", vencedores[i]);
    }
  } else {
    printf("Vencedor: %d\n", vencedores[0]);
  }

  free(vencedores);
}

int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam) {

  int qtdMaioresMedias, *premiados;
  float maiorMedia = 0.0;
  float *maioresMedias, *medias;

  medias = (float *) malloc(n * sizeof(float));
  
  if(medias == NULL) {
    trata_erro_memoria();
    exit(1);
  }

  for(int i = 0; i < n; i++) {
    float media = ((t1[i]*p1) + (t2[i]*p2)) / (p1+p2);
    medias[i] = media;

    if(media > maiorMedia){
      maiorMedia = media;
    }
  }

  for(int i = 0; i < n; i++){
    if(medias[i] == maiorMedia){
      (*tam)++;
    }
  }

  premiados = (int *) malloc(*tam * sizeof(int));

  for(int i = 0; i < n; i++){
    if(medias[i] == maiorMedia){
      premiados[i] = inscr[i];
    }
  }

  free(medias);

  return premiados;
}

void trata_erro_memoria(){
  printf("Memoria insuficiente\n");
}