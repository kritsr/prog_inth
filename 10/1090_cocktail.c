#include <stdio.h>

int main(){
  int tail[1000001] = {};
  int N, A;
  unsigned long long ans = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    int a;
    scanf("%d", &a);
    tail[a]++;
  }
  scanf("%d", &A);
  for (int i = 0, j = A; j > i; i++,j--){
    ans += (unsigned long long)tail[i] * tail[j];
  }
  if (A % 2 == 0) {
    ans += (unsigned long long)tail[A/2] * (tail[A/2]-1) / 2;
  }
  printf("%lld\n", ans);
  return 0;
}