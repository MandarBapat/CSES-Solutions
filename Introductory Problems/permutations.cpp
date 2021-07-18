#include <bits/stdc++.h>

using namespace std;

int main(){
  long int n;
  scanf("%ld", &n);

  if((n==2) || (n==3)){
    printf("NO SOLUTION");
  }

  else{
    if(n%2==0){
      for(long int i=(n-1);i>=1;i=i-2){
        printf("%ld ", i);
      }

      for(long int i=n;i>=2;i=i-2){
        printf("%ld ", i);
      }
    }

    else{
      for(long int i=n;i>=1;i=i-2){
        printf("%ld ", i);
      }

      for(long int i=n-1;i>=2;i=i-2){
        printf("%ld ", i);
      }
    }
  }
}
