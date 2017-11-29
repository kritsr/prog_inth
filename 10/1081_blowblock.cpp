#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  int N;
  cin >> N;
  int f[N][N], n = N/2, n2 = n*n;
  int a[n2],b[n2],c[n2],d[n2];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> f[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i*n+j] = f[2*i][2*j];
      b[i*n+j] = f[2*i+1][2*j];
      c[i*n+j] = f[2*i][2*j+1];
      d[i*n+j] = f[2*i+1][2*j+1];
    }
  }
  sort(a, a+n2);
  sort(b, b+n2);
  sort(c, c+n2);
  sort(d, d+n2);
  int sum = 0;
  for (int i = 0; i < n2; i++) {
    sum += a[i]*b[i]*c[i]*d[i];
  }
  cout << sum << endl;
}
