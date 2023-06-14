// Faça um teste de mesa para testar 3 exemplos do programa de conversão binária.
// # include <stdio.h>
// int conversao_binaria(int n, int *vetor_binario, int tamanho, int tamanho_fixo) // o
// "tamanho_fixo" é usado somente na última chamada da função no vetor_binário
// {
// vetor_binario[tamanho] = (n % 2); // as últimas posições do vetor receberão o
// resto dessa divisão
// n /= 2; // o "n" precisa ser divido para continuar os próximos cálculos
// corretamente
// if(tamanho > 0) // esse "if" é usado em todas as funções recursivas exceto a última
// chamada quando o tamamho for igual a zero
// {
// tamanho--; // a função a ser chamada receberá um tamanho decrementado
// return conversao_binaria(n, vetor_binario, tamanho, tamanho_fixo); // chama
// a função recursivamente com tamanho decrementado
// }
// if(tamanho == 0) // apenas na última chamada será feito isso