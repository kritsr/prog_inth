#include <iostream>
#include <algorithm>
using namespace std;
struct worm {
  unsigned long long d;
  unsigned long long c;
};
bool cmp (worm a, worm b) {
  return a.c < b.c;
}
int main() {
  int N;
  cin >> N;
  worm worms[N];
  for (int i = 0; i < N; i++)
    cin >> worms[i].d >> worms[i].c;
  sort(worms, worms+N, cmp);
  double ratio = 0, r;
  unsigned long long mcost = 0, mdata = 0,
    cost = worms[0].c, data = worms[0].d;
  for (int i = 1; i < N; i++) {
    if (worms[i].c != cost) {
      r = (double)data/cost;
      if (r > ratio) {
        ratio = r;;
        mcost = cost;
        mdata = data;
      }
    }
    data += worms[i].d;
    cost = worms[i].c;
  }
  r = (double)data/cost;
  if (r > ratio) {
    mcost = cost;
    mdata = data;
  }
  cout << mdata << ' ' << mcost << endl;
}
