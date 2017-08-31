#include <stdio.h>
#include <string.h>

int main()
{
  char team[4][21];
  int scoreboard[4][4];
  for (int i = 0; i < 4; i++)
    gets(team[i]);

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      scanf("%d", scoreboard[i] + j);
    }
  }
  int s[3][4];
  memset(s, 0, 12 * sizeof(int));
  for (int i = 0; i < 3; i++)
    for (int j = i + 1; j < 4; j++)
    {
      if (scoreboard[i][j] > scoreboard[j][i])
      {
        s[0][i] += 3;
      }
      else if (scoreboard[i][j] < scoreboard[j][i])
      {
        s[0][j] += 3;
      }
      else
      {
        s[0][i] += 1;
        s[0][j] += 1;
      }
      s[1][i] += scoreboard[i][j] - scoreboard[j][i];
      s[2][i] += scoreboard[i][j];
      s[1][j] += scoreboard[j][i] - scoreboard[i][j];
      s[2][j] += scoreboard[j][i];
    }
  // for (int i = 0; i < 4; i++){
  //   printf("%d %d %d %s\n", s[0][i], s[1][i], s[2][i], team[i]);
  // }
  for (int _n = 0; _n < 4; _n++)
  {
    int i0 = 0;
    for (int i = 1; i < 4; i++)
    {
      if (s[0][i] > s[0][i0])
      {
        i0 = i;
      }
      else if (s[0][i] == s[0][i0])
      {
        if (s[1][i] > s[1][i0])
        {
          i0 = i;
        }
        else if (s[1][i] == s[1][i0])
        {
          if (s[2][i] > s[2][i0])
          {
            i0 = i;
          }
        }
      }
    }
    printf("%s %d\n", team[i0], s[0][i0]);
    s[0][i0] = -1;
    s[1][i0] = -1;
    s[2][i0] = -1;
  }
  return 0;
}