#include<stdio.h>
int main(){
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  int n = 1+N-K, m = 1+M-K;
  int map0[N][M];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      scanf("%d", &map0[i][j]);
  int map1[N][m];
  for (int i = 0; i < N; i++) {
    int s = 0;
    for (int j = 0; j < M; j++) {
      s += map0[i][j];
      if (j >= K-1) {
        map1[i][1+j-K] = s;
        s -= map0[i][1+j-K];
      }
    }
  }
  int max = 0;
  for (int j = 0; j < m; j++) {
    int s = 0;
    for (int i = 0; i < N; i++) {
      s += map1[i][j];
      if (i >= K-1) {
        if (s > max) max = s;
        s -= map1[1+i-K][j];
      }
    }
  }
  printf("%d\n", max);
}
