#include<iostream>
#include<queue>
using namespace std;
int main(){
  int N, M, Q, ans = 0;
  cin >> N >> M;
  Q = 2 * M;
  priority_queue<int, vector<int>, greater<int>> gs;
  queue<int> cq;
  int ps[N], cs[M];
  for (int i = 0; i < N; i++) {
    cin >> ps[i];
    gs.push(i);
  }
  for (int i = 0; i < M; i++) cin >> cs[i];
  for (int i = 0; i < Q; i++) {
    int c; cin >> c;
    if (c > 0) {
      cq.push(--c);
    } else {
      c = -c-1;
      gs.push(cs[c]);
    }
    if (!cq.empty() && !gs.empty()) {
      int g = gs.top();
      c = cq.front();
      ans += ps[g] * cs[c];
      cs[c] = g;
      gs.pop();
      cq.pop();
    }
  }
  cout << ans << endl;
}
