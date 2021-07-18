#include <bits/stdc++.h>

using namespace std;

#define ll long long int

long long power(long long x, long long y){
  ll sum = 0;
  for(ll i=1; (int)(pow(y,i)+0.5) <= x;i++){
    sum += floor(x/(int)(pow(y,i) + 0.5));
  }
  return sum;
}


int main(){
  ll n;
  scanf("%lld", &n);

  cout << power(n,5);
}
