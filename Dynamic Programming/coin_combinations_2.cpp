#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,x;
  scanf("%d %d", &n, &x);

  int c[n];
  int min1 = INT_MAX;

  for(int i=0;i<n;i++){
    scanf("%d", &c[i]);
    min1 = min(min1, c[i]);
  }

  for(int i=1;i<min1;i++){
    arr[i] = 0;
  }
  arr[min1] = 1;

  

}
