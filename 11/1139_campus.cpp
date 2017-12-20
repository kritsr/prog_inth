#include<iostream>
#include<algorithm>
using namespace std;
struct dorm {
  int x;
  int n;
};
bool compare (dorm a, dorm b) {
  return a.x < b.x;
}
long long diff(int a, int b) {
  return a>b?a-b:b-a;
}
int main(){
  // Normal cin is too slow
  ios::sync_with_stdio(false);
  int N, i;
  cin >> N;
  dorm dormX[N], dormY[N];
  long long median = 0, n;
  for (int i = 0; i < N; i++) {
    cin >> dormX[i].x >> dormY[i].x >> dormX[i].n;
    median += (dormY[i].n = dormX[i].n);
  }
  //Find median
  median = (median + 1) / 2;
  sort(dormX, dormX+N, compare);
  sort(dormY, dormY+N, compare);
  n = 0; i = -1;
  while (n < median) {
    n += dormX[++i].n;
  }
  int X = dormX[i].x;
  n = 0; i = -1;
  while (n < median) {
    n += dormY[++i].n;
  }
  int Y = dormY[i].x;
  //End median
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum += diff(X, dormX[i].x)*dormX[i].n + diff(Y, dormY[i].x)*dormY[i].n;
  }
  cout << sum << endl;
}
