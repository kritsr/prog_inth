#include<stdio.h>
int main(){
  int nA, nB, nX;
  scanf("%d %d", &nA, &nB);
  int A[nA], B[nB], *X, min, max;
  long long sumA = 0, sumB = 0, sumX;
  for (int i = 0; i < nA; i++) {
    scanf("%d", A+i);
    sumA += A[i];
  }
  for (int i = 0; i < nB; i++) {
    scanf("%d", B+i);
    sumB += B[i];
  }
  min = (sumA)/nA;
  max = (sumB+nB-1)/nB;
  if (max < min) {
    X = A; nX = nA;
    sumX = sumA;
    min = (sumB)/nB;
    max = (sumA+nA-1)/nA;
  } else {
    X = B; nX = nB;
    sumX = sumB;
  }
  int i = 0, n = nX;
  while (i < nX && X[i] <= min) i++;
  while (i < nX && X[i] < max) {
    --n;
    sumX -= X[i];
    max = (sumX+n-1)/n;
    ++i;
  }
  printf("%d\n", nX-n);
}
