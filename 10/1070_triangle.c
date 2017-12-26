#include <stdio.h>

int main() {
  int N, min1, min2, max = 0;
  min1 = min2 = 100000;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int l;
    scanf("%d", &l);
    if (l > max) max = l;
    if (l <= min1) {
      min2 = min1;
      min1 = l;
    } else if (l < min2) {
      min2 = l;
    }
  }
  if (min1 + min2 <= max)
    printf("yes\n");
  else
    printf("no\n");
}
