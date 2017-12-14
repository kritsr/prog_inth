#include<stdio.h>
int main() {
  int n, max, min, ans = 0;
  scanf("%d", &n);
  scanf("%d", &min);
  max = min;
  for (int i = 1; i < n; i++) {
    int b; // Current
    scanf("%d", &b);
    if (b > max) {
      if (max - min > ans) ans = max - min;
      max = min = b;
    } else if (b < min) min = b;
  }
  if (max - min > ans) ans = max - min;
  printf("%d.%d00000\n", ans/2, ans%2==0?0:5);
}