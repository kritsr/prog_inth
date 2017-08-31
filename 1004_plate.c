#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
  int id;
  struct queue *next;
} queue;

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
  queue *q = malloc(sizeof(queue));
  queue
  q->next = NULL;

  char x;
  int id;
  for (scanf("%c", &x); x != 'X'; scanf("%c", &x))
  {
    switch (x)
    {
    case 'D':
      printf("discharge\n");
      break;
    case 'E':
      scanf("%d", &id);
      printf("enqueue %d\n", id);
      break;
    }
  }
  printf("0\n");
}
