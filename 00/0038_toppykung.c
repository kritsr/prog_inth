#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct text
{
  char text[31];
  struct text *next;
};

int main()
{
  int N;
  scanf("%d\n", &N);
  struct text *s = malloc(sizeof(struct text));
  s->next = NULL;
  struct text *n;
  struct text *f, *p;
  for (int i = 0; i < N; i++)
  {
    n = malloc(sizeof(struct text));
    gets(n->text);
    f = s->next;
    p = s;
    while (f != NULL) //-1 go next, 0 end, 1 settle
    {
      int r = strcmp(f->text, n->text);
      if (r == 0)
      {
        free(n);
        break;
      }
      else if (r < 0)
      {
        p = f;
        f = f->next;
      }
      else
      {
        n->next = f;
        p->next = n;
        break;
      }
    }
    if (f == NULL)
    {
      n->next = p->next;
      p->next = n;
    }
  }
  f = s->next;
  free(s);
  while (f != NULL)
  {
    printf("%s\n", f->text);
    s = f;
    f = f->next;
    free(s);
  }
}
