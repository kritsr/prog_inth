#include <stdio.h>
#include <string.h>

int main()
{
  int x, y;
  scanf("%d %d", &x, &y);
  if (x > y) printf("2\n");
  else printf("%d\n", ((y - 1) / x) + 1);
}
