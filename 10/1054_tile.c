#include <stdio.h>

static inline int isOverlap(int x, int y, int r) {
  return r*r > x*x + y*y;
}

int main() {
  int N;
  scanf("%d\n", &N);
  int X[N], Y[N], R[N];
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d\n", &X[i], &Y[i], &R[i]);
  }
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (isOverlap(X[j] - X[i], Y[j] - Y[i], R[i] + R[j])) {
        ++cnt;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
