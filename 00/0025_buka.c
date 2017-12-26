#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define DIFF(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))
int main()
{
  char i1[101], i2[101], o[2];
  gets(i1);
  gets(o);
  gets(i2);
  if (o[0] == '*')
  {
    printf("%s%s", i1, i2+1);
  }
  else
  {
    int l1 = strlen(i1);
    int l2 = strlen(i2);
    if (l1 == l2)
    {
      i1[0] = '2';
      printf("%s", i1);
    }
    else if (l1 > l2)
    {
      i1[l1-l2] = 0;
      printf("%s%s", i1, i2);
    }
    else
    {
      i2[l2-l1] = 0;
      printf("%s%s", i2, i1);
    }
  }
}
