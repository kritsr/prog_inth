#include <stdio.h>

int MAP[20][20];
int MEMO[20][20];
int M;

int max (int a, int b) {
  return a>b?a:b;
}

int findMax(int x, int y) {
  if (MEMO[y][x] > 0) return MEMO[y][x];
  int m = MAP[y][x];
  if (x > 0 && MAP[y][x-1] > MAP[y][x]) m = max(m,findMax(x-1,y));
  if (y > 0 && MAP[y-1][x] > MAP[y][x]) m = max(m,findMax(x,y-1));
  if (x < M-1 && MAP[y][x+1] > MAP[y][x]) m = max(m,findMax(x+1,y));
  if (y < M-1 && MAP[y+1][x] > MAP[y][x]) m = max(m,findMax(x,y+1));
  MEMO[y][x] = m;
  return m;
}

int main() {
  scanf("%d", &M);
  int x, y;
  scanf("%d %d", &x, &y);
  --x;--y;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &MAP[i][j]);
      if (MAP[i][j] == 100) MAP[i][j] = -100;
      MEMO[i][j] = -10;
    }
  }
  printf("%d\n", findMax(x, y));
  return 0;
}
