#include <stdio.h>
#include <string.h>

int main(){
  int n, k;
  scanf("%d %d", &n, &k);
  int K = (1<<k);
  int ans[K];
  memset(ans, 0x55, sizeof(ans));
  ans[0] = 0;
  for (int i = 0; i < n; i++) {
    int p, fn = 0;
    scanf("%d", &p);
    for (int j = 0; j < k; j++) {
      int c;
      scanf("%d", &c);
      fn |= (c << j);
    }
    for (int j = 0; j < K; j++) {
      int n_fn = j | fn;
      int n_p = ans[j] + p;
      if (ans[n_fn] > n_p) ans[n_fn] = n_p;
    }
  }
  printf("%d\n", ans[K-1]);
}
