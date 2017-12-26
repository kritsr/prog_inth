#include <stdio.h>

typedef struct stock
{
  int amount;
  double price;
} stock;

void swap(stock *a, stock *b)
{
  stock t;
  t = *a;
  *a = *b;
  *b = t;
}
int partition(stock a[], int l, int h)
{
  double p = a[h].price;
  int i = l - 1;
  for (int j = l; j < h; j++)
  {
    if (a[j].price <= p && i++ != j)
    {
      swap(a + i, a + j);
    }
  }
  swap(a + i + 1, a + h);
  return i + 1;
}
void qsort(stock a[], int l, int h)
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
  int N, M;
  scanf("%d", &N);
  stock st[N];
  for (int i = 0; i < N; i++)
  {
    int p, q;
    scanf("%d %d", &p, &q);
    st[i].amount = q;
    st[i].price = (double)p / q;
  }
  qsort(st, 0, N - 1);
  scanf("%d", &M);
  int i = 0;
  for (int _i = 0; _i < M; _i++)
  {
    int q;
    double p = 0;
    scanf("%d", &q);
    while (q > 0)
    {
      if (st[i].amount > q)
      {
        st[i].amount -= q;
        p += st[i].price * q;
        q = 0;
      }
      else
      {
        q -= st[i].amount;
        p += st[i].price * st[i].amount;
        i++;
      }
    }
    printf("%.03f\n", p);
  }
}
