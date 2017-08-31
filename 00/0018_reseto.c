#include <stdio.h>
#include <string.h>

int main()
{
  int N, K;
  scanf("%d %d", &N, &K);
  unsigned char map[N + 1];
  memset(map, 1, N+1);
  for (int n = 2; n <= N; n++)
  {
    if (map[n])
    {
      for (int x = n; x <= N; x += n)
      {
        if (map[x])
        {
          map[x] = 0;
          if (--K == 0)
          {
            printf("%d\n", x);
            return 0;
          }
        }
      }
    }
  }
  return 0;
}