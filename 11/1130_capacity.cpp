#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int N;
  cin >> N;
  int xs[N], n, st = 1, sum = 0;
  for (int i = 2; i < N-1; i++) st=(st*i)%49999;
  n = -((st*(N-1))%49999);
  st *= 2;
  for (int i = 0; i < N; i++) cin >> xs[i];
  sort(xs, xs+N);
  for (int i = 0; i < N; i++, n=(n+st)%49999) {
    sum = (sum + (long long)(xs[i]%49999)*n)%49999;
  }
  cout << sum << endl;
}
