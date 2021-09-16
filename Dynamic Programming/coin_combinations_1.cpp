#include <bits/stdc++.h>

using namespace std;

long int arr[(int)(1e6+1)];

long int min_count(int sum, int c[], int n){
  if(arr[sum] != -1){
    return arr[sum];
  }
  else{
    long int sum2 = 0;
    for(int i=0;i<n;i++){
      if(sum-c[i] >= 0){
        sum2 = sum2 + min_count(sum-c[i],c,n);
      }
    }
    arr[sum] = sum2%((long int)(1e9+7));
    return arr[sum];
  }
}


int main(){
  int n,x;
  scanf("%d %d", &n, &x);

  int c[n];
  int min1 = INT_MAX;

  for(int i=0;i<((int)(1e6+1));i++){
    arr[i] = -1;
  }

  for(int i=0;i<n;i++){
    scanf("%d", &c[i]);
    min1 = min(min1, c[i]);
  }

  for(int i=0;i<min1;i++){
    arr[i] = 0;
  }

  arr[0] = 1;
  arr[min1] = 1;

  printf("%ld", min_count(x, c, n));
}
