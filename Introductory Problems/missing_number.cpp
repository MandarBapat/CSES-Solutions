#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  int arr[n+1];
  int temp;

  for(int i=0;i<n+1;i++){
    arr[i]=0;
  }

  for(int i=1;i<=(n-1);i++){
    scanf("%d", &temp);
    arr[temp] = 1;
}

  for(int i=1;i<n+1;i++){
    if(arr[i]==0){
      printf("%d",i);
    }
  }
}
