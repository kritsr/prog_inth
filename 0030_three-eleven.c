#include <stdio.h>
#include <string.h>

int main()
{
  char c;
  int m3 = 0, _m11a = 0, _m11b = 0;
  int *m11a = &_m11a;
  int *m11b = &_m11b;
  int *tmp;
  while (10 != (c = getchar()))
  {
    c -= '0';
    m3 = (m3 + c) % 3;
    *m11a = (*m11a + c) % 11;
    tmp = m11a;
    m11a = m11b;
    m11b = tmp;
  }
  printf("%d %d\n", m3, (11 + *m11b - *m11a) % 11);
  return 0;
}