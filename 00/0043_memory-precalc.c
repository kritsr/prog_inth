#include <stdio.h>

#define G(i, j, k) ((i * j * k) % (i + j + k))

int main()
{
  for (int n = 1; n <= 300; n++)
  {
    unsigned long long r = 0;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n + i; j++)
      {
        for (int k = 1; k <= n + i + j; k++)
        {
          r += G(i, j, k);
        }
      }
    }
    printf("%d: %lu\n", n, r);
  }
  return 0;
}