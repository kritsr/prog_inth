#include<stdio.h>
int map[17][17], n;
int tchk(int i, int j, int c) {
  return (i >= 0 && i < n && j >= 0 && j < n && map[i][j] == c);
}
int chk(int i, int j) {
  int c, cnt1 = 0, cnt2 = 0;
  c = map[i+(map[i][j] != map[i][j+1])][j];
  if (c == 0) return 0;
  if (map[i][j] == c) {
    cnt1++;
    cnt2 += tchk(i-1,j,c) + tchk(i,j-1,c) + 1;
  }
  if (map[i+1][j] == c) {
    cnt1++;
    cnt2 += tchk(i+2,j,c) + tchk(i+1,j-1,c) + 1;
  }
  if (map[i][j+1] == c) {
    cnt1++;
    cnt2 += tchk(i-1,j+1,c) + tchk(i,j+2,c) + 1;
  }
  if (map[i+1][j+1] == c) {
    cnt1++;
    cnt2 += tchk(i+2,j+1,c) + tchk(i+1,j+2,c) + 1;
  }
  return cnt1 == 3 && cnt2 == 3;
}
int main(){
  int a = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &map[i][j]);
  for (int i = 0; i < n-1; i++)
    for (int j = 0; j < n-1; j++)
      a += chk(i, j);
  printf("%d\n", a);
}