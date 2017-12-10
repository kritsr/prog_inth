#include<stdio.h>
char map[8][9] =
  {
    "........",
    "........",
    "........",
    "...OX...",
    "...XO...",
    "........",
    "........",
    "........"
  };
int chkVal(int i, int j, char val) {
  return i >= 0 && i < 8 && j >= 0 && j < 8 && map[i][j] == val;
}
void expand(int r, int c){
  char m = map[r][c];
  char n = m=='O'?'X':'O';
  for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      if (di == 0 && dj == 0) continue;
      int i = r+di, j = c+dj;
      while (chkVal(i, j, n)) {
        i += di; j += dj;
      }
      if (chkVal(i, j, m)) {
        while (i != r || j != c) {
          map[i][j] = m;
          i -= di; j -= dj;
        }
      }
    }
  }
}

int main(){
  int n;
  scanf("%d\n", &n);
  for (int i = 0 ;i < n; i++) {
    int r, c; char m;
    scanf(" %c %d", &m, &r);
    r--;
    c = m - 'a';
    m = (i%2)?'O':'X';
    map[r][c] = m;
    expand(r,c);
  }
  for (int i = 0; i < 8; i++) {
    printf("%s\n", map[i]);
  }
}