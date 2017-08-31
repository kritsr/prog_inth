#include <stdio.h>
#include <string.h>

int main()
{
  char in[101];
  gets(in);
  int l = strlen(in);
  char out[101];
  int j = 0;
  for (int i = 0; i < l; i++)
  {
    out[j++] = in[i];
    if (in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u')
      i += 2;
  }
  out[j] = 0;
  printf("%s\n", out);
}