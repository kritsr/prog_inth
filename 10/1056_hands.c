//10.09
//19.17 > 8 min
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
int main(){
  int N, K;
  scanf("%d %d\n", &N, &K);
  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d\n", A+i);
  }
  qsort(A, 0, N-1);
  int sum = 0;
  for (int i = N-1; i > 0; i -= K) {
    sum += A[i];
  }
  printf("%d\n", sum);
  return 0;
}
