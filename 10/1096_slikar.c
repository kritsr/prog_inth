#include <stdio.h>
int g(int m[256][256][3], int i, int j, int x) {
  if (x == 0) {
    int r = m[i][j][0] + m[i+1][j][0] + m[i][j+1][1] + m[i+1][j+1][2];
    int q = m[i][j][0] + m[i+1][j][0] + m[i][j+1][2] + m[i+1][j+1][1];
    if (q < r) r = q;
    q = m[i][j][0] + m[i+1][j][0] + m[i][j+1][2] + m[i+1][j+1][1];
    if (q < r) r = q;
    q = m[i][j][0] + m[i+1][j][1] + m[i][j+1][0] + m[i+1][j+1][2];
    if (q < r) r = q;
    q = m[i][j][0] + m[i+1][j][2] + m[i][j+1][0] + m[i+1][j+1][1];
    if (q < r) r = q;
    q = m[i][j][1] + m[i+1][j][0] + m[i][j+1][0] + m[i+1][j+1][2];
    if (q < r) r = q;
    q = m[i][j][2] + m[i+1][j][0] + m[i][j+1][0] + m[i+1][j+1][1];
    if (q < r) r = q;
    q = m[i][j][1] + m[i+1][j][0] + m[i][j+1][2] + m[i+1][j+1][0];
    if (q < r) r = q;
    q = m[i][j][2] + m[i+1][j][0] + m[i][j+1][1] + m[i+1][j+1][0];
    if (q < r) r = q;
    q = m[i][j][1] + m[i+1][j][2] + m[i][j+1][0] + m[i+1][j+1][0];
    if (q < r) r = q;
    q = m[i][j][2] + m[i+1][j][1] + m[i][j+1][0] + m[i+1][j+1][0];
    if (q < r) r = q;
    q = m[i][j][0] + m[i+1][j][1] + m[i][j+1][2] + m[i+1][j+1][0];
    if (q < r) r = q;
    q = m[i][j][0] + m[i+1][j][2] + m[i][j+1][1] + m[i+1][j+1][0];
    if (q < r) r = q;
    return r;
  } else {
    return m[i][j][x] + m[i+1][j][x] + m[i][j+1][x] + m[i+1][j+1][x];
  }
}
int main(){
  int N;
  scanf("%d", &N);
  int m[256][256][3];
  for (int i = 0; i < N; i+=2) {
    char t1[N+1], t2[N+1];
    scanf("%s", t1);
    scanf("%s", t2);
    for (int j = 0; j < N; j+=2) {
      int a = t1[j] + t2[j] + t1[j+1] + t2[j+1] - '0' * 4;
      m[i/2][j/2][0] = 0;
      if (a == 0 || a == 4) {
        m[i/2][j/2][0] = 1;
      }
      m[i/2][j/2][1] = 4-a;
      m[i/2][j/2][2] = a;
    }
  }
  N /= 2;
  while (N > 1) {
    for (int i = 0; i < N; i+=2) {
      for (int j = 0; j < N; j+=2) {
        m[i/2][j/2][0] = g(m,i,j,0);
        m[i/2][j/2][1] = g(m,i,j,1);
        m[i/2][j/2][2] = g(m,i,j,2);
      }
    }
    N /= 2;
  }
  printf("%d\n", m[0][0][0]);
}
