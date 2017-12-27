// Too high memory usage (224B per node)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct Trie {
  struct Trie *children[27];
  char c26;
  bool eow;
} Trie;
Trie *newNode() {
  Trie *t = malloc(sizeof(Trie));
  t->eow = false;
  for (int i = 0; i < 27; i++) t->children[i] = NULL;
  return t;
}
void printTrie(Trie *t) {
  if (t->eow) printf("P\n");
  for (int i = 0; i < 26; i++) {
    if (t->children[i] != NULL) {
      printf("%c\n", 'a' + i);
      printTrie(t->children[i]);
      printf("-\n");
    }
  }
  if (t->children[26] != NULL) {
    printf("%c\n", t->c26);
    printTrie(t->children[26]);
  }
  free(t);
}
int main(){
  int N;
  scanf("%d", &N);
  Trie *t = newNode(), *tc;
  char lword[21], lmax = 0;
  int tn = 0;
  for (int i = 0; i < N; i++) {
    char tmp[21];
    scanf("%s", tmp);
    int l = strlen(tmp);
    if (l > lmax) {
      lmax = l;
      strcpy(lword, tmp);
    }
    tc = t;
    for (int i = 0; i < l; i++) {
      int index = tmp[i]-'a';
      if (tc->children[index] == NULL) {
        tc->children[tmp[i]-'a'] = newNode();
        tn++;
      }
      tc = tc->children[tmp[i]-'a'];
    }
    tc->eow = true;
  }
  tc = t;
  for (int i = 0; i < lmax; i++) {
    tc->c26 = lword[i];
    tc->children[26] = tc->children[lword[i]-'a'];
    tc->children[lword[i]-'a'] = NULL;
    tc = tc->children[26];
  }
  printf("%d\n", tn*2-lmax+N);
  printTrie(t);
}
