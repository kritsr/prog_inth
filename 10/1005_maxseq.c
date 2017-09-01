#include <stdio.h>
int main()
{
  int N;
  scanf("%d", &N);
  int input[N];
  int max = 0, maxFromIndex = 0, maxToIndex = 0;
  int sum = 0, sumFromIndex = 0;
  for (int i = 0; i < N; i++)
  {
    scanf("%d", input + i);
    
    if (sum < 0 && input[i] > 0)
    {
      sum = input[i];
      sumFromIndex = i;
    } else {
      sum += input[i];
    }
    if (sum > max)
    {
      max = sum;
      maxFromIndex = sumFromIndex;
      maxToIndex = i;
    }
  }
  if (max > 0)
  {
    for (int i = maxFromIndex; i < maxToIndex; i++)
    {
      printf("%d ", input[i]);
    }
    printf("%d\n%d\n", input[maxToIndex], max);
  }
  else
  {
    printf("Empty sequence\n");
  }

  return 0;
}