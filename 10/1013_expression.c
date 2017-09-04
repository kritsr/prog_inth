#include <stdio.h>
#include <string.h>

typedef struct op_t
{
  char expression[200];
  char sub_exp[65][200];
} op_t;
int op(int x, char *exp, char op, char *out);
int main()
{
  char input[200];
  scanf("%s", input);
  int N;
  scanf("%d", &N);
  for (int _i = 0; _i < N; _i++)
  {
    int x;
    char output[200] = "p";
    char tmp[200];
    char exp[200];
    strcpy(exp, input);
    for (scanf("%d", &x); x > 0; scanf("%d", &x))
    {
      sprintf(tmp, "op(%d,%s)", x, output);
      strcpy(output, tmp);
      int l = strlen(exp);
      if (l > 0)
      {
        // Precedence + * ^ ()
        int bcnt = 0; //bracket count
        // Check +
        if (op(x, exp, '+', tmp) || op(x, exp, '*', tmp) || op(x, exp, '^', tmp))
        {
          strcpy(exp, tmp);
        }
        else if (x == 1)
        {
          if (exp[0] == '(')
          {
            for (int i = 0; i < l - 2; i++)
            {
              exp[i] = exp[i + 1];
            }
            exp[l - 2] = 0;
          }
        }
        else
          exp[0] = 0;
      }
    }
    if (exp[0] == 0)
      strcpy(exp, "null");
    printf("%s=%s\n", output, exp);
  }
  return 0;
}
int op(int x, char *exp, char op, char *out)
{
  int bcnt = 0;
  int valid = 0;
  int oi = 0;
  const int l = strlen(exp);
  for (int i = 0; i < l; i++)
  {
    if (x == 1)
      out[oi++] = exp[i];
    if (exp[i] == '(')
      bcnt++;
    else if (exp[i] == ')')
      bcnt--;
    else if (!bcnt && exp[i] == op)
    {
      valid = 1;
      if (1 == x--)
        out[oi - 1] = 0;
    }
  }
  out[oi] = 0;
  return valid;
}