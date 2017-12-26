#include <stdio.h>
#include <string.h>

int main()
{
  int x, y, z;
  scanf("%d %d %d", &x, &y, &z);
  int r = 0;
  while (x > 1)
  {
    x >>= 1;
    r++;
  }
  while (y > 1)
  {
    y >>= 1;
    r++;
  }
  while (z > 1)
  {
    z >>= 1;
    r++;
  }
  printf("%d\n", r);
}
