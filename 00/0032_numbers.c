#include <stdio.h>
void print(int dg,int n)
{
  while(n-- > 0)
  printf("%d",dg);
}  
int main()
{
  int n,i,num[10]={0},digit;
  scanf("%d",&n);
  for(i=0;i<n;num[digit]++,i++)
    scanf("%d",&digit);
  for(i=1;num[i]==0;i++){;}
  print(i,1);
  print(0,num[0]);
  print(i,num[i]-1);
  for(i=i+1;i<10;print(i,num[i]),i++)
  scanf(" ");
}
