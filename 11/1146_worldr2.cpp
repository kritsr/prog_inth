#include<iostream>
#include<algorithm>
using namespace std;
struct place {
  string server;
  string town;
};
bool cmp (place a, place b) {
  return (a.server < b.server || (a.server == b.server && a.town < b.town));
}
bool isRoot(place p) {
  if (p.server == "Delta") return p.town == "Eternal_City_Mac_Anu";
  if (p.server == "Omega") return p.town == "Warring_City_Lumina_Cloth";
  if (p.server == "Theta") return p.town == "Celestial_City_Dol_Dona";
  if (p.server == "Sigma") return p.town == "Dual_City_Breg_Epona";
}
int main(){
  int N, P, Q;
  cin >> N >> P >> Q;
  Q *= 2;
  place plist[N];
  for (int i = 0; i < N; i++)
    cin >> plist[i].server >> plist[i].town;
  sort(plist, plist+N, cmp);
  place c = plist[0];
  int ans = 0;
  if (!isRoot(c)) ans = Q;
  for (int i = 1; i < N; i++) {
    if (c.server != plist[i].server) {
      ans += P;
      c.town = "";
    }
    if (c.town != plist[i].town && !isRoot(plist[i]))
      ans += Q;
    c = plist[i];
  }
  cout << ans << endl;
}
