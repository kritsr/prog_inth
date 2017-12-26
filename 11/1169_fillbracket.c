#include<stdio.h>
int main(){
  int n = 0, st = 0;
  while(1) {
    char c; scanf("%c", &c);
    if (c == '(') ++st;
    else if (c == ')')
      if (st > 0) --st;
      else ++n;
    else break;
  }
  printf("%d\n", st+n);
}
