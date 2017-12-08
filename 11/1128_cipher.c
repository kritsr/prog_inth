#include<stdio.h>
int main(){
  int N;
  scanf("%d", &N);
  long a[N];
  scanf("%ld", a);
  for (int i = 1; i < N; i++) {
    scanf("%ld", a+i);
    a[i] += a[i-1];
  }
  long s = 0;
  for (int i = 0; i < N; i++) {
    s = (s + (N-i) * a[i]) % 2553;
  }
  printf("%ld\n", s);
}
