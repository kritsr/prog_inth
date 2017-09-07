#include <stdio.h>
#include <string.h>

int c_cnt['Z' + 1];
int check(){
  for (int i = 'A'; i <= 'Z'; i++){
    if (c_cnt[i]) return 0;
  }
  for (int i = 'a'; i <= 'z'; i++){
    if (c_cnt[i]) return 0;
  }
  return 1;
}
int main()
{
  int g, s, i = 0;
  scanf("%d %d\n", &g, &s);
  char c;
  for (int i = 0; i < g; i++)
  {
    c = getchar();
    c_cnt[c]--;
  }
  if (13 == getchar()) getchar();
  char queue[g];
  memset(queue, 0, sizeof(queue));
  int ans = 0;
  for (int _i = 0; _i < s; _i++)
  {
    c_cnt[queue[i]]--;
    queue[i] = getchar();
    c_cnt[queue[i]]++;
    if (++i >= g){
      i = 0;
    }
    if (check()) ans++;
  }
  printf("%d\n", ans);
}

