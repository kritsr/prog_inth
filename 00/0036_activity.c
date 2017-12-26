#include <stdio.h>
int main()
{
  int N;
  scanf("%d", &N);
  unsigned long long t = N & 1;
  int m = N / 2;
  t++;
  for (int i = N; i > N-m; i--){
    t *= i;
  }
  for (int i = 2; i <= m; i++){
    t /= i;
  }
  printf("%lu\n", t);
}
