#include <bits/stdc++.h>

using namespace std;

long int arr[(int)(1e6+1)] = {0};


long int count(long int n){

  if(n <= 0){
    return 0;
  }
  if(arr[n] != 0){
    return arr[n];
  }
  else{
    arr[n] = (count(n-1) + count(n-2) + count(n-3) + count(n-4) + count(n-5) + count(n-6))%((long long int)(1e9 + 7));
    return arr[n];
  }
}

int main(){
  int n;
  scanf("%d", &n);
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 4;
  arr[4] = 8;
  arr[5] = 16;
  arr[6] = 32;

  printf("%lld", count(n));
}
