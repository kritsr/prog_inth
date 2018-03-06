#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  int xss[N][N], *xs;
  xs = (int*)xss;
  fill(xs, xs+N*N, 0);
  for (int i = 0, L = 2*N+1; i < L; i++) {
    int x = i / 2, t;
    for (int j = 0, L = N + i%2; j < L; j++) {
      cin >> t;
      if (i%2) {
        t *= 5;
        if (j < N) xss[x][j] += t;
        if (j > 0) xss[x][j-1] -= t;
      } else {
        t *= 3;
        if (x < N) xss[x][j] += t;
        if (x > 0) xss[x-1][j] -= t;
      }
    }
  }
  sort(xs, xs+N*N);
  int s = 0;
  for (int i = 0; i < K; i++) {
    s += xs[i];
  }
  cout << s << endl;
}
