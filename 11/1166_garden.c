#include<stdio.h>
char garden[30][31];
int n, m;
int count(int i, int j) {
  if (garden[i][j] != '.') return 0;
  int cnt = 1;
  garden[i][j] = '@';
  if (i > 0) cnt += count(i-1, j);
  if (j > 0) cnt += count(i, j-1);
  if (i < n-1) cnt += count(i+1, j);
  if (j < m-1) cnt += count(i, j+1);
  return cnt;
}
int main(){
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", garden+i);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (garden[i][j] == '#') {
        if (i > 0 && garden[i-1][j] != '#') garden[i-1][j] = '!';
        if (j > 0 && garden[i][j-1] != '#') garden[i][j-1] = '!';
        if (i < n-1 && garden[i+1][j] != '#') garden[i+1][j] = '!';
        if (j < m-1 && garden[i][j+1] != '#') garden[i][j+1] = '!';
      }
    }
  }
  int max = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (garden[i][j] == '.') {
        int cnt = count(i, j);
        if (cnt > max) max = cnt;
      }
    }
  }
  printf("%d\n", max);
}
