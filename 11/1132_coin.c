#include<stdio.h>
void solve(){
  int N, K, n = 1;
  scanf("%d %d", &N, &K);
  N -= K-1;
  while (n < N) n *= 2;
  if (n == N) printf("B\n");
  else printf("A\n");
}
int main(){
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) solve();
}
