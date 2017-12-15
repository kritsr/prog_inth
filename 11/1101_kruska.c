#include<stdio.h>
long long dstate[200][200][7][4];
int kstate[200][200][7][4];
char wiz[200][200][8];
int main() {
  int N, K, m;
  scanf("%d %d %d", &N, &K, &m);
  int x, y;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &y, &x);
    scanf("%s", wiz[y-1][x-1]);
  }
  int dx = 1, dy = 0, dow = 0, t, dir = 0, loop = 0;
  long long d = 0, k = 0;
  x = y = 0;
  while (k < K) {
    x += dx; y += dy; d++; dow = (dow + 1) % 7;
    int c = 1;
    if (wiz[y][x][dow] == 'R') {t = dy; dy = dx; dx = -t; k++;dir = (dir+1)%4;c=0;}
    else if (wiz[y][x][dow] == 'L') {t = dx; dx = dy; dy = -t; k++;dir = (dir+3)%4;c=0;}
    if (x+dx >= N || x+dx < 0) {k++;dx = -dx;dir = (dir+2)%4;c=0;}
    else if (y+dy >= N || y+dy < 0) {k++;dy = -dy;dir = (dir+2)%4;c=0;}
    if (c || loop) continue;
    if (kstate[y][x][dow][dir] == 0) {
      dstate[y][x][dow][dir] = d;
      kstate[y][x][dow][dir] = k;
    } else {
      loop = 1;
      int kl = k - kstate[y][x][dow][dir];
      long long dl = d - dstate[y][x][dow][dir];
      int l = (K-k)/kl;
      k += kl*l;
      d += dl*l;
    }
  }
  printf("%ld\n", d);
}
