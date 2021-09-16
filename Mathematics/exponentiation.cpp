#include <bits/stdc++.h>

using namespace std;

long long int exp(int a, int b){
  long long int p = 1;
  long long int m = (long long int)(1e9+7);
  long long int x = a;
  long long int y = b;

  x = x%m;
  if(x == 0){
    return 0;
  }
  else{
    while(y>0){
      if(y&1){
        p = (p * x)%m;
      }
      y = y>>1;
      x = (x*x)%m;
    }
    return p;
  }
}


int main(){
  int n;
  scanf("%d", &n);

  for(int i=1;i<=n;i++){
    int a,b;
    scanf("%d %d", &a, &b);

    if(b==0){
      printf("%d\n",1);
    }
    else if(a==0){
      printf("%d\n",0);
    }
    else{
      printf("%lld\n", exp(a,b));
    }
  }
}
