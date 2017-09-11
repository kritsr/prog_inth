#include <stdio.h>

void swap(long long *a, long long *b)
{
  long long t;
  t = *a;
  *a = *b;
  *b = t;
}
long long lcm(long long a, long long b)
{
  long long x = a * b;
  while (b != 0)
  {
    a %= b;
    swap(&a, &b);
  }
  return x / a;
}
int main(){
  int N;
  scanf("%d", &N);
  long long a;
  int b;
  scanf("%d", &b);
  a = b;
  for (int i = 1; i < N; i++){
    scanf("%d", &b);
    a = lcm(a,b);
  }
  printf("%d\n", a);
  return 0;
}
