#include <stdio.h>
char solve(char a, char b, char c) {
  if ((a <= b && b <= c) || (c <= b && b <= a)) return b;
  else if ((a <= c && c <= b) || (b <= c && c <= a)) return c;
  else return a;
}

int main() {
  int ln, kn;
  scanf("%d %d", &ln, &kn);
  char L1[ln+1];
  char L2[ln+1];
  char K[kn+1];
  scanf("%s", L1);
  scanf("%s", L2);
  scanf("%s", K);
  for (int i = 0; i < kn; i++) {
    for (int j = 0; j < ln; j++) {
      K[i] = solve(K[i], L1[j], L2[j]);
    }
  }
  printf("%s\n", K);
}
