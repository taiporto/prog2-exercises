#include <stdio.h>

/* Implementar a função INVERTE que recebe um número unsigned int como parâmetro
e retorna este número escrito ao contrário. Ex: 431 <-> 134. */

unsigned int INVERTE(unsigned int num);

int main() {

}

unsigned int INVERTE(unsigned int num){
  while(num > 0){
    unsigned int algarismo = num % 10;
  }
}

/** ChatGPT's solution */

/* #include <stdio.h>

int main() {
    unsigned int num, inverted_num = 0;

    printf("Enter an unsigned integer: ");
    scanf("%u", &num);

    while (num > 0) {
        unsigned int digit = num % 10;
        inverted_num = (inverted_num * 10) + digit;
        num /= 10;
    }

    printf("Inverted number: %u", inverted_num);

    return 0;
} */