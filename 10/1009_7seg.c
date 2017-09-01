#include <stdio.h>
#include <string.h>
#define MAX(a, b) (a > b ? a : b)
unsigned int getNum(char map[3][40], int N)
{
  unsigned int n = 0, m;
  for (int i = 0; i < N; i++)
  {
    int j = 4 * i;
    // printf("%c%c%c\n", map[0][j+0], map[0][j+1], map[0][j+2]);
    // printf("%c%c%c\n", map[1][j+0], map[1][j+1], map[1][j+2]);
    // printf("%c%c%c\n", map[2][j+0], map[2][j+1], map[2][j+2]);
    if (map[2][j + 2] != '|')
    {
      m = 2;
    }
    else if (map[0][j + 1] != '_')
    { // 1,4
      m = map[1][j + 0] != '|' ? 1 : 4;
    }
    else if (map[1][j + 2] != '|')
    { // 5,6
      m = map[2][j + 0] != '|' ? 5 : 6;
    }
    else if (map[2][j + 1] != '_')
    {
      m = 7;
    }
    else if (map[1][j + 0] != '|')
    {
      m = 3;
    }
    else if (map[1][j + 1] != '_')
    {
      m = 0;
    }
    else if (map[2][j + 0] != '|')
    {
      m = 9;
    }
    else
    {
      m = 8;
    }
    // printf("%d\n", m);
    n = 10 * n + m;
  }
  return n;
}
int main()
{
  int N, M;
  char buf[3][40];
  scanf("%d %d", &N, &M);
  getchar();
  memset(buf, 0, 120);
  gets(buf[0]);
  gets(buf[1]);
  gets(buf[2]);
  unsigned int a = getNum(buf, N);
  memset(buf, 0, 120);
  gets(buf[0]);
  gets(buf[1]);
  gets(buf[2]);
  unsigned int b = getNum(buf, M);
  printf("%u\n", a + b);
}