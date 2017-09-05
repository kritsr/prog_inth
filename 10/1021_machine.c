#include <stdio.h>
#define CHILD_L_i(i) (2 * (i) + 1)
#define CHILD_R_i(i) (2 * (i) + 2)
#define PARENT_i(i) (((i)-1) / 2)
#define SWAP(a, b) \
  a ^= b;          \
  b ^= a;          \
  a ^= b;
int heap[300000];
int heap_n = 0;
int tmp;
void insert(int val);
int extract();
int main()
{
  int N;
  scanf("%d", &N);
  char cmd[3];
  int val;
  for (int i = 0; i < N; i++)
  {
    scanf("%s", &cmd);
    if (cmd[0] == 'P')
    {
      scanf("%d", &val);
      insert(val);
    }
    else if (cmd[0] == 'Q')
    {
      printf("%d\n", extract());
    }
    else{
      break;
    }
  }
  return 0;
}
void insert(int val)
{
  int i = heap_n++;
  heap[i] = val;
  for (int pi = PARENT_i(i); heap[i] > heap[pi]; pi = PARENT_i(i))
  {
    SWAP(heap[i], heap[pi]);
    i = pi;
  }
}
int extract()
{
  if (0 == heap_n)
    return -1;
  int result = heap[0];
  heap[0] = heap[--heap_n];
  int i = 0;
  while (1)
  {
    int li = CHILD_L_i(i);
    if (li >= heap_n) break;
    int ri = CHILD_R_i(i);
    if (ri >= heap_n) ri = li;
    int ci = heap[li] > heap[ri] ? li : ri;
    if (heap[i] < heap[ci])
    {
      SWAP(heap[i], heap[ci]);
      i = ci;
    }
    else
    {
      break;
    }
  }
  return result;
}