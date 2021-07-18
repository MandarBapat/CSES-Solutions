#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%d",&n);

  int arr[n];
  int c[n];

  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }

  int i =0;

  while(i<n){
    if(i==0){
      c[i] = 0;
    }
    else if(arr[i-1] < arr[i]){
      c[i] = i;
    }
    else if(arr[i-1] > arr[i]){
      int j = i-1;
      c[i] = -1;
      while(j>=0 && c[i]!=0){
        c[i] = c[j];
        if(arr[c[i]-1] >= arr[i]){
          j = c[j]-1;
          continue;
        }
        else{
          break;
        }
      }
    }
    else if(arr[i-1] == arr[i]){
      c[i] = c[i-1];
    }
  i++;
 }

 for(int i=0;i<n;i++){
   printf("%d ",c[i]);
 }
}
