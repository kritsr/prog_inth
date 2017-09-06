#include <stdio.h>
#include <string.h>

int main()
{
  char op, var1, var2;
  int mem['Z' + 1], val;
  memset(mem, 0, sizeof(mem));
  scanf("%c", &op);
  while (op != '!')
  {
    switch (op)
    {
    case '=':
      scanf(" %c %d\n", &var1, &val);
      mem[var1] = val;
      break;
    case '#':
      scanf(" %c\n", &var1);
      printf("%d\n", mem[var1]);
      break;
    default:
      scanf(" %c %c\n", &var1, &var2);
      switch (op)
      {
      case '+':
        mem[var1] += mem[var2];
        break;
      case '-':
        mem[var1] -= mem[var2];
        break;
      case '*':
        mem[var1] *= mem[var2];
        break;
      case '/':
        mem[var1] /= mem[var2];
      }
    }
    scanf("%c", &op);
  }
  printf("!\n");
}