#include <bits/stdc++.h>

using namespace std;


int main(){
  long long int  n;
  scanf("%lld", &n);

  long long int m = (long long int)(1e9+7);
  long long int count = 0;

  for(long long int i=1;i<=floor(sqrt(n));i++){
    if(n/i == i){
      count = count + (i*i)%m;
    }
    else{
      count = count + (2*(n/i)*i)%m;
    }
  }

  printf("%lld", count%m);
}
