#include <bits/stdc++.h>

using namespace std;


int main(){
  int n,x;
  scanf("%d %d", &n, &x);

  long long int arr[n+1];
  arr[0] = 0;
  int temp;

  for(int i=1;i<=n;i++){
    scanf("%d", &temp);
    arr[i] = arr[i-1] + temp;
  }

  map<long long int, long long int> u;
  long long int count = 0;

  for(int i=0;i<=n;i++){
    if(u.find(arr[i]-x) != u.end()){
      count = count + u[arr[i]-x];
      u[arr[i]]++;
    }
    else{
      u[arr[i]]++;
    }
  }

  printf("%lld", count);
}
