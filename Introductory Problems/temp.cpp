#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);

  int temp = n;
  while(true){
    if((n&(n>>1)) == 0){
      printf("%d", n);
      break;
    }
    n++;
  }
}
