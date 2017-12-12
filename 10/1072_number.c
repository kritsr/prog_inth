#include<stdio.h>
int N, dir = 1, a_i = 0;
int geti(int i) {
  return (a_i + (dir*(i-1)) + N) % N;
}
int main(){
  int M;
  scanf("%d %d", &N, &M);
  int a[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < M; i++) {
    char cmd;
    scanf(" %c", &cmd);
    int x, y, t;
    if (cmd == 'a') {
      scanf("%d %d", &x, &y);
      int ix = geti(x), iy = geti(y);
      t = a[ix]; a[ix] = a[iy]; a[iy] = t;
    } else if (cmd == 'b') {
      scanf("%d %d", &x, &y);
      a[geti(x)] = y;
    } else if (cmd == 'c') {
      scanf("%d", &x);
      a_i = geti(x);
      dir *= -1;
    } else {
      scanf("%d", &x);
      printf("%d\n", a[geti(x)]);
    }
  }
}
