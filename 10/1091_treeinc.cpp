#include<iostream>
#include<algorithm>

using namespace std;
struct road {
  int from;
  int to;
};
bool cmp (road a, road b) {
  return a.from < b.from;
}
int main()
{
  int N;
  cin >> N;
  road rs[N];
  int cities[N];
  fill_n(cities, N, 1);
  for (int i = 0; i < N; i++)
  {
    int u, v;
    cin >> u >> v;
    if (u > v) {
      rs[i].from = v;
      rs[i].to = u;
    } else {
      rs[i].from = u;
      rs[i].to = v;
    }
  }
  sort(rs, rs+N, cmp);
  int m = 1;
  for (int i = 0; i < N; i++)
  {
    int a = cities[rs[i].from] + 1;
    if (cities[rs[i].to] < a){
      cities[rs[i].to] = a;
    }
    if (a > m) m = a;
  }
  printf("%d\n", m);
}
