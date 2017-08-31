#include <stdio.h>
#include <math.h>

#define CALC(x) (A * (x) * (x) + B * (x) + C)

int gcd(int a, int b)
{
  int t;
  if (b<0) b = -b;
  while (b != 0)
  {
    t = a % b;
    a = b;
    b = t;
  }
  return a;
}

int main()
{
  int A, B, C;
  scanf("%d %d %d", &A, &B, &C);
  int y = B * B - 4 * A * C;
  int x = (int)sqrt((double)y);
  if (y >= 0 && x * x == y)
  {
    int a, b, c, d, ga, gc, r;
    a = c = 2 * A;
    b = B + x;
    d = B - x;
    ga = gcd(a, b);
    gc = gcd(c, d);
    a /= ga;
    b /= ga;
    c /= gc;
    d /= gc;
    r = A /a/c;
    if (a < c)
    {
      printf("%d %d ", a, b);
      a = c;
      b = d;
    }
    else if (c < a)
    {
      printf("%d %d ", c, d);
    }
    else
    {
      if (b < d)
      {
        printf("%d %d ", a, b);
        a = c;
        b = d;
      }
      else
      {
        printf("%d %d ", c, d);
      }
    }
    printf("%d %d", a * r, b * r);
  }
  else
    printf("No Solution\n");
}