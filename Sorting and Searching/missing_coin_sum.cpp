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

  int flag = 0;
  long long int max = 0;
  if(arr[0]!=1){
    flag = 1;
    printf("%lld",1);
  }
  else{
    set<long long int> set1;
    set1.insert(1);

    for(long int i=1;i<n;i++){
      long long int temp = *(set1.rbegin());
      temp++;
      if(arr[i] <= temp){
        set1.insert(temp-1 + arr[i]);
        max = *(set1.rbegin());
      }
      else{
        flag = 1;
        printf("%lld",temp);
        break;
      }
    }
  }

  if(flag==0){
    printf("%lld", max+1);
  }

}
