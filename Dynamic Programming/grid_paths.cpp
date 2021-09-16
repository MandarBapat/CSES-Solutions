#include <bits/stdc++.h>

using namespace std;

long int arr[1000][1000];


long int count(int n, int p, int q){
  if((arr[p][q] != -1)){
    return arr[p][q];
  }
  else{
    if(p == (n-1) && q < (n-1)){
      arr[p][q] = count(p,q+1);
      return arr[p][q];
    }
    else if(p < (n-1) && q==(n-1)){
      arr[p][q] = count(p+1,q);
      return arr[p][q];
    }
    else{
      
    }
  }
}


int main(){
  int n;
  scanf("%d", &n);
  string s;
  for(int i=0;i<n;i++){
    cin >> s;
    for(int j=0;j<n;j++){
      if(s[j] == '.'){
        arr[i][j] = -1;
      }
      else{
        arr[i][j] = 0;
      }
    }
  }

  arr[n-1][n-1] = 0;
  if(arr[n-1][n-2] != 0){
    arr[n-1][n-2] = 1;
  }
  if(arr[n-2][n-1] != 0){
    arr[n-2][n-1] = 1;
  }

  printf("%ld", count(n, 0, 0));
}
