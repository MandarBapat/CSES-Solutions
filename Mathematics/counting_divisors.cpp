#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);

  for(int j=1;j<=n;j++){
    int x;
    scanf("%d", &x);

      int count  = 0;

      for(int i=1;i<=floor(sqrt(x));i++){
        if(x%i == 0 && x/i != i){
          count +=2;
        }
        else if(x%i == 0 && x/i == i){
          count++;
        }
      }
      printf("%d\n", count);
  }
}
