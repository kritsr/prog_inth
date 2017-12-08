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
  deque<int> q
  for (int i = 1; i <= K; i++) {
    p[i] += p[0];
  }
  sort
  for (int i = K+1; i < N; i++) {
    int min = p[i-K];
    for (int j = i-K+1; j < i; j++) {
      if (min > p[j]) min = p[j];
    }
    p[i] += min;
  }
  cout << p[N-1] << endl;
}
