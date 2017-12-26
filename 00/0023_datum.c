#include <stdio.h>
int main()
{
  const char dayName[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  const int daymonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
  int day, mon;
  scanf("%d %d", &day, &mon);
  int result = 3;
  for (int i = 0; i < mon - 1; i++)
  {
    result += daymonth[i];
  }
  result += day;
  result %= 7;
  printf("%s\n", dayName[result]);
}
