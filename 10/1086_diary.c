#include<stdio.h>
int main() {
  int N, K, A;
  scanf("%d %d %d", &N, &K, &A);
  int B = (100*N+A-1)/A, d = 0;
  int set[A][B];
  // Init
  for (int i = 0; i < A; i++)
    for (int j = 0; j < B; j++)
      set[i][j] = -100;
  // 1 when page increased
  for (int i = 0; i < N; i++) {
    int n, a = A;
    scanf("%d", &n);
    for (int k = 0; k < n; k++,d++) {
      if (a-- > 0) set[d%A][d/A] = 1;
      else set[d%A][d/A] = 0;
    }
  }
  B = (d+A-1)/A;
  int max = 0;
  for (int i = 0; i < A; i++) {
    int s = 1, a = 0, b = 0;
    while (b < K) {
      s += set[i][b];
      b++;
    }
    while (b <= B) {
      s -= set[i][a];
      if (s > max || (s == max && (a*A + i + 1) < d)) {
        max = s;
        d = a*A + i + 1;
      }
      s += set[i][b];
      a++;b++;
    }
  }
  printf("%d %d\n", d, max);
}
