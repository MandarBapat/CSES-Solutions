#include <bits/stdc++.h>

using namespace std;

int v[(int)(1e6)];

void fill_sub(vector<int> arr[], int n, int i){
  if(arr[i].size() == 0){
    v[i] = 0;
    return;
  }
  else{
    int sum = 0;
    for(auto c : arr[i]){
      if(v[c] == -1){
        fill_sub(arr,n,c);
      }
      sum = sum + v[c];
    }
    v[i] = sum + arr[i].size();
  }
}

int main(){
  int n;
  scanf("%d", &n);

  vector<int> arr[n+1];
  int temp;

  for(int i=2;i<=n;i++){
    scanf("%d", &temp);
    arr[temp].push_back(i);
  }

  for(int i=0;i<(int)(1e6);i++){
    v[i] = -1;
  }

  fill_sub(arr,n,1);

  for(int i=1;i<=n;i++){
    printf("%d ",v[i]);
  }
}
