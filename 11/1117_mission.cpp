#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int N;
  cin >> N;
  int xs[N];
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    xs[i] = b - 2*a;
  }
  sort(xs, xs+N);
  int y = -1, i = 0;
  long long e = 0;
  while (xs[i] <= y && i < N) {
    e += y;
    y -= 2;
    i++;
  }
  while (i < N) e += xs[i++];
  cout << e << endl;
}
