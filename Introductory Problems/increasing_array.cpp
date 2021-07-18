#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%d\n", &n);

  long long int arr[n];

  for(int i=0;i<n;i++){
    scanf("%lld", &arr[i]);
  }

  long long moves = 0;
  long long int max = arr[0];

  for(int i=1;i<n;i++){
    if(arr[i]<=max){
      moves += (max-arr[i]);
    }
    else{
      max = arr[i];
    }
  }

  printf("%lld", moves);
}
