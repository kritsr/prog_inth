#include <stdio.h>

int main() {
  int N, K;
  scanf("%d %d\n", &N, &K);
  int A[N], score[K], n = N, ci = 0, cp = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d\n", A+i);
  }
  for (int i = 0; i < K; i++) score[i] = 0;
  for (int i = 0; i < N; i++) {
    int d;
    scanf("%d\n", &d);
    ci = (ci + d) % n;
    score[cp] += A[ci];
    cp = (cp+1)%K;
    n--;
    for (int j = ci; j < n; j++) {
      A[j] = A[j+1];
    }
  }
  for (int i = 0; i < K; i++) {
    printf("%d\n", score[i]);
  }
}
