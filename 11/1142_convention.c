// Interval tree
#include<stdio.h>
#include<stdlib.h>
typedef struct Interval {
  int low, high;
} Interval;
typedef struct ITNode {
  Interval *i;
  int max;
  struct ITNode *left, *right;
} ITNode;
ITNode * newNode(Interval i) {
  ITNode *t = malloc(sizeof(ITNode));
  t->i = malloc
}
int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    // if(solve(a, b)) printf("yes\n");
    // else printf("no\n");
  }
}
