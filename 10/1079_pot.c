#include<stdio.h>
int main(){
  int n, k, i = 1, s = 1, j = 0;
  scanf("%d %d", &n, &k);
  int a[n];
  a[0] = 1;
  while (i < n && i < k) {
    a[i] = (a[i-1]*2) % 2009;
    s = (s+a[i])%2009;
    i++;
  }
  if (i < n) {
    a[i] = s;
  }
  while (++i < n) {
    a[i] = (2*a[i-1]-a[j++]+2009)%2009;
  }
  printf("%d\n", a[n-1]);
}
