#include<stdio.h>
int map[9][9];
int map0[9][9];
#define OK 0b1111111110
int isOk() {
  int a, b;
  for (int i = 0; i < 9; i++) {
    a = 0; b = 0;
    for (int j = 0; j < 9; j++) {
      if (map0[i][j] != 0 && map0[i][j] != map[i][j]) return 0;
      a |= 1 << map[i][j];
      b |= 1 << map[j][i];
    }
    if (a != OK || b != OK) return 0;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a = 0;
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          a |= 1 << map[3*i+k][3*j+l];
        }
      }
      if (a != OK) return 0;
    }
  }
  return 1;
}
int main(){
  int n;
  scanf("%d\n", &n);
  for (int j = 0; j < 9; j++) {
    for (int k = 0; k < 9; k++) {
      scanf("%d", &map0[j][k]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 9; j++) {
      for (int k = 0; k < 9; k++) {
        scanf("%d", &map[j][k]);
      }
    }
    if (isOk()) printf("%d\n", i);
  }
  printf("END\n");
}