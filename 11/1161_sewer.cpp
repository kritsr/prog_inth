#include<iostream>
#include<list>
using namespace std;
struct pos{int x; int y;};
bool operator!=(const pos& a, const pos& b) {
  return a.x != b.x || a.y != b.y;
}
struct npos{pos p; pos prev;};
int ts[100][100];
char m0[100][100];
int n, m;
bool isValid(pos a) {
  return a.x >= 0 && a.x < m && a.y >= 0 && a.y < n;
}
bool isCon(pos a, pos b) {
  if (isValid(a) && isValid(b)) {
    int x = a.x < b.x ? a.x : b.x;
    int y = a.y < b.y ? a.y : b.y;
    return (m0[y][x] == 'B') || m0[y][x] == (a.x == b.x?'D':'R');
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ts[i][j] = 0;
      cin >> m0[i][j];
    }
  }
  list<npos> l = {{{0, 0}, {0, 0}}};
  ts[0][0] = 1;
  pos a = {-1,-1};
  bool found = false;
  while (!found) {
    npos np = l.front();
    pos p = np.p;
    l.pop_front();
    pos cs[4] = {{p.x-1, p.y},{p.x, p.y-1},
                {p.x+1, p.y},{p.x, p.y+1}};
    for (int i = 0; i < 4; i++) {
      if (cs[i] != np.prev && isCon(cs[i], p)) {
        if (ts[cs[i].y][cs[i].x] == 0) {
          ts[cs[i].y][cs[i].x] = ts[p.y][p.x] + 1;
          l.push_back({cs[i], p});
        } else {
          found = true;
          a = cs[i];
          break;
        }
      }
    }
  }
  cout << ts[a.y][a.x] << endl;
  cout << a.y+1 << ' ' << a.x+1 << endl;
}
