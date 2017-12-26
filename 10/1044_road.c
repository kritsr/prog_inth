#include <stdio.h>
#include <string.h>
#define set0(dst) memset(dst, 0, sizeof(dst))
int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  int val_n[n];
  int val_m[m];
  int inc_n[n];
  int inc_m[m];
  set0(val_n);
  set0(val_m);
  set0(inc_n);
  set0(inc_m);
  int t, sum = 0;;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      scanf("%d", &t);
      val_n[i] += t;
      val_m[j] += t;
      sum += t;
    }
  }
  for (int i = 0; i < n; i++){
    int i1 = i-1;
    int i2 = i+1;
    for (int j = 0; j < m; j++){
      int j1 = j-1;
      int j2 = j+1;
      scanf("%d", &t);
      if (i1>=0) inc_n[i1] += t;
      if (i2<n) inc_n[i2] += t;
      if (j1>=0) inc_m[j1] += t;
      if (j2<m) inc_m[j2] += t;
    }
  }
  int max = -100000;
  for (int i = 0; i < n; i++){
    int val = sum - val_n[i] + inc_n[i];
    if (val > max) max = val;
  }
  for (int i = 0; i < m; i++){
    int val = sum - val_m[i] + inc_m[i];
    if (val > max) max = val;
  }
  printf("%d\n", max);
}
