#include <stdio.h>

int main(){
  int a[5];
  for (int i = 0; i < 5; i++)
    scanf("%d", a+i);
  for (int n = 0; n < 5; n++)
    for (int i = 0; i < 4; i++)
      if (a[i] > a[i+1]) {
        int t = a[i+1];
        a[i+1] = a[i];
        a[i] = t;
        printf("%d %d %d %d %d\n", a[0],a[1],a[2],a[3],a[4]);
      }
}
