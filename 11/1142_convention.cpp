// Interval tree
#include<iostream>
#include<algorithm>
using namespace std;
struct Interval {
  int low, high;
};
struct ITNode {
  Interval i;
  Interval ri;
  ITNode *left, *right;
};
Interval insert (ITNode *root, ITNode *n) {
  Interval i = n->ri;
  if (n->i.low < root->i.low) {
    if (root->left == NULL) root->left = n;
    else i = insert(root->left, n);
  } else {
    if (root->right == NULL) root->right = n;
    else i = insert(root->right, n);
  }
  if (i.high > root->ri.high) root->ri.high = i.high;
  if (i.low < root->ri.low) root->ri.low = i.low;
  return i;
}
int start[100000];
int si = 0;
int end_a[100000];
int ei = 0;
void prepOverlap(ITNode *n, Interval i) {
  if (n->left != NULL && n->left->ri.high >= i.low)
    prepOverlap(n->left, i);
  if (i.low <= n->i.high && n->i.low <= i.high) {
    start[si++] = n->i.low;
    end_a[ei++] = n->i.high;
  }
  if (n->right != NULL && n->right->ri.low <= i.high)
    prepOverlap(n->right, i);
}
int check(int K){
  sort(end_a, end_a+ei);
  int i = 0, j = 0, k = 0;
  while (k < K && i < si && j < ei) {
    if (start[i] <= end_a[j]) {
      k++; i++;
    } else if (end_a[j] < start[i]) {
      k--; j++;
    }
  }
  return k < K;
}
int main() {
  int N, K;
  ios::sync_with_stdio(false);
  cin >> N >> K;
  ITNode root[N];
  printf("yes\n");
  for (int i = 0; i < N; i++) {
    cin >> root[i].i.low >> root[i].i.high;
    root[i].ri.high = root[i].i.high;
    root[i].ri.low = root[i].i.low;
    root[i].left = root[i].right = NULL;
    if (i > 0) {
      si = ei = 0;
      prepOverlap(root, root[i].i);
      if (check(K)) {
        printf("yes\n");
        insert(root, root+i);
      } else {
        printf("no\n");
      }
    }
  }
}
