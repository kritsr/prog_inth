#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);
  int exp = ((N * N + 1) * N) / 2;
  int map[N][N];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      scanf("%d", &map[i][j]);
    }
  }
  int s3 = 0, s4 = 0;
  for (int i = 0; i < N; i++)
  {
    int s1 = 0, s2 = 0;
    for (int j = 0; j < N; j++)
    {
      s1 += map[i][j];
      s2 += map[j][i];
    }
    if (s1 != exp || s2 != exp)
    {
      printf("No\n");
      return 0;
    }
    s3 += map[i][i];
    s4 += map[N-1-i][i];
  }
  if (s3 != exp || s4 != exp)
  {
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  return 0;
}