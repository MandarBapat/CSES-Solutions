#include <bits/stdc++.h>

using namespace std;

int main(){
  long int n;
  scanf("%ld", &n);

  long long int arr[n];

  for(long int i=0;i<n;i++){
    scanf("%lld", &arr[i]);
  }

  sort(arr,arr+n);
  long long int median;
  if(n%2==0){
    median = arr[(n/2)-1];
  }
  else{
    median = arr[(n+1)/2 - 1];
  }

  long long int cost = 0;

  for(long int i=0;i<n;i++){
    cost = cost + abs(arr[i]-median);
  }

  printf("%lld", cost);
}
