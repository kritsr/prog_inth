#include <stdio.h>
char A(int i)
{
  return 'A' + (i % 3);
}
char B(int i)
{
  if (i & 1)
  {
    return 'A' + ((i >> 1 & 1) << 1);
  }
  else
  {
    return 'B';
  }
}
char C(int i)
{
  i = ((i >> 1) + 2) % 3;
  return 'A' + i;
}
int main()
{
  int na, nb, nc, N;
  scanf("%d\n", &N);
  na = nb = nc = 0;
  char a, b, c, t;
  for (int i = 0; i < N; i++){
    scanf("%c", &t);
    (t == A(i)) && na++;
    (t == B(i)) && nb++;
    (t == C(i)) && nc++;
  }
  int m = 0;
  m = na>nb?na:nb;
  m = m>nc?m:nc;
  printf("%d\n", m);
  (na == m) && printf("Adrian\n");
  (nb == m) && printf("Bruno\n");
  (nc == m) && printf("Goran\n");
  return 0;
}