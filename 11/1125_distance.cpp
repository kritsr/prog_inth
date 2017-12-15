#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  int N;
  cin >> N;
  int a[N], b[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }
  sort(a, a+N);
  sort(b, b+N);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    int t = i - (N-1-i);
    ans += ((long long)a[i] + b[i]) * t;
  }
  cout << ans << endl;
}
