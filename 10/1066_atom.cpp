#include<iostream>
#include<list>
using namespace std;
#define diff(a,b) ((a)>(b)?(a)-(b):(b)-(a))

int main(){
  list<int> alist;
  int N, t, p, m, n, en = 0;
  cin >> N >> p;
  alist.push_back(p);
  for (int i = 1; i < N; i++) {
    cin >> t;
    int d = diff(p, t);
    if (d > m) {
      m = d;
      n = 1;
    } else if (d == m) n++;
    p = t;
    alist.push_back(p);
  }
  while (alist.size() > 1) {
    list<int>::iterator it1 = alist.begin();
    list<int>::iterator it2 = next(it1);
    int nn=0, nm=0;
    while (it1 != alist.end() && it2 != alist.end()) {
      int d = diff(*it1, *it2);
      // cout << "chk " << *it1 << ' ' << *it2 << endl;
      if (d == m) {
        while (d >= m) {
          // cout << "del " << *it1 << ' ' << *it2 << endl;
          it2++;
          alist.erase(it1,it2);
          en += d;
          if (it2 == alist.begin() || alist.size() <= 1) {
            it1 = it2;
            it2 = next(it1);
            d = 0;
            break;
          } else if (it2 == alist.end()) break;
          it1 = prev(it2);
          d = diff(*it1, *it2);
        }
        n--;
      } else {
        it1++;
        it2++;
      }
      if (d > nm) {
        nm = d;
        nn = 1;
      } else if (d == nm) nn++;
    }
    n = nn;
    m = nm;
    // cout << "nm " << n << ' ' << m << endl;
  }
  cout << en << endl;
}
