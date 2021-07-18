#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,x;
  scanf("%d %d", &n, &x);

  int p[n];

  for(int i=0;i<n;i++){
    scanf("%d", &p[i]);
  }

  sort(p,p+n);

  int i=0;
  int j=(n-1);
  int count = 0;

  while(i <= j){
    if(p[i] + p[j] <= x){
      i++;
      j--;
      count++;
    }
    else{
      count++;
      j--;
    }
  }

  printf("%d", count);
}
