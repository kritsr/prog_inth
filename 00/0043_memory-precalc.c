#include <stdio.h>

#define G(i, j, k) ((i * j * k) % (i + j + k))

int main()
{
  unsigned long long result[300] = {};
  for (int n = 300; n <= 300; n++)
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
    result[n-1] = r;
  }
  printf("{%lu", result[0]);
  for (int i = 1; i < 300; i++){
    printf(",%lu", result[i]);
  }
  printf("}\n");
}
