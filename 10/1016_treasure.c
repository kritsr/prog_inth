#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
  const double s2 = 1 / sqrt(2);
  int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
  int dis;
  char dir[10];
  char input[40];
  for (scanf("%s", input); input[0] != '*'; scanf("%s", input))
  {
    sscanf(input, "%d%s", &dis, dir);
    if (!strcmp("N", dir))
    {
      y1 += dis;
    }
    else if (!strcmp("E", dir))
    {
      x1 += dis;
    }
    else if (!strcmp("W", dir))
    {
      x1 -= dis;
    }
    else if (!strcmp("S", dir))
    {
      y1 -= dis;
    }
    else if (!strcmp("NE", dir))
    {
      y2 += dis;
      x2 += dis;
    }
    else if (!strcmp("SE", dir))
    {
      y2 -= dis;
      x2 += dis;
    }
    else if (!strcmp("SW", dir))
    {
      y2 -= dis;
      x2 -= dis;
    }
    else if (!strcmp("NW", dir))
    {
      y2 += dis;
      x2 -= dis;
    }
  }
  double x = (double)x1 + (double)x2 / sqrt(2);
  double y = (double)y1 + (double)y2 / sqrt(2);
  printf("%.3f %.3f\n", x, y);
  printf("%.3f\n", sqrt(x * x + y * y));
  return 0;
}