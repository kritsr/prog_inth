#include<stdio.h>
typedef long long ll;
ll gcd(ll a, ll b) {
  while (b > 0) {
    ll t = b;
    b = a % b;
    a = t;
  }
  return a;
}
int main(){
  ll N, cd;
  scanf("%ld", &N);
  scanf("%ld", &cd);
  for (ll i = 1; i < N; i++) {
    ll n;
    scanf("%ld", &n);
    cd = gcd(cd, n);
  }
  ll n = 1;
  ll cnt = 1;
  while (cd % 2 == 0) {
    cnt++;
    cd /= 2;
  }
  n *= cnt;
  for (ll i = 3; i <= cd; i+=2) {
    cnt = 1;
    while (cd % i == 0) {
      cnt++;
      cd /= i;
    }
    n *= cnt;
  }
  printf("%ld\n", n);
}
