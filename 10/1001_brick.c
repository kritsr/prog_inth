#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int H, W;
  scanf("%d %d", &H, &W);
  int obs[W];
  int bricks[W + 1];
  char map[H][W + 1];
  for (int i = 0; i < W; i++){
    obs[i] = -1;
  }
  memset(map, 0, H * (W + 1) * sizeof(char));
  for (int h = H - 1; h >= 0; h--)
  {
    scanf("%s", map[h]);
    for (int x = 0; x < W; x++)
    {
      if (map[h][x] == 'O' && obs[x] == -1)
      {
        obs[x] = h;
      }
    }
  }
  for (int i = 0; i < W; i++)
  {
    scanf("%d", bricks + i);
  }
  for (int x = 0; x < W; x++)
  {
    for (int h = obs[x] + 1; h < H && h <= obs[x] + bricks[x]; h++){
      map[h][x] = '#';
    }

  }
  for (int h = H - 1; h >= 0; h--)
  {
    puts(map[h]);
  }
}
