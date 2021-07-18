#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
  ll n;
  scanf("%lld", &n);

  for(ll k=1;k<=n;k++){
    if(k>2){
      cout << (((k*k)*(k*k - 1))/2) - 4*(k-1)*(k-2) << "\n";
    }
    else{
      cout << ((k*k)*(k*k - 1))/2 << "\n";
    }
  }
}
