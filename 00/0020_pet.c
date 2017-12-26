#include <stdio.h>
int main()
{
  int j, k = 0;
  for (int i = 1; i <= 5; i++)
  {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int s = a + b + c + d;
    if (s > k)
    {
      k = s;
      j = i;
    }
  }
  printf("%d %d\n", j, k);
}
