#include <ctype.h>
#include <string.h>
#include <stdio.h>
int check(char MAP[25][25], char *word, int L, int I, int J)
{
  // 8 direction
  for (int dx = -1; dx <= 1; dx++)
  {
    for (int dy = -1; dy <= 1; dy++)
    {
      if (dx || dy)
      {
        for (int i = 0; i <= L; i++)
        {
          if (i == L)
            return 1;
          if (MAP[I + i * dx][J + i * dy] != word[i])
            break;
        }
      }
    }
  }
  return 0;
}
int main()
{
  int R, C;
  scanf("%d %d\n", &R, &C);
  char MAP[25][25];
  memset(MAP, 0, 25 * 25);
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      scanf("%c", &MAP[i][j]);
      MAP[i][j] = tolower(MAP[i][j]);
    }
    getchar();
  }
  int K;
  scanf("%d", &K);
  char word[16];
  for (int _i = 0; _i < K; _i++)
  {
    int f = 1;
    scanf("%s", word);
    int L = strlen(word);
    for (int i = 0; i < L; i++)
    {
      word[i] = tolower(word[i]);
    }
    for (int i = 0; i < R && f; i++)
    {
      for (int j = 0; j < C && f; j++)
      {
        if (check(MAP, word, L, i, j))
        {
          f = 0;
          printf("%d %d\n", i, j);
        }
      }
    }
  }
  return 0;
}