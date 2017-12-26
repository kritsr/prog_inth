#include <stdio.h>

int main() {
  int N, n = -1;
  scanf("%d\n", &N);
  char stack[N];
  for (int i = 0; i < N; i++) {
    char c;
    scanf(" %c", &c);
    if (n >= 0 && stack[n] == c) {
      --n;
    } else {
      stack[++n] = c;
    }
  }
  printf("%d\n", n + 1);
  if (n < 0) printf("empty");
  for (int i = n; i >= 0; --i) {
    printf("%c", stack[i]);
  }
  printf("\n");
}
