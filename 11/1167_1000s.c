#include<stdio.h>
int min(int a, int b){return a<b?a:b;}
int max(int a, int b){return a>b?a:b;}
int abs(int a){return a>0?a:-a;}
int main(){
  int n, N = 0, E = 0, W = 0, S = 0;
  while(1) {
    char c;
    scanf("%c", &c);
    if (c == 'N') N++;
    else if (c == 'E') E++;
    else if (c == 'W') W++;
    else if (c == 'S') S++;
    else break;
  }
  int pos = max(N, S) + max(E, W);
  int neg = min(N, S) + min(E, W);
  scanf("%d", &n);
  int x = abs(pos - abs(neg - n));
  int y = abs(neg - abs(pos - n));
  printf("%d\n", 2*max(x,y));
}
