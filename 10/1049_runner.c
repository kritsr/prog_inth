#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct runner{
  int number;
  int speed;
  struct runner *next;
}runner;
typedef struct lane{
  runner *first;
  runner *last;
}lane;
int main(){
  int N, M, L;
  scanf("%d %d", &N, &M);
  lane lanes[M];
  memset(lanes, 0, sizeof(lanes));
  for (int i = 0; i < N; i++){
    runner *r = malloc(sizeof(runner));
    scanf("%d %d %d", &(r->number), &L, &(r->speed));
    L--;
    if (lanes[L].first == NULL) {
      lanes[L].first = lanes[L].last = r;
    }
    else {
      lanes[L].last->next = r;
      lanes[L].last = r;
    }
  }
  while (1){
    int max = 0, num;
    for (int i = 0; i < M; i++){
      if (lanes[i].first != NULL){
        runner *r = lanes[i].first;
        lanes[i].first = r->next;
        if (max < r->speed){
          max = r->speed;
          num = r->number;
        }
        free(r);
      }
    }
    if (max > 0) printf("%d\n", num);
    else break;
  }
}
