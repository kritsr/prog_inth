#include <stdio.h>
#include <string.h>
#define FORN(i, N) for (int i = 0; i < (N); i++)
int main()
{
  int N;
  scanf("%d", &N);
  char moveset[1001];
  FORN(i, N)
  {
    unsigned char dice[6] = {1, 2, 3, 5, 4, 6};
    scanf("%s", moveset);
    const int l = strlen(moveset);
    int t;
    FORN(j, l)
    {
      switch (moveset[j])
      {
      case 'F':
        t = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[1];
        dice[1] = t;
        break;
      case 'B':
        t = dice[3];
        dice[3] = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = t;
        break;
      case 'L':
        t = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[2];
        dice[2] = t;
        break;
      case 'R':
        t = dice[4];
        dice[4] = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = t;
        break;
      case 'C':
        t = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[3];
        dice[3] = dice[2];
        dice[2] = t;
        break;
      case 'D':
        t = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[3];
        dice[3] = t;
        break;
      }
    }
    printf("%d ", dice[1]);
  }
  return 0;
}
