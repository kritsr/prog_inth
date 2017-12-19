#include<stdio.h>
int main(){
  int N;
  scanf("%d", &N);
  int A[N];
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", A+i);
    ans += A[i];
  }
  ans += (long long)A[0] * (N-3);
  int x = 2*A[1] - A[0];
  for (int i = N-2; i > 1; i--) {
    if (A[i] > x) ans = ans - A[i--] + x;
  }
  printf("%ld\n", ans);
}
