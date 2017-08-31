#include <stdio.h>
#include <string.h>

void printline(int n, int i);
#define MIN(a,b) ((a)<(b)?(a):(b))
int main()
{
  int h;
  scanf("%d", &h);
  int w = h & 1 ? h : h - 1;
  for (int i = 0; i < h; i++)
  {
    printline(w, MIN(i, h-i-1));
  }
}

void printline(int w, int i)
{
  int loc1 = w / 2 + i;
  int loc2 = w / 2 - i;
  for (int i = 0; i < w; i++)
  {
    if (i == loc1 || i == loc2)
      printf("*");
    else
      printf("-");
  }
  printf("\n");
}
