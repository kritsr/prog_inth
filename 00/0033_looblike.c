#include <stdio.h>

int main()
{
  int N, m = 0, f = 0;
  scanf("%d", &N);
  int like[10000] = {0};
  for (int _i = 0; _i < N; _i++)
  {
    int i;
    scanf("%d", &i);
    if (m < ++like[i - 1])
    {
      m = like[i - 1];
    }
  }
  for (int i = 0; i < 10000; i++)
  {
    if (like[i] == m)
    {
      if (f){
        printf(" %d", i + 1);
      }else{
        printf("%d", i + 1);
        f = 1;
      }
    }
  }
}