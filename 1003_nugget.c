#include <stdio.h>
int isNugget(int i)
{
  for (int a = i / 20; a >= 0; a--)
  {
    for (int b = (i - 20 * a) / 9; b >= 0; b--)
    {
      if (0 == (i - a * 20 - b * 9) % 6)
      {
        return 1;
      }
    }
  }
  return 0;
}
int main()
{
  int N, f = 0;
  scanf("%d", &N);
  for (int i = 6; i <= N; i++)
  {
    if (isNugget(i))
    {
      f = 1;
      printf("%d\n", i);
    }
  }
  if (!f) printf("no\n");
}