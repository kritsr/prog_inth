#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int N;
  cin >> N;
  int sticks[N];
  for (int i = 0; i < N; i++) {
    cin >> sticks[i];
  }
  int ans=0;
  if (N >= 3) {
    int i=0, j=2;
    sort(sticks, sticks+N);
    while (j < N) {
      int a = sticks[i] + sticks[i+1];
      while (j < N && sticks[j] < a) j++;
      int n = j-i;
      if (n >= 3 && n > ans) ans = n;
      while (i < N-1 && sticks[j] >= sticks[i] + sticks[i+1]) i++;
    }
  }
  cout << ans << endl;
  return 0;
}
