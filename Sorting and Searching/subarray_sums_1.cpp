#include <bits/stdc++.h>

using namespace std;

int main(){
  long int n;
  long long int x;

  scanf("%ld %lld", &n, &x);

  long long int arr[n];

  for(int i=0;i<n;i++){
    scanf("%lld", &arr[i]);
  }

  long long int count = 0;
  long long int sum = arr[0];
  long int i,j;
  i=0;
  j=0;
  while(i<n && j<n){
    if(sum<x){
      j++;
      sum = sum + arr[j];
    }
    else if(sum > x){
      sum = sum - arr[i];
      i++;
    }
    else{
      count++;
      sum = sum -arr[i];
      i++;
      j++;
      sum = sum + arr[j];
    }
  }

  printf("%lld", count);
}
