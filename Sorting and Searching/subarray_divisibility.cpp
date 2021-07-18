#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);

  int temp;
  long long int arr[n+1];
  map<long long int, long long int> m;
  long long int count = 0;
  arr[0] = 0;
  for(int i=1;i<=n;i++){
    scanf("%d", &temp);
    arr[i] = arr[i-1] + temp;
    m[(arr[i]%n+n)%n]++;
    if(arr[i]%n == 0){
      count++;
    }
  }

  for(int i=0;i<n;i++){
    if(m.find(i) != m.end()){
      count = count + (m[i]*(m[i]-1))/2;
    }
  }

  printf("%lld", count);
}
