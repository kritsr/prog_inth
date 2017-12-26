// LIS
#include<stdio.h>
int main(){
  int N;
  scanf("%d", &N);
  int h[N], l[N], max = 0;
  for (int i = 0; i < N; i++) scanf("%d", h+i);
  l[0] = h[0];
  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= max; j++)
      if (h[i] < l[j] && (j == 0 || h[i] > l[j-1])) l[j] = h[i];
    if (h[i] > l[max]) {
      l[++max] = h[i];
    }
  }
  printf("%d\n", max+1);
}
