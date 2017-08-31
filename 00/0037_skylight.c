#include <stdio.h>
int main()
{
  unsigned int N, M, K, L, C, t, cost;
  scanf("%d %d %d %d %d", &N, &M, &L, &K, &C);
  cost = -1;
  for (int i = 0; i < N * M; i++)
  {
    scanf("%d", &t);
    cost += t;
  }
  cost = cost / C + 1;
  cost += L * K;
  printf("%d\n", cost);
  return 0;
}