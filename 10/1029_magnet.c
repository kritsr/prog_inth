#include <stdio.h>

void swap(int *a, int *b)
{
  int t;
  t = *a;
  *a = *b;
  *b = t;
}
int partition(int a[], int l, int h)
{
  int p = a[h];
  int i = l - 1;
  for (int j = l; j < h; j++)
  {
    if (a[j] <= p && i++ != j)
    {
      swap(a + i, a + j);
    }
  }
  swap(a + i + 1, a + h);
  return i + 1;
}
void qsort(int a[], int l, int h)
{
  if (l < h)
  {
    int pi = partition(a, l, h);
    qsort(a, l, pi - 1);
    qsort(a, pi + 1, h);
  }
}
int rmpair(int a[], int N)
{
  int p = a[0];
  int j = 0;
  int flip = 1;
  for (int i = 1; i < N + 1; i++)
  {
    if (a[i] == p)
    {
      flip = !flip;
    }
    else
    {
      if (flip)
      {
        a[j++] = p;
      }
      flip = 1;
      p = a[i];
    }
  }
  return j;
}
int solve(int v, int a[], int n, int N)
{
  if (v < a[0])
    return a[0] - 1;
  else if (v >= a[n-1])
    return N - a[n-1] + 1;
  else
  {
    int i = n / 2;
    int s = n / 4;
    while (1)
    {
      if (v < a[i])
        i -= s;
      else if (v >= a[i + 1])
        i += s;
      else{
        return a[i + 1] - a[i];
      }
      if (s >= 2)
        s /= 2;
    }
  }
}
int main()
{
  int N, M, Q;
  scanf("%d %d %d", &N, &M, &Q);
  int a, b, k;
  int f[2 * M + 1];
  f[2 * M] = -1;
  for (int i = 0; i < M; i++)
  {
    scanf("%d %d", &a, &k);
    b = a + k;
    f[2 * i + 0] = a;
    f[2 * i + 1] = b;
  }
  qsort(f, 0, 2 * M - 1);
  int n = rmpair(f, 2 * M);
  for (int i = 0; i < Q; i++)
  {
    scanf("%d", &a);
    printf("%d\n", solve(a, f, n, N));
  }
  return 0;
}