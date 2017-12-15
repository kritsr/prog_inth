#include<stdio.h>
#define MAX (1000000)
int d[MAX + 1];
int main() {
  for (int i = 1; i < MAX; i++) {
    int j = i;
    while(j < MAX) {
      d[j]++;
      j += i;
    }
  }
  int Q;
  scanf("%d", &Q);
  for (int q = 0; q < Q; q++) {
    int a, b, c, ans = 0;
    scanf("%d %d %d", &a, &b, &c);
    for (int i = a; i <= b; i++) {
      if (d[i] == c) ans++;
    }
    printf("%d\n", ans);
  }
}
