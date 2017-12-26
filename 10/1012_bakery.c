#include <stdio.h>

int main()
{
  int N;
  int A = 0, B = 0, C = 0, D = 0, E = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    A += a; // 4/4
    B += b; // 3/4
    C += c; // 2/4
    D += d; // 1/4
    E += e; // 1/8
  }
  A += B + C / 2;
  D -= B;
  if (C & 1)
  {
    A++;
    D -= 2;
  }
  if (D > 0)
  {
    A += D / 4;
    int x = 4 - (D % 4);
    if (x)
    {
      A++;
      E -= 2 * x;
    }
  }
  else if (D < 0)
  {
    E += D * 2;
  }
  if (E > 0)
  {
    A += (E+7) / 8;
  }
  printf("%d\n", A);
}
