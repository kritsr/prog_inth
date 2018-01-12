#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int N, M, C;
  cin >> N >> M;
  int ps0[M], ps1[M];
  for (int i = 0; i < M; i++) {
    cin >> ps0[i] >> ps1[i]; ++ps1[i];
  }
  sort(ps0, ps0+M);
  sort(ps1, ps1+M);
  char c;
  cin >> c;
  switch (c) {
    case 'R': C = 0;break;
    case 'G': C = 1;break;
    default : C = 2;
  }
  int i = 0, j = 0, li = 1, ans = 0;
  while (j < M) {
    if (i >= M || ps0[i] > ps1[j]) {
      ans += C * (ps1[j]-li);
      C = (C+1)%3;
      li = ps1[j++];
    } else if (ps0[i] < ps1[j]) {
      ans += C * (ps0[i]-li);
      C = (C+2)%3;
      li = ps0[i++];
    } else {++i;++j;}
  }
  ans += C * (N+1-li);
  cout << ans << endl;
}
