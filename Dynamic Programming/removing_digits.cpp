#include <bits/stdc++.h>

using namespace std;

long int arr[(int)(1e6+1)];


long int min_count(int x){
  if(arr[x] != -1){
    return arr[x];
  }
  else{
    long int min2 = INT_MAX;
    int temp = x;
    while(temp>0){
      if(temp%10 !=0 ){
        min2 = min(min2, min_count(x-temp%10)+1);
      }
      temp = temp/10;
    }
    arr[x] = min2;
    return arr[x];
  }
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i=0;i<((int)(1e6+1));i++){
    arr[i] = -1;
  }

  for(int i=1;i<=9;i++){
    arr[i] = 1;
  }
  arr[0] = 0;
  arr[10] = 2;
  arr[11] = 3;

  printf("%ld", min_count(n));
}
