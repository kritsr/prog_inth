#include<stdio.h>
int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  char spd[2000001] = {0};
  int t;
  for (int i = 0; i < N; i++) {
    scanf("%d", &t);
    spd[t] = 1;
  }
  int s = 2000001;
  while (K-- > 0) {
    while(spd[--s] == 0);
  }
  printf("%d\n", s);
}
