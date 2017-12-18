#include<stdio.h>
int main(){
  int N, num[9] = {1}, cost[9], n = -1;
  scanf("%d", &N);
  for (int i = 1; i <= 9; i++) {
    int c;
    scanf("%d", &c);
    while (n >= 0 && c <= cost[n]) n--;
    cost[++n] = c;
    num[n] = i;
  }
  int digits = N / cost[0];
  N %= cost[0];
  for (int i = n; i > 0; i--) {
    cost[i] -= cost[0];
    int d = N / cost[i];
    N %= cost[i];
    if (d > digits) d = digits;
    digits -= d;
    while(d-- > 0) printf("%d", num[i]);
  }
  while(digits-- > 0) printf("%d", num[0]);
  printf("\n");
}
