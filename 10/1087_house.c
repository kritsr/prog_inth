#include<stdio.h>
int main() {
  int R, C, K;
  scanf("%d %d %d", &R, &C, &K);
  int h[R][C];
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      scanf("%d", &h[i][j]);
      if ((i+j)&1) h[i][j] = -h[i][j];
    }
  }
  int max = -1e9;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      int t = 0;
      for (int k = -K; k <= K; k++) {
        if (i+k >= 0 && i+k < R) {
          t += h[i+k][j];
        }
        if (j+k >= 0 && j+k < C) {
          t += h[i][j+k];
        }
      }
      t -= h[i][j];
      if ((i+j)&1) t = -t;
      if (t > max) max = t;
    }
  }
  printf("%d\n", max);
}
