#include <stdio.h>
int main()
{
  int score['H'] = {};
  char c;
  int cnt = 7;
  while ('!' != (c = getchar()))
  {
    while (10 != c)
    {
      if (score[c] >= 0)
        score[c]++;
      c = getchar();
    }
    if (cnt > 1)
    {
      int min = 1 << 20;
      char outer = 0;
      for (char i = 'A'; i <= 'G'; i++)
      {
        if (score[i] >= 0)
        {
          if (score[i] < min)
          {
            outer = i;
            min = score[i];
          }
          else if (score[i] == min)
          {
            outer = 0;
          }
        }
      }
      if (outer)
      {
        score[outer] = -1;
        cnt--;
      }
    }
  }

  printf("%d\n", cnt);
  while (cnt > 0)
  {
    int max = 0;
    for (int i = 'A'; i <= 'G'; i++)
    {
      if (score[i] > max)
        max = score[i];
    }
    for (int i = 'A'; i <= 'G'; i++)
    {
      if (score[i] == max)
      {
        printf("%c %d\n", i, score[i]);
        score[i] = -1;
        cnt--;
      }
    }
  }
}
