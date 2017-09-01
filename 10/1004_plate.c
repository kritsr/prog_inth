#include <stdio.h>
#include <stdlib.h>

// allocated memory is not freed properly
typedef struct studentQueue
{
  int id;
  struct studentQueue *next;
} studentQueue;

typedef struct classQueue
{
  int id;
  struct classQueue *next;
  studentQueue *studentQ;
} classQueue;

int main()
{
  int Nc, Ns;
  scanf("%d %d\n", &Nc, &Ns);
  short class[10001];
  for (int i = 0; i < Ns; i++)
  {
    int c, s;
    scanf("%d %d", &c, &s);
    class[s] = c;
  }
  classQueue *classQ = malloc(sizeof(classQueue));
  classQ->studentQ = malloc(sizeof(studentQueue));
  classQ->next = NULL;

  char cmd;
  int id;
  for (scanf("%c", &cmd); cmd != 'X'; scanf("%c", &cmd))
  {
    switch (cmd)
    {
    case 'D':
      // printf("discharge: ");
      if (NULL == classQ->next)
        printf("empty\n");
      else
      {
        studentQueue *sq = classQ->next->studentQ, *t = sq->next;
        printf("%d\n", t->id);
        sq->next = t->next;
        if (t->next == NULL){
          //clear class queue
          classQueue *t2 = classQ->next;
          classQ->next = t2->next;
          free(t2->studentQ);
          free(t2);
        }
        free(t);
      }
      break;
    case 'E':
      scanf("%d", &id);
      // printf("enqueue %d from class %d\n", id, class[id]);
      classQueue *pq = classQ, *nq = classQ->next;
      while (1)
      {
        if (nq == NULL)
        {
          nq = malloc(sizeof(classQueue));
          nq->id = class[id];
          nq->next = NULL;
          pq->next = nq;
          nq->studentQ = malloc(sizeof(studentQueue));
          nq->studentQ->next = malloc(sizeof(studentQueue));
          nq->studentQ->next->next = NULL;
          nq->studentQ->next->id = id;
          break;
        }
        else if (nq->id == class[id])
        {
          studentQueue *sq = nq->studentQ->next;
          while (1)
          {
            if (sq->next == NULL)
            {
              sq->next = malloc(sizeof(studentQueue));
              sq->next->id = id;
              sq->next->next = NULL;
              break;
            }
            sq = sq->next;
          }
          break;
        }
        pq = nq;
        nq = pq->next;
      }
      break;
    }
  }
  printf("0\n");
  //TODO: Clear allocated memory
}
