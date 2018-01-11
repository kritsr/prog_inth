#include<stdio.h>
char grid[1000][1001];
int mapv[1000][1000], maph[1000][1000], N, M;
int main(){
  int Q;
  scanf("%d", &Q);
  while (--Q >= 0) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
      scanf("%s", grid[i]);
    }
    int max = 0, k, l, x;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (grid[i][j] == '1') {
          k = j;
          while (++k < M && grid[i][k] == '1');--k;
          l = (k+j)/2;
          x = j;
          while (j <= l) {
            maph[i][j] = k - j;
            j++;
          }
          while (j <= k) {
            maph[i][j] = j - x;
            j++;
          }
        } else {
          maph[i][j] = 0;
        }
      }
    }
    for (int j = 0; j < M; j++) {
      for (int i = 0; i < N; i++) {
        if (grid[i][j] == '1') {
          k = i;
          while (++k < N && grid[k][j] == '1');--k;
          l = (k+i)/2;
          x = i;
          while (i <= l) {
            mapv[i][j] = k - i;
            i++;
          }
          while (i <= k) {
            mapv[i][j] = i - x;
            i++;
          }
        } else {
          mapv[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        x = mapv[i][j] + maph[i][j];
        if (x > max) max = x;
      }
    }
    printf("%d\n", max+1);
  }
}
