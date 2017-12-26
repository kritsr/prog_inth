#include <stdio.h>
int main(){
  int K, N;
  scanf("%d %d", &K, &N);
  int d = 0, a = 1, b = 2, i = 1;
  while (N >= a){
    d += ((N+a)/b) * i;
    i++;
    a = b;
    b *= 2;
  }
  printf("%d\n", d);
}
