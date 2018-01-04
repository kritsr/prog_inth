#include<stdio.h>
#include<string.h>
typedef struct mountain {
  int x;
  int h;
} mountain;
int main(){
  int N, H = 0, L = 0;
  scanf("%d", &N);
  mountain ms[N];
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &ms[i].x, &ms[i].h);
    ms[i].x--;
    if (ms[i].h > H) H = ms[i].h;
    int l = ms[i].x + ms[i].h*2;
    if (l > L) L = l;
  }
  char map[H][L];
  memset(map, '.', H*L);
  for (int i = 0; i < N; i++) {
    for (int h = 0; h < ms[i].h; h++) {
      int l = ms[i].x + h
      int r = ms[i].x + 2*ms[i].h - h - 1;
      if (map[h][l] == '.') map[h][l] = '/';
      else if (map[h][l] == '\\') map[h][l] = 'v';
      if (map[h][r] == '.') map[h][r] = '\\';
      else if (map[h][r] == '/') map[h][r] = 'v';
      for (int j = l+1; j < r; j++) map[h][j] = 'X';
    }
  }
  for (int i = H-1; i >= 0; i--) {
    printf("%.*s\n", L, map[i]);
  }
}
