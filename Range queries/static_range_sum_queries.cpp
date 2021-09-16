#include <bits/stdc++.h>

using namespace std;


int main(){
  long int n,q;
  scanf("%ld %ld", &n, &q);

  unsigned long long int arr[n] = {0};
  unsigned long long int temp;

  for(long int i=0;i<n;i++){
    scanf("%ulld", &temp);
    if(i==0){
      arr[i] = temp;
    }
    else{
      arr[i] = arr[i-1] + temp;
    }
  }

  long int a,b;
  for(long int i=1;i<=q;i++){
    scanf("%ld %ld", &a, &b);
    if(a==1){
      printf("%lld\n", arr[b-1]);
    }
    else{
      printf("%lld\n", arr[b-1] - arr[a-2]);
    }
  }
}
