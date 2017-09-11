#include <stdio.h>

int max_diff(int a, int b, int c)
{
  int min, max;
  min = max = a;
  if (b > max)
    max = b;
  else
    min = b;
  if (c > max)
    max = c;
  if (c < min)
    min = c;
  return max - min;
}

int main()
{
  int N;
  scanf("%d", &N);
  int prof[N];
  scanf("%d", prof);
  int sum[N];
  sum[0] = prof[0];
  for (int i = 1; i < N; i++)
  {
    scanf("%d", prof + i);
    sum[i] = sum[i - 1] + prof[i];
  }
  int bi = 1, ci = 2, mindiff = 2001;
  for (int j = 1; j < N - 1; j++)
  {
    for (int k = j + 1; k < N; k++)
    {
      int a = sum[j - 1];
      int b = sum[k - 1] - sum[j - 1];
      int c = sum[N - 1] - sum[k - 1];
      
      int diff = max_diff(a,b,c);
      if (diff < mindiff){
        mindiff = diff;
        bi = j;
        ci = k;
        if (diff == 0) {
          printf("%d %d", bi + 1, ci + 1);
          return 0;
        }
      }
    }
  }
  printf("%d %d", bi + 1, ci + 1);
  return 0;
}