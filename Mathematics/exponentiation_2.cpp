#include <bits/stdc++.h>

using namespace std;

int exp2(int a, int b){
  long long int x = a;
  long long int y = b;
  long long int m = (long long int)(1e9+6);
  long long int p = 1;

  x = x%m;
  if(x == 0){
    return 0;
  }
  else{
    while(y > 0){
      if(y&1){
        p = (p*x)%m;
      }
      y = y >> 1;
      x = (x*x)%m;
    }
    return p;
  }
}


int exp1(int a, int b, int c){
  long long int x = a;
  long long int y = b;
  long long int z = c;
  long long int m = (long long int)(1e9+7);

    long long int r = exp2(b,c);
    if(r == 0){
      return 1;
    }
    else{
      long long int p = 1;
      while(r>0){
        if(r&1){
          p = (p*x)%m;
        }
        r = r >> 1;
        x = (x*x)%m;
      }
      return p;
    }
}


int main(){
  int n;
  scanf("%d", &n);

  for(int i=1;i<=n;i++){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    if(b==0 && c==0){
      printf("%d\n",a);
    }
    else if(a==0 && b ==0){
      printf("%d\n",1);
    }
    else{
      printf("%d\n", exp1(a,b,c));
    }
  }
}
