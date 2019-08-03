/* Teste de um buffer circular
 *
 * Este programa serve para implementar e testar uma implementacao de buffer
 * circular
 */

#include <stdio.h>

char buffer[5];
int prox_livre=0;
int prox_leitura=0;
int N=0;

void adicionar_buffer(char c) {
  if (N < 5) {
    buffer[prox_livre]=c;
    prox_livre = (prox_livre+1) % 5;
    N = N + 1;
  }
}

void remover_buffer() {
  if (N > 0) {
    prox_leitura = (prox_leitura + 1) % 5;
    N = N - 1;
  }
}

void imprimir_buffer() {
  if (N == 0) printf("\n");
  else {
    for (int n = 0; n < N; n++) {
      printf("%c", buffer[((prox_leitura + n) % 5)]);
      if (n == (N-1))  printf("\n");
      else printf(" ");
    }
  }
}

int main() {


  char c;

  do {
    scanf("%c", &c);
    if (c == '\n') break;
    if (c>='0' && c<='9') {
      adicionar_buffer(c);
      imprimir_buffer();
    }
    if ((c>='a' && c<='z') || (c>='A' && c<='Z')) {
      remover_buffer();
      imprimir_buffer();
    }
  } while (1);

  return 0;
}
