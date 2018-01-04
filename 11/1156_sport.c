#include<stdio.h>
#include<string.h>
char buf[200];
void p(int w, int l, int i) {
  if (w == 0 || l == 0) printf("%.*s\n", i-1, buf);
  else {
    if (w > 0) {
      buf[i] = 'W';
      p(w-1, l, i+2);
    }
    if (l > 0) {
      buf[i] = 'L';
      p(w, l-1, i+2);
    }
  }
}

int main(){
  int k, a, b;
  scanf("%d %d %d", &k, &a, &b);
  memset(buf, ' ', 200);
  p(k-a, k-b, 0);
}
