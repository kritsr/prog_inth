#include <stdio.h>
#include <stdlib.h>

int cmp(int n, char *s1, char *s2)
{
  int cnt = 0;
  for (int i = 0; i < n && cnt <= 2; i++)
  {
    cnt += (s1[i] != s2[i]);
  }
  return cnt <= 2;
}

int main()
{
  int L, N;
  scanf("%d %d", &L, &N);
  char *s1, *s2, *t;
  s1 = malloc((L + 1) * sizeof(char));
  s2 = malloc((L + 1) * sizeof(char));
  scanf("%s", s1);
  for (int i = 0; i < N - 1; i++)
  {
    scanf("%s", s2);
    if (!cmp(L, s1, s2))
      break;
    t = s1;
    s1 = s2;
    s2 = t;
  }
  printf("%s\n", s1);
  free(s1);
  free(s2);
}
