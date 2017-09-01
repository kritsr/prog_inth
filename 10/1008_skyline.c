#include <stdio.h>

#define MAX(a,b) a>b?a:b
#define MAX_NUM 255
int main()
{
  int N;
  scanf("%d", &N);
  int skyline[MAX_NUM+1] = {0};
  for (int i = 0; i < N; i++)
  {
    int l, h, r;
    scanf("%d %d %d", &l, &h, &r);
    for (int j = l; j < r; j++){
      skyline[j] = MAX(skyline[j], h);
    }
  }
  int h = 0;
  for (int i = 1; i <= MAX_NUM; i++)
  {
    if (h != skyline[i])
    {
      printf("%d %d ", i, skyline[i]);
    }
    h = skyline[i];
  }
  return 0;
}