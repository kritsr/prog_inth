#include <stdio.h>

int main()
{
  int input[9];
  int sum = -100;
  for (int i = 0; i < 9; i++)
  {
    scanf("%d", input+i);
    sum += input[i];
  }
  for (int i = 0; i < 8; i++)
  {
    for (int j = i + 1; j < 9; j++)
    {
      if (input[i] + input[j] == sum)
      {
        input[i] = input[j] = 0;
      }
    }
  }
  for (int i = 0; i < 9; i++)
  {
    if (input[i] != 0)
    {
      printf("%d\n", input[i]);
    }
  }
}
