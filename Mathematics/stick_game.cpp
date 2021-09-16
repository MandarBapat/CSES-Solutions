#include <bits/stdc++.h>

using namespace std;

int arr[(int)(1e6+1)];

int wl(int n, int p[], int k){
  if(arr[n] != -1){
    return arr[n];
  }
  else{
    bool var2 = true;
    for(int i=0;i<k;i++){
      if(n-p[i] > 0){
        var2 = var2 && (bool)(wl(n-p[i],p,k));
      }
    }

    if(var2 == true){
      arr[n] = 0;
      return arr[n];
    }
    else{
      arr[n] = 1;
      return arr[n];
    }
  }
}


int main(){
  int n,k;
  scanf("%d %d", &n, &k);

  for(int i=0;i<((int)(1e6+1)); i++){
    arr[i] = -1;
  }

  int p[k];
  for(int i=0;i<k;i++){
    scanf("%d", &p[i]);
    arr[p[i]] = 1;
  }

  for(int i=1;i<=n;i++){
    if(wl(i, p, k)){
      printf("W");
    }
    else{
      printf("L");
    }
  }
}
