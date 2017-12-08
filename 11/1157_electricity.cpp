#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  int p[N];
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }
  deque<int> q;
  for (int i = 1; i <= K; i++) {
    p[i] += p[0];
    while (!q.empty() && q.back() > p[i]) q.pop_back();
    q.push_back(p[i]);
  }
  for (int i = K+1, j = 1; i < N; i++, j++) {
    p[i] += q.front();
    if (q.front() == p[j]) q.pop_front();
    while (!q.empty() && q.back() > p[i]) q.pop_back();
    q.push_back(p[i]);
  }
  cout << p[N-1] << endl;
}
