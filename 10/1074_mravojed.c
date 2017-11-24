#include <stdio.h>

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  char map[N][M+1];
  for (int i = 0; i < N; i++)
    scanf("%s", map[i]);
  int x, y, z = 0;
  for (int i = 0; i < N && z == 0; i++)
    for (int j = 0; j < M && z == 0; j++)
      if (map[i][j] == 'x') {
        int z1 = 1; z = 1;
        for (int k = i+1; k < N; k++)
          if (map[k][j] == 'x') z1++;
          else break;
        for (int k = j+1; k < M; k++)
          if (map[i][k] == 'x') z++;
          else break;
        if (z > z1) z = z1;
        x = i+1;
        y = j+1;
      }
  printf("%d %d %d\n", x, y, z);
  for (int i = x-1; i < x-1+z; i++)
    for (int j = y-1; j < y-1+z; j++)
      map[i][j] = 'o';

  int z0 = z;
  z = 0;
  for (int i = N-1; i >= 0 && z == 0; i--)
    for (int j = M-1; j >= 0 && z == 0; j--)
      if (map[i][j] == 'x') {
        int z1 = 1; z = 1;
        for (int k = i-1; k >= 0; k--)
          if (map[k][j] == 'x') z1++;
          else break;
        for (int k = j-1; k >= 0; k--)
          if (map[i][k] == 'x') z++;
          else break;
        if (z < z1) z = z1;
        x = i-z+2;
        y = j-z+2;
        if (y-1 < 0 || map[x-1][y-1] == '.') y = j+1;
      }
  if (z == 0) z = z0;
  printf("%d %d %d\n", x, y, z);
  return 0;
}
