#include <bits/stdc++.h>

using namespace std;

int main(){
  long int n;
  long long int x;

  scanf("%ld %lld", &n, &x);
  long long int temp;

  long long int arr[n], c[n];
  map<long long int, int> m;
  for(long int i=0;i<n;i++){
    scanf("%lld", &temp);
    arr[i] = temp;
    c[i] = temp;
    m[temp] = i;
  }

  sort(c,c+n);
  long long int max = c[n-1];
  long long int min = c[0];
  int flag = 0;
  for(long int i=0;i<n;i++){
    long long int k = x - arr[i];
    if(k<min || k>max){
      continue;
    }
    if(binary_search(c,c+n,k) && (m[k]!=i)){
      flag = 1;
      printf("%ld %ld", i+1, m[k]+1);
      break;
    }
  }

  if(flag==0){
    printf("IMPOSSIBLE");
  }
}
