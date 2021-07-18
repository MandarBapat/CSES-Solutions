#include <bits/stdc++.h>

using namespace std;

#define ll long long int


int main(){
  int t;
  scanf("%d", &t);

  for(int i=1;i<=t;i++){
    ll a,b;

    scanf("%lld %lld", &a, &b);

    if(((a+b)%3==0) && (2*a >=b && 2*b >= a)){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
}
