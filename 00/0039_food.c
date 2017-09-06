#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b) {a^=b;b^=a;a^=b;}

int print(char begin, char *a, int n)
{
  printf("%d", begin);
  for (int i = 0; i < n; i++)
  {
    printf(" %d", *a++);
  }
  printf("\n");
}
void reverse(char str[], int l, int h)
{
  while (l < h)
  {
    SWAP(str[l], str[h]);
    l++;
    h--;
  }
}
void printPermutations(char begin, char *arr, int n)
{
  int isFinished = 0;
  int i = 0;
  while (i >= 0)
  {
    print(begin, arr, n);
    for (i = n - 2; i >= 0; i--)
    {
      if (arr[i] < arr[i + 1])
        break;
    }
    if (i >= 0)
    {
      int j, min = 99;
      for (int k = i + 1; k < n; k++)
      {
        if (arr[k] > arr[i] && arr[k] < min)
        {
          j = k;
          min = arr[k];
        }
      }
      SWAP(arr[i], arr[j]);
      reverse(arr, i + 1, n - 1);
    }
  }
}

int main()
{
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  char ng[m];
  char ok[n - 1];
  for (int i = 0; i < m; i++)
  {
    scanf("%d", ng + i);
  }
  for (int begin = 1; begin <= n; begin++)
  {
    int nogo = 0;
    for (int i = 0; i < m; i++)
    {
      if (begin == ng[i])
      {
        nogo = 1;
        break;
      }
    }
    if (!nogo)
    {
      for (int i = 1, k = 0; i <= n; i++)
      {
        if (i != begin)
        {
          ok[k++] = i;
        }
      }
      printPermutations(begin, ok, n - 1);
    }
  }
  return 0;
}