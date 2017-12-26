#include <ctype.h>
#include <string.h>
#include <stdio.h>

int isPalindrome(char *in, int l)
{
  for (int i = 0; i < l / 2; i++)
  {
    if (in[i] != in[l - 1 - i])
      return 0;
  }
  return 1;
}

int main()
{
  char input[201];
  scanf("%s", input);
  int l = strlen(input);
  for (int i = 0; i < l; i++)
  {
    input[i] = tolower(input[i]);
  }
  if (isPalindrome(input, l))
  {
    if (isPalindrome(input, l / 2))
    {
      printf("Double Palindrome\n");
    }
    else
      printf("Palindrome\n");
  }
  else
    printf("No\n");
}
