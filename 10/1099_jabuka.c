#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b) {a^=b;b^=a;a^=b;}
int gcd(int a, int b);
int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  int g = gcd(a, b);
  div_t ra, rb;
  for (int i = 1; i <= g; i++)
  {
    ra = div(a, i);
    if (ra.rem == 0)
    {
      rb = div(b, i);
      if (rb.rem == 0)
      {
        printf("%d %d %d\n", i, ra.quot, rb.quot);
      }
    }
  }
}

int gcd(int a, int b)
{
  while (b != 0)
  {
    a %= b;
    SWAP(a, b);
  }
  return a;
}
