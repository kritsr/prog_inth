#include<iostream>
#include<algorithm>
using namespace std;
struct warp {
  int from;
  int to;
};
bool cmp (warp a, warp b) {
  return a.from < b.from;
}
int main() {
  int N, M, K;
  cin >> N >> M >> K;
  bool* r = new bool[N+1]();
  warp* w = new warp[M];
  int* b = new int[K+1];
  b[K] = N; // Add wall to the end
  for (int i = 0; i < M; i++) {
    cin >> w[i].from >> w[i].to;
  }
  sort(w, w+M, cmp);
  for (int i = 0; i < K; i++) {
    cin >> b[i];
  }
  sort(b, b+K);
  int max = 0;
  r[1] = true;
  for (int i = 1, j = 0, k = 0; i < N; i++) {
    if (r[i]) {
      // find first valid warp
      while (j < M && w[j].from < i) j++;
      // find next wall
      while (b[k] < i) k++;
      fill(r+i,r+b[k]+1,true);
      i = b[k];
      max = b[k];
      // update warp
      while (j < M && w[j].from <= i) r[w[j++].to] = true;
    }
  }
  if (r[N]) printf("1\n");
  else printf("0 %d\n", max);
  delete[] r;
  delete[] b;
  delete[] w;
}
