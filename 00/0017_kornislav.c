#include <stdio.h>

int main()
{
  int m1 = 100, m2 = 100, m3 = 100;
  for (int i = 0; i < 4; i++){
    int in;
    scanf("%d", &in);
    if (in <= m1){
      m3 = m2;
      m2 = m1;
      m1 = in;
    } else if (in <= m2){
      m3 = m2;
      m2 = in;
    } else if (in <= m3){
      m3 = in;
    }
  }
  printf("%d\n", m1*m3);
}