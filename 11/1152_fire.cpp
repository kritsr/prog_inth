#include<iostream>
#include<algorithm>
using namespace std;
struct item {int val;int time;};
bool cmp (const item& a, const item& b) {
  return a.val > b.val;
}
int main(){
  // ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int N2 = N*N, NT = 2*N-1;
  item xs[N2];
  int ans[NT];
  for (int i = 0; i < NT; i++) ans[i] = 0;
  for (int i = 0, k = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> xs[k].val;
      xs[k++].time = i+j;
    }
  }
  sort(xs, xs+N2, cmp);
  int s = 0;
  for (int n = NT-1, i = 0; n > 0; i++) {
    int j = xs[i].time;
    while (ans[j] > 0 && j > 0) j--;
    if (j > 0) {
      ans[j] = xs[i].val;
      s += xs[i].val;
      --n;
    }
  }
  printf("%d\n", s);
}
