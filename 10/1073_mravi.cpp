#include <iostream>
#include <algorithm>
using namespace std;
int calX(int x, int L) {
  x %= 2*L;
  if (x < 0) {
    x = -x;
  }
  if (x > L) {
    x = 2*L - x;
  }
  return x;
}
void sort(int[], int);
int main() {
  int L, T, N;
  cin >> L >> T >> N;
  int m[N];
  for (int i = 0; i < N; i++) {
    int a; char b;
    cin >> a >> b;
    if (b == 'L') {
      a -= T;
    } else {
      a += T;
    }
    m[i] = calX(a, L);
  }
  sort(m, m+N);
  for (int i = 0; i < N; i++) {
    cout << m[i] << ' ';
  }
  return 0;
}