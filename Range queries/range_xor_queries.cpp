#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,q;
  scanf("%d %d", &n, &q);

  long long int arr[n];
  int temp;

  for(int i=0;i<n;i++){
    scanf("%d", &temp);
    if(i==0){
      arr[i] = temp;
    }
    else{
      arr[i] = arr[i-1]^temp;
    }
  }

  int a,b;
  for(int i=1;i<=q;i++){
    scanf("%d %d", &a, &b);
    if(a==1){
      printf("%lld\n", arr[b-1]);
    }
    else{
      printf("%lld\n", arr[b-1]^arr[a-2]);
    }
  }
}
