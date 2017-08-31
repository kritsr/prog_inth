#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 0 i = 1
// 1 v = 5
// 2 x = 10
// 3 l = 50
// 4 c = 100

int main()
{
  int N;
  scanf("%d", &N);
  int r[5] = {0};
  for (int n = 1; n <= N; n++){
    int a = n/100;
    int b = (n%100)/10;
    int c = (n%10);
    //x00
    r[4] += a;
    //x0
    r[4] += (b == 9);
    r[3] += ((4 <= b) && (b <= 8));
    b %= 5;
    (b==4) && r[2]++;
    (b<=3) && (r[2] += b);
    //x
    r[2] += (c == 9);
    r[1] += ((4 <= c) && (c <= 8));
    c %= 5;
    (c==4) && r[0]++;
    (c<=3) && (r[0] += c);
  }
  printf("%d %d %d %d %d\n", r[0], r[1], r[2], r[3], r[4]);
  return 0;
}