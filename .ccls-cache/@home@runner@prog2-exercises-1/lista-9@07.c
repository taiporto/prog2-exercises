// 7. Considere o tipo Aluno, que representa um aluno da disciplina, e o tipo Prova, que representa a
// prova de um aluno, ambos descritos a seguir:
// struct aluno {
// int mat; /* Matricula do aluno */
// char nome[81]; /* Nome do aluno */
// };
// typedef struct aluno Aluno;
// struct prova {
// Aluno a; /* Aluno que fez a prova */
// float q1, q2, q3, q4; /* Nota em cada questao */
// };
// typedef struct prova Prova;
// O seguinte algoritmo de ordenação bolha foi implementado, utilizando as funções auxiliares
// compara e troca, para ordenar um vetor de ponteiros para o tipo Prova:
// void ordena(int n, Prova** v)
// {
// int fim,i;
// for(fim=n-1; fim>0; fim--)
// for(i=0; i<fim; i++)
// if(compara(v[i],v[i+1]))
// troca(&v[i],&v[i+1]);
// }
// Essa função ordena o vetor em ordem decrescente de nota da prova --- que equivale à soma das
// notas das quatro questões ---, com desempate pela ordem alfabética do nome do aluno. Por
// exemplo, se Maria e Ana tiram 6.0 e Sandra tira 7.0, a ordem deve ser Sandra, Ana e Maria.
// Implemente as funções compara e troca de forma que o algoritmo descrito funcione corretamente.

typedef struct aluno {
  int mat; /* Matricula do aluno */
  char nome[81]; /* Nome do aluno */
} Aluno;

typedef struct prova {
  Aluno a; /* Aluno que fez a prova */
  float q1, q2, q3, q4; /* Nota em cada questao */
} Prova;

void ordena(int n, Prova** v)
{
  int fim,i;
  for(fim=n-1; fim>0; fim--)
    for(i=0; i<fim; i++)
      if(compara(v[i],v[i+1]))
        troca(&v[i],&v[i+1]);
}

int compara() {
  
}

int 

int main() {
  
}