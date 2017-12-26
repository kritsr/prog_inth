#include <stdio.h>
int findI(int *g, int i) {
  while (g[i] < 0) {
    i = -g[i];
  }
  return i;
}
int main(){
  int N, M;
  scanf("%d %d", &N, &M);
  int g[N+1];
  for (int i = 1; i <= N; i++) {
    scanf("%d", g+i);
  }
  for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a = findI(g,a);
    b = findI(g,b);
    if (a == b) {
      printf("-1\n");
    } else if (g[a] > g[b] || (g[a] == g[b] && a < b)) {
      g[a] += g[b]/2;
      g[b] = -a;
      printf("%d\n", a);
    } else {
      g[b] += g[a]/2;
      g[a] = -b;
      printf("%d\n", b);
    }
  }
}
