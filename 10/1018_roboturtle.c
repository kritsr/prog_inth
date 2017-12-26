#include <stdio.h>

int main()
{
  const char dir_n[5] = "ENWS";
  int N;
  scanf("%d", &N);
  int x = 0, y = 0, d = 0;
  char dir[3];
  int dis;
  for (int i = 0; i < N; i++)
  {
    scanf("%s %d", dir, &dis);
    switch (dir[0])
    {
    case 'L':
      d = (d + 1) % 4;
      break;
    case 'R':
      d = (d + 3) % 4;
      break;
    case 'B':
      d = (d + 2) % 4;
      break;
    }
    switch (d)
    {
    case 0:
      x += dis;
      break;
    case 1:
      y += dis;
      break;
    case 2:
      x -= dis;
      break;
    case 3:
      y -= dis;
      break;
    }
    if (x >= 50000 || y >= 50000 || x <= -50000 || y <= -50000)
    {
      printf("DEAD\n");
      return 0;
    }
  }
  printf("%d %d\n%c\n", x, y, dir_n[d]);
}
