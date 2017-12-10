#include<stdio.h>
char map[5][5];
int n, m, s = 0;
int del(int i, int j, char x) {
  if (x == map[i][j]) {
    map[i][j] = '-';
    s += 5;
    del(i,j-1,x);
    del(i,j+1,x);
    if (i > 0) del(i-1,j,x);
    del(i+1,j,x);
  }
  return 1;
}
int chk(int i, int j) {
  int c = 0;
  int x = map[i][j];
  if (map[i][j] == map[i][j+1]) c=del(i,j+1,x);
  if (map[i][j] == map[i][j-1]) c=del(i,j-1,x);
  if (map[i][j] == map[i+1][j]) c=del(i+1,j,x);
  if (i > 0 && map[i][j] == map[i-1][j]) c=del(i-1,j,x);
  return c;
}
void proc() {
  int bi, con = 1;
  while (con) {
    con = 0;
    char t;
    for (int j = 1; j < m-1; j++) {
      for (int i = n-1; i >= 0; i--) {
        switch (map[i][j]) {
          case '#': bi = i-1; break;
          case '-': break;
          default: t = map[i][j];map[i][j] = '-';map[bi--][j] = t;
        }
      }
    }
    for (int i = 0; i < n-1; i++) {
      for (int j = 1; j < m-1; j++) {
        if (map[i][j] != '-' && map[i][j] != '#')
          con |= chk(i,j);
      }
    }
  }
}
int main(){
  scanf("%d %d ", &n, &m);
  char tmp[10];
  for (int i = 0; i < n; i++) {
    gets(tmp);
    for (int j = 0; j < m; j++) {
      map[i][j] = tmp[2*j];
    }
  }
  int N;
  scanf("%d ", &N);
  while (N-- > 0) {
    gets(tmp);
    int x = tmp[0]-'0',
        y = tmp[2]-'0',
        dir = (tmp[4] == 'R'?1:-1);
    // Check invalid move
    if (map[x][y] == '-' || map[x][y] == '#' || map[x][y+dir] != '-') {
      s -= 5;
      continue;
    }
    map[x][y+dir] = map[x][y];
    map[x][y] = '-';
    proc();
  }
  printf("%d\n", s);
  tmp[5] = ' ';
  tmp[2*m-1] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      tmp[j*2] = map[i][j];
    }
    printf("%s\n", tmp);
  }
}