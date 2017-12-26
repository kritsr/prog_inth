#include <stdio.h>
int main(){
  int n, q, a, b;
  scanf("%d", &n);
  int p[n];
  scanf("%d", &a);
  p[0] = 0;
  for (int i = 1; i < n; i++) {
    scanf("%d", &b);
    if (b > a) {
      p[i] = p[i-1] + b - a;
    } else {
      p[i] = p[i-1];
    }
    a = b;
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d", &a, &b);
    printf("%d\n", p[b-1] - p[a-1]);
  }
}
