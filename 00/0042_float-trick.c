#include <stdio.h>
#include <math.h>

int main(){
  int N;
  unsigned long long e;
  scanf("%d", &N);
  for (int _i = 0; _i < N; _i++){
    scanf("%ld", &e);
    long double x = 1;
    for (unsigned long long i = 0; i < e; i++) x *= 2;
    printf("%.0LF\n", x);
  }
  return 0;
}