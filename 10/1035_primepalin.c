#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int nextPalindrome (int in)
{
  char buf[10];
  char can[10];
  sprintf(buf, "%d", in);
  int l = strlen(buf);
  strcpy(can, buf);
  int trail = l / 2;
  for (int i = 0; i < trail; i++){
    can[l-1-i] = can[i];
  }
  if (strcmp(can, buf) >= 0) return atoi(can);
  can[l - trail] = 0;
  int i = atoi(can);
  i++;
  sprintf(can, "%d", i);
  l = strlen(can) + trail;
  for (int i = 0; i < trail; i++) {
    can[l-1-i] = can[i];
  }
  can[l+trail] = 0;
  return atoi(can);
}

int isPrime(int n){
  if (2 == n) return 1;
  if (!(n & 1)) return 0;
  int k = (int)sqrt((double)n);
  for (int i = 3; i <= k; i+=2){
    if (0 == n % i) return 0;
  }
  return 1;
}

int main(){
  int in;
  scanf("%d\n", &in);
  while (!isPrime(in = nextPalindrome(in))) in++;
  printf("%d\n", in);
  return 0;
}