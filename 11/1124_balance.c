#include <stdio.h>

int W[20];
int W_SUM[20];

int findWeight(int);
int main(){
  //Precalc
  W[0] = W_SUM[0] = 1;
  for (int i = 1; i < 20; i++){
    W[i] = W[i-1] * 3;
    W_SUM[i] = W_SUM[i-1] + W[i];
  }
  int w;
  scanf("%d", &w);
  int r = 0, n = 0;
  int i;
  while (w != 0) {
    if (w > 0) {
      i = findWeight(w);
      r += W[i];
      w -= W[i];
    } else {
      i = findWeight(-w);
      w += W[i];
    }
    n++;
  }
  printf("%d %d\n", n, r);
  return 0;
}

// Can be optimized to find from last index, desc
int findWeight(int n){
  int i = 0;
  while (W_SUM[i] < n) i++;
  return i;
}