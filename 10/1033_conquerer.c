#include <stdio.h>
#include <string.h>

typedef struct status
{
  int x;
  int y;
  int score;
} status;

int main()
{
  int N, K;
  scanf("%d %d\n", &N, &K);
  int cnt = N * N - 4;
  int table[N][N];
  int turn[4 * K];
  for (int i = 0; i < 4; i++)
    for (int k = 0; k < K; k++)
      scanf("%c\n", &turn[4 * k + i]);
  status player[4] = {{N - 1, 0, 1}, {N - 1, N - 1, 1}, {0, N - 1, 1}, {0, 0, 1}};
  memset(table, 0, sizeof(table));
  for (int i = 0; i < 4; i++)
    table[player[i].x][player[i].y] = i + 1;
  int k = 0;
  for (int _i = 0; _i < K; _i++)
    for (int i = 0; i < 4; i++)
    {
      char dir = turn[k++];
      int dx, dy;
      switch (dir)
      {
      case 'N': dx = 0; dy = -1; break;
      case 'S': dx = 0; dy = 1; break;
      case 'E': dx = 1; dy = 0; break;
      case 'W': dx = -1; dy = 0; break;
      }
      int px = player[i].x + dx;
      int py = player[i].y + dy;
      if (px < N && px >= 0 && py < N && py >= 0)
      {
        if (table[px][py] == 0)
          cnt--;
        else if (player[table[px][py] - 1].x == px && player[table[px][py] - 1].y == py)
          continue;
        else
          player[table[px][py] - 1].score--;
        player[i].x = px;
        player[i].y = py;
        player[i].score++;
        table[px][py] = i + 1;
      }
    }
  if (cnt)
    printf("No\n");
  else
  {
    int m = 0, n = 0;
    for (int i = 0; i < 4; i++)
    {
      if (player[i].score > m)
      {
        n = 1;
        m = player[i].score;
      }
      else if (player[i].score == m)
        n++;
    }
    printf("%d %d\n", n, m);
    for (int i = 0; i < 4; i++)
      if (player[i].score == m)
        printf("%d\n", i + 1);
  }
  return 0;
}