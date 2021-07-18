#include <bits/stdc++.h>


using namespace std;
#define ll long long int


ll calc(ll x){
  if(x>=50){
    if(x%2==0){
      return (calc(x/2)*calc(x/2))%((long long)(1e9 + 7));
    }
    else{
      return (calc(floor(x/2))*calc(floor(x/2) + 1))%((long long)(1e9 + 7));
    }
  }
  else{
    return (long long)(pow(2,x)+0.5)%((long long)(1e9 + 7));
  }
}

int main(){
  ll n;
  scanf("%lld", &n);
  cout << calc(n);
}
