#include <stdio.h>
#include <string.h>

int find_len(char *s1, char *s2)
{
  int len = 0;
  while (*s1 == *s2 && *s1 != 0 && *s2 != 0)
  {
    len++;
    s1++;
    s2++;
  }
  return len;
}

int main()
{
  char in1[200], in2[200];
  scanf("%s", in1);
  scanf("%s", in2);
  int L1 = strlen(in1);
  int L2 = strlen(in2);
  int max_len = 0;
  int max_index = 0;
  for (int i = 0; i < L1; i++)
  {
    for (int j = 0; j < L2; j++)
    {
      int len = find_len(in1 + i, in2 + j);
      if (len > max_len)
      {
        max_index = i;
        max_len = len;
      }
    }
  }
  in1[max_index + max_len] = 0;
  printf("%s\n", in1 + max_index);
  return 0;
}