#include <stdio.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int main() {
  int N;
  scanf("%d\n", &N);
  int X[N], H[N];
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &X[i], &H[i]);
  }
  int bound, maxCnt, maxI, cI, cnt;
  // Go right
  maxCnt = 0;
  bound = X[0] + H[0];
  cI = 0;
  cnt = 1;
  for (int i = 1; i < N; i++) {
    if (X[i] < bound) {
      if (++cnt > maxCnt) {
        maxCnt = cnt;
        maxI = cI;
      }
    } else {
      cI = i;
      cnt = 1;
    }
    bound = MAX(bound, X[i] + H[i]);
  }
  int maxRi = maxI;
  int maxRCnt = maxCnt;
  // Go left
  maxCnt = 0;
  bound = X[N-1] - H[N-1];
  cI = N-1;
  cnt = 1;
  for (int i = N-2; i >= 0; i--) {
    if (X[i] > bound) {
      if (++cnt > maxCnt) {
        maxCnt = cnt;
        maxI = cI;
      }
    } else {
      cI = i;
      cnt = 1;
    }
    bound = MIN(bound, X[i] - H[i]);
  }
  int maxLi = maxI;
  int maxLCnt = maxCnt;
  if (maxLCnt > maxRCnt) {
    printf("%d L\n", maxLi + 1);
  } else if (maxLCnt < maxRCnt) {
    printf("%d R\n", maxRi + 1);
  } else if (maxLi > maxRi){
    printf("%d R\n", maxRi + 1);
  } else {
    printf("%d L\n", maxLi + 1);
  }
}
