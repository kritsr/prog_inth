#include<stdio.h>
#include<string.h>
int main() {
  int n;
  scanf("%d", &n);
  int N = n*2;
  int d[N];
  memset(d, 0, sizeof(d));
  for (int i = 0; i < N; i++) {
    int t, min = 0;
    for (int j = 0; j < N; j++) {
      scanf("%d", &t);
      t += d[j];
      if (j > 1 && j < i) {
        if (t < min) min = t;
      }
      else if (j == 1){
        min = t;
      }
    }
    d[i] = min;
  }
  printf("%d\n", d[N-1]);
}
