#include<iostream>
#include<algorithm>
using namespace std;
int N;
char map[1000][1000];
struct cell{int r;int c;int p;};
bool compare(cell a, cell b) {
  return a.p < b.p;
}
void spread(int r, int c, int v) {
  if (r >= 0 && r < N && c >= 0 && c < N && map[r][c] == 0) {
    map[r][c] = v;
    spread(r-1, c, v);
    spread(r+1, c, v);
    spread(r, c-1, v);
    spread(r, c+1, v);
  }
}
int main() {
  cin >> N;
  int N2 = N*N;
  cell cs[N2];
  fill(&map[0][0], &map[0][0] + sizeof(map), -1);
  for (int i = 0, k = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cs[k] = {i, j, 0};
      cin >> cs[k].p;
      ++k;
    }
  }
  sort(cs, cs+N2, compare);
  map[cs[0].r][cs[0].c] = 1;
  map[cs[1].r][cs[1].c] = 2;
  for (int i = 2; i < N2; i++) {
    bool h1 = false, h2 = false;
#define r cs[i].r
#define c cs[i].c
#define p cs[i].p
    map[r][c] = 0;
    if (r > 0 && map[r-1][c] > 0) {
      switch (map[r-1][c]) {
        case 2: h2 = true;break;
        case 1: h1 = true;break;
      }
    }
    if (c > 0 && map[r][c-1] > 0) {
      switch (map[r][c-1]) {
        case 2: h2 = true;break;
        case 1: h1 = true;break;
      }
    }
    if (r < N-1 && map[r+1][c] > 0) {
      switch (map[r+1][c]) {
        case 2: h2 = true;break;
        case 1: h1 = true;break;
      }
    }
    if (c < N-1 && map[r][c+1] > 0) {
      switch (map[r][c+1]) {
        case 2: h2 = true;break;
        case 1: h1 = true;break;
      }
    }
    if (h1 && h2) {
      cout << p << endl;
      break;
    } else if (h1) {
      spread(r, c, 1);
    } else if (h2) {
      spread(r, c, 2);
    } else {
      map[r][c] = 0;
    }
#undef r
#undef c
#undef p
  }
}
