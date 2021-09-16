#include <bits/stdc++.h>

using namespace std;

long int arr[(int)(1e6+1)] = {0};

long int min_count(long int sum, long int c[], int n){
  if(arr[sum] != 0){
    return arr[sum];
  }
  else if(sum == 0){
    return 0;
  }
  else{
    long int min2 = INT_MAX;
    long int temp;
    for(int i=0;i<n;i++){
      if((sum - c[i] >= 0)){
        temp = min_count(sum-c[i],c,n);
        if(temp != -1){
          min2 = min(min2, temp+1);
        }
      }
    }
    if(min2 == INT_MAX){
      arr[sum] = -1;
    }
    else{
      arr[sum] = min2;
    }
    return arr[sum];
  }
}

int main(){
  int n,x;
  scanf("%d %d", &n, &x);

  long int c[n];
  long int min1 = INT_MAX;
  for(int i=0;i<n;i++){
    scanf("%ld", &c[i]);
    min1 = min(min1, c[i]);
    arr[c[i]] = 1;
  }

  for(int i=1;i<min1;i++){
    arr[i] = -1;
  }

  printf("%ld", min_count(x,c,n));
}
