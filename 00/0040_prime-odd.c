#include <stdio.h>
int main()
{
  int N;
  scanf("%d", &N);
  for (int _i = 0; _i < N; _i++)
  {
    char c = 0, p;
    int r, cnt = 0;
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9')
    {
      p = c;
      cnt++;
      c = getchar();
    }
    p = p - '0';
    r = (p & 1) || ((cnt == 1) && (p == 2));
    if (r)
    {
      printf("T\n");
    }
    else
    {
      printf("F\n");
    }
  }
  return 0;
}