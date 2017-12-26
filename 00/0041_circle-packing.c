#include <stdio.h>
#include <math.h>

int main()
{
  int n;
  scanf("%d", &n);
  double r = n & 14;
  if (n == 1) {
    r += 2;
  } else if (n == 3) {
    r += sqrt(3);
  } else if (n & 1)
    r += -2 + 2 * sqrt(3);
  printf("%0.6lf\n", r);
}
