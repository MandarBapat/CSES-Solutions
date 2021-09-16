#include <bits/stdc++.h>

using namespace std;


int main(){
  long long int n;
  int k;
  scanf("%lld %d", &n, &k);

  long long int arr[k];
  for(int i=0;i<k;i++){
    scanf("%lld", &arr[i]);
  }

  long long int sum = 0;
  for(int i=1;i<(1<<k);i++){
    int count;
    count = __builtin_popcount(i);
    long long int tmp = n;

    for(int j=0;j<k;j++){
      if((1<<j)&i){
        tmp  = tmp/arr[j];
      }
    }
    if(count&1){
      sum = sum + tmp;
    }
    else{
      sum = sum - tmp;
    }
  }

  printf("%lld", sum);
}
