#include<stdio.h>
#include<string.h>
int main(){
  int W, H, K;
  scanf("%d %d %d", &W, &H, &K);
  int map0[H][W], map[H][W];
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      scanf("%d", &map0[i][j]);
  for (int i = 0; i < K; i++) {
    int x, y;
    scanf("%d %d", &x, &y);--x;--y;
    memcpy(map, map0, sizeof(map));
    while (1) {
      if (x >= W) printf("E\n");
      else if (x < 0) printf("W\n");
      else if (y >= H) printf("S\n");
      else if (y < 0) printf("N\n");
      else if (map[y][x] == 0) printf("NO\n");
      else {
        int t = map[y][x];
        map[y][x] = 0;
        if (t % 2 == 0 ) x += 3 - t;
        else y += t - 2;
        continue;
      }
      break;
    }
  }
}
