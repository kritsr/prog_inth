#include<stdio.h>
void printb(int val, int N) {
  for (int d = 1 << (N-1); d > 0; d >>= 1) {
    if (val & d) printf("1");
    else printf("0");
  }
}
int main(){
  int N;
  scanf("%d", &N);
  int max = 1;
  for (int i = 0; i < N; i++) max *= 2;
  max -= 1;
  for (int i = 0; i < max; i++) {
    for (int d = 1; d < max; d <<= 1) {
      if (!(i & d)) {
        int j = i | d;
        printb(i, N);printf(" ");
        printb(j, N);printf("\n");
      }
    }
  }
}
