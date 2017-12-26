#include <stdio.h>

char getChr(int digit, int times) {
  if (digit == 1) {
    return -times;
  } else if (digit >= 2 && digit <= 6) {
    return 'A' + (digit-2)*3 + (times-1) % 3;
  } else if (digit == 7) {
    return 'P' + ((times-1)%4);
  } else if (digit == 8) {
    return 'T' + ((times-1)%3);
  } else if (digit == 9) {
    return 'W' + ((times-1)%4);
  }
  return 0;
}

int main() {
  int N, S, M;
  scanf("%d\n", &N);
  char word[N+1], c;
  int t, x, y, dx, dy, j = 0;
  scanf("%d %d\n", &x, &t);
  c = getChr(x, t);
  if (c > 0) word[j++] = c;
  y = x/3;
  x = x%3;
  while (--N > 0) {
    scanf("%d %d %d\n", &dx, &dy, &t);
    x += dx;
    y += dy;
    c = getChr(y*3+x, t);
    if (c < 0) {
      j += c;
      if (j < 0) j = 0;
    }
    else word[j++] = c;
  }
  if (j > 0) {
    word[j] = 0;
    printf("%s\n", word);
  } else printf("null\n");
}
