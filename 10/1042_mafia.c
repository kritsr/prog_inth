#include <stdio.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  int X[N+1], Y[M+1];
  for (int i = 0; i <= N; i++) X[i] = 0;
  for (int i = 0; i <= M; i++) Y[i] = 0;
  int m = 0;
  for (int i = 0; i < K; i++){
    int x, y, r, e;
    scanf("%d %d %d", &x, &y, &r);
    e = MIN(N, x+r);
    for (int i = MAX(0, x-r); i <= e; i++){
      X[i]++;
      if (X[i] > m) m = X[i];
    }
    e = MIN(M, y+r);
    for (int i = MAX(0, y-r); i <= e; i++){
      Y[i]++;
      if (Y[i] > m) m = Y[i];
    }
  }
  printf("%d\n", m);
  return 0;
}