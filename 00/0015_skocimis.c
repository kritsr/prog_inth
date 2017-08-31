#include <stdio.h>
#define MAX(a,b) (a)>(b)?(a):(b)
int main(){
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  printf("%d\n", MAX(b-a,c-b)-1);
}