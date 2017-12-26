#include <stdio.h>
#include <string.h>
#define MIN(a, b) (a < b ? a : b)
int main()
{
  int W, H, N;
  scanf("%d %d %d", &W, &H, &N);
  int filter[W];
  memset(filter, 0, sizeof(filter));
  for (int i = 0; i < N; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    y = MIN(W, x + y);
    for (; x < y; x++)
    {
      filter[x]++;
    }
  }
  int a = 0, b = 0;
  for (int i = 0; i < W; i++)
  {
    if (filter[i] == 0)
      a += H;
    else if (filter[i] == 1)
      b += H;
  }
  printf("%d %d\n", a, b);
}
