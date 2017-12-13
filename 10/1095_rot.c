#include<stdio.h>
int diff(int a, int b) {
  return a>b?a-b:b-a;
}
int min(int a, int b) {
  return a<b?a:b;
}
int max(int a, int b) {
  return a>b?a:b;
}
int main() {
  int R, C, K;
  scanf("%d %d", &R, &C);
  char map[R][C+1];
  for (int i = 0; i < R; i++) {
    scanf("%s", map[i]);
  }
  scanf("%d", &K);
  K %= 360;
  if (K%90 == 0) {
    switch(K/90) {
      case 0:
        for (int i = 0; i < R; i++) {
          for (int j = 0; j < C; j++) {
            printf("%c", map[i][j]);
          }
          printf("\n");
        }
        break;
      case 1:
        for (int j = 0; j < C; j++) {
          for (int i = R-1; i >= 0; i--) {
            printf("%c", map[i][j]);
          }
          printf("\n");
        }
        break;
      case 2:
        for (int i = R-1; i >= 0; i--) {
          for (int j = C-1; j >= 0; j--) {
            printf("%c", map[i][j]);
          }
          printf("\n");
        }
        break;
      default:
        for (int j = C-1; j >= 0; j--) {
          for (int i = 0; i < R; i++) {
            printf("%c", map[i][j]);
          }
          printf("\n");
        }
        break;
    }
  } else {
    switch(K/90) {
      case 0:
        for (int i = 0, n = R + C - 1; i < n; i++) {
          for (int ns = diff(R - 1, i), i = 0; i < ns; i++) printf(" ");
          int x = min(R-1, i), y = i-x;
          printf("%c", map[x--][y++]);
          for (; x >= 0 && y < C; x--,y++) {
            printf(" %c", map[x][y]);
          }
          printf("\n");
        }
        break;
      case 1:
        for (int i = 0, n = R + C - 1; i < n; i++) {
          for (int ns = diff(C - 1, i), i = 0; i < ns; i++) printf(" ");
          int x = min(R-1, R+C-2-i), y = min(C-1, i);
          // printf("%d %d: %d %d", R-1, R+C-2-i);
          printf("%c", map[x--][y--]);
          for (; x >= 0 && y >= 0; x--,y--) {
            printf(" %c", map[x][y]);
          }
          printf("\n");
        }
        break;
      case 2:
        for (int i = 0, n = R + C - 1; i < n; i++) {
          for (int ns = diff(R - 1, i), i = 0; i < ns; i++) printf(" ");
          int x = max(0, R-1-i), y = R+C-2-i-x;
          printf("%c", map[x++][y--]);
          for (; x < R && y >= 0; x++,y--) {
            printf(" %c", map[x][y]);
          }
          printf("\n");
        }
        break;
      default:
        for (int i = 0, n = R + C - 1; i < n; i++) {
          for (int ns = diff(C - 1, i), i = 0; i < ns; i++) printf(" ");
          int x = max(i-C+1, 0), y = max(C-1-i, 0);
          printf("%c", map[x++][y++]);
          for (; x < R && y < C; x++,y++) {
            printf(" %c", map[x][y]);
          }
          printf("\n");
        }
        break;
    }
  }
}
