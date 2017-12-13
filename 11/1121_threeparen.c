#include<stdio.h>
int main() {
  char stack[50000];
  char in[100001];
  int si = 0, N;
  scanf("%d", &N);
  for (int x = 0; x < N; x++) {
    scanf("%s", in);
    si = -1;
    int i = 0;
    for (; in[i] != 0; i++) {
      if (in[i] == '(' || in[i] == '[' || in[i] == '{') {
        if (++si >= 50000) break;
        else stack[si] = in[i]+(in[i] == '('?1:2);
      } else if (si >= 0 && in[i] == stack[si]) --si;
      else break;
    }
    if (in[i] == 0 && si == -1) printf("yes\n");
    else printf("no\n");
  }
}
