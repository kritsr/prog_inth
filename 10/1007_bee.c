#include <stdio.h>

#define MAX_YEAR 24
int bee[MAX_YEAR + 1][2]; // max 24 years

int main()
{
  // Precalc - Can be improved to real time calc and cache
  bee[0][0] = 1;
  bee[0][1] = 0;
  for (int i = 1; i <= MAX_YEAR; i++)
  {
    bee[i][1] = bee[i - 1][0];
    bee[i][0] = 1 + bee[i - 1][0] + bee[i - 1][1];
  }
  int y;
  scanf("%d", &y);
  while (y != -1)
  {
    printf("%d %d\n", bee[y][0], 1 + bee[y][0] + bee[y][1]);
    scanf("%d", &y);
  }
}
