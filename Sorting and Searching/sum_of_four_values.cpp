#include <bits/stdc++.h>

using namespace std;


int main(){
  int n;
  long long int x;

  scanf("%d %lld", &n, &x);

  long long int arr[n], c[n];
  long long int temp;
  unordered_map<long long int, int> m;

  for(int i=0;i<n;i++){
    scanf("%lld", &temp);
    arr[i] = temp;
    c[i] = temp;
    m[temp] = i;
  }

  sort(c, c+n);
  long long int max = c[n-1];
  long long int min = c[0];

  int flag = 0;

  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int k=j+1;k<n;k++){
        long long int key = x - arr[i] - arr[j] - arr[k];
        if(key>max || key<min){
          continue;
        }
        else if(binary_search(c,c+n, key) && (m[key]!=i) && (m[key]!=j) && (m[key]!=k)){
          flag=1;
          printf("%d %d %d %d", i+1, j+1, k+1, m[key]+1);
          break;
        }
      }
      if(flag){
        break;
      }
    }
    if(flag){
      break;
    }
  }

  if(flag==0){
    printf("IMPOSSIBLE");
  }
}
