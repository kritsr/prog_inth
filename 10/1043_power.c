#include <stdio.h>
#include <math.h>

int isExpo(int, int);
int main(){
  int N;
  scanf("%d", &N);
  for (int _i = 0; _i < N; _i++){
    int _n;
    double n;
    scanf("%d", &_n);
    n = _n;
    int no = 1;
    for (double i = floor(log2(n)); i >= 2; i--){
      double x = round(pow(n, 1/i));
      if (n == pow(x, i)) {
        printf("%.0f\n", i);
        no = 0;
        break;
      }
    }
    if (no) printf("NO\n");
  }
  return 0;
}
