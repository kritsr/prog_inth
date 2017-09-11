#include <stdio.h>

typedef struct ladder
{
  int from;
  int to;
} ladder;
void swap(ladder *a, ladder *b)
{
  ladder t;
  t = *a;
  *a = *b;
  *b = t;
}
int partition(ladder a[], int l, int h)
{
  double p = a[h].to;
  int i = l - 1;
  for (int j = l; j < h; j++)
  {
    if (a[j].to <= p && i++ != j)
    {
      swap(a + i, a + j);
    }
  }
  swap(a + i + 1, a + h);
  return i + 1;
}
void qsort(ladder a[], int l, int h)
{
  if (l < h)
  {
    int pi = partition(a, l, h);
    qsort(a, l, pi - 1);
    qsort(a, pi + 1, h);
  }
}
int main()
{
  int K, N, M;
  scanf("%d %d %d", &K, &N, &M);
  ladder ladders[M];
  int floor[N + 1];
  floor[1] = 0;
  for (int i = 0; i < M; i++)
  {
    scanf("%d %d", &(ladders + i)->from, &(ladders + i)->to);
  }
  for (int i = 2; i <= N; i++){
    floor[i] = K+1;
  }
  qsort(ladders, 0, M-1);
  int max = 1;
  for (int i = 0; i < M; i++)
  {
    int a = floor[ladders[i].from] + 1;
    if (floor[ladders[i].to] > a){
      floor[ladders[i].to] = a;
    }
    if (floor[ladders[i].to] <= K && ladders[i].to > max)
      max = ladders[i].to;
    
  }
  printf("%d\n", max);
  return 0;
}