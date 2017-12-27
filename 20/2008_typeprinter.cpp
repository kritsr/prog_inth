// Use list instead of map to reduce memory
#include<iostream>
#include<forward_list>
using namespace std;
struct Trie {
  char c;
  bool eow;
  forward_list<Trie> children;
};
void printTrie(Trie t, bool isLast = true) {
  if (t.eow) cout << "P\n";
  Trie t0;
  if (isLast && !t.children.empty()) {
    t0 = t.children.front();
    t.children.pop_front();
  } else isLast = false;
  for (auto tc : t.children) {
    cout << tc.c << '\n';
    printTrie(tc, false);
    cout << "-\n";
  }
  if (isLast) {
    cout << t0.c << '\n';
    printTrie(t0);
  }
}
int main(){
  int N; cin >> N;
  Trie root = {0, false}, *t;
  string lword;
  int tn = 0;
  // Collect into Trie structure
  for (int i = 0; i < N; i++) {
    string tmp; cin >> tmp;
    if (tmp.length() > lword.length()) lword = tmp;
    t = &root;
    for (char c : tmp) {
      auto ti = t->children.before_begin();
      auto tj = t->children.begin();
      while (tj != t->children.end() && tj->c <= c) {
        ++ti; ++tj;
      }
      if (ti == t->children.before_begin() || ti->c < c){
        ++tn;
        ti = t->children.insert_after(ti, {c, false});
      }
      t = &(*ti);
    }
    t->eow = true;
  }
  // Bring longest tree to the front
  t = &root;
  for (auto c : lword) {
    auto ti = t->children.before_begin();
    auto tj = t->children.begin();
    while (tj->c != c) {
      ++ti; ++tj;
    }
    if (ti != t->children.before_begin()){
      t->children.push_front(*tj);
      t->children.erase_after(ti, ++tj);
    }
    t = &(t->children.front());
  }

  cout << tn*2-lword.length()+N << endl;
  printTrie(root);
}
