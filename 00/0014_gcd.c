#include <stdio.h>
#define SWAP(a,b) {a^=b;b^=a;a^=b;}
int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  while (b != 0)
  {
    a %= b;
    SWAP(a, b);
  }
  printf("%d\n", a);
}
