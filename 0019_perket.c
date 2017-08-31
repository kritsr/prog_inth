#include <stdio.h>
#include <string.h>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define DIFF(a,b) ((a)>(b)?(a)-(b):(b)-(a))
int main()
{
  int N;
  scanf("%d", &N);
  int s[N], p[N];
  int diff = 1000000000;
  for (int i = 0; i < N; i++)
  {
    scanf("%d %d", p + i, s + i);
  }
  int lim = 1 << N;
  for (int i = 1; i < lim; i++)
  {
    int sum = 0, prod = 1;
    for (int j = 0; j < N; j++)
    {
      if (i & (1 << j))
      {
        sum += s[j];
        prod *= p[j];
      }
    }
    diff = MIN(DIFF(sum,prod), diff);
  }
  printf("%d\n", diff);
  return 0;
}