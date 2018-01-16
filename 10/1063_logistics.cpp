#include<iostream>
#include<iomanip>
#include<algorithm>
struct Route {
  char from;
  char to;
  double cost;
};
struct Station {
  char id;
  Station *t1;
  Station *t2;
};
using namespace std;
int main(){
  int N, rn = 0; cin >> N;
  Route rs[N], rst[26];
  Station sts[28];
  for (int i = 0; i < 26; i++) {
    sts[i] = {(char)('a'+i), NULL, NULL};
  }
  sts[26] = {'X', NULL, NULL};
  sts[27] = {'Y', NULL, NULL};
  for (int i = 0; i < N; i++) {
    char f, t;
    double c;
    cin >> f >> t >> c;
    rs[i] = {f, t, c};
    if (f < 'a') f = 26 + f - 'X';
    else f -= 'a';
    if (t < 'a') t = 26 + t - 'X';
    else t -= 'a';
    if (sts[f].t1 == NULL || sts[f].t1 == sts+t) sts[f].t1 = sts+t;
    else sts[f].t2 = sts+t;
    if (sts[t].t1 == NULL || sts[t].t1 == sts+f) sts[t].t1 = sts+f;
    else sts[t].t2 = sts+f;
  }
  Station *pst = NULL;
  Station *cst = sts+26;
  while (cst != NULL && cst->id != 'Y') {
    if (cst->t1 != pst) cst = (pst=cst)->t1;
    else cst = (pst=cst)->t2;
    if (cst == NULL) break;
    double cs[300], c;
    int cn = 0;
    for (int i = 0; i < N; i++) {
      if ((rs[i].from == pst->id && rs[i].to == cst->id) ||
          (rs[i].from == cst->id && rs[i].to == pst->id)) {
        cs[cn++] = rs[i].cost;
      }
    }
    sort(cs, cs+cn);
    if (cn % 2 == 1) c = cs[cn/2];
    else c = (cs[cn/2] + cs[cn/2 - 1]) / 2;
    rst[rn++] = {pst->id, cst->id, c};
  }
  double sum = 0;
  if (cst != NULL) {
    cout << fixed << setprecision(1);
    for (int i = 0; i < rn; i++) {
      cout << rst[i].from << ' ' << rst[i].to << ' ' << rst[i].cost << endl;
      sum += rst[i].cost;
    }
    cout << sum << endl;
  } else {
    cout << "broken" << endl;
  }
}
