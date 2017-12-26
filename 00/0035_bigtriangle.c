//brute
#include <stdio.h>

#define ABS(x) ((x) > 0 ? (x) : -(x))
#define AREAx2 (x[i] * y[j] + x[j] * y[k] + x[k] * y[i] - x[i] * y[k] - x[k] * y[j] - x[j] * y[i])
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int main()
{
  int N, t, max = 0;
  scanf("%d", &N);
  int x[N], y[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d %d", x + i, y + i);
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      for (int k = j + 1; k < N; k++)
      {
        t = AREAx2;
        t = ABS(t);
        max = MAX(max, t);
      }
    }
  }
  printf("%d.", max >> 1);
  if (max & 1)
  {
    printf("500\n");
  }
  else
  {
    printf("000\n");
  }
}
