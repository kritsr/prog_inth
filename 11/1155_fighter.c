#include<stdio.h>
int main(){
  int hp[2];
  scanf("%d", &hp);
  hp[1] = hp[0];
  int p, cnt, t = 2;
  while(1){
    scanf("%d", &p);
    if (t != p%2) {
      cnt = 1;
      t = p%2;
    } else cnt++;
    if (cnt >= 3) hp[1-t] -= 3;
    else hp[1-t]--;
    if (hp[1-t] <= 0) break;
  }
  printf("%d\n%d\n", t, p);
}
