#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m,k;
  scanf("%d %d %d", &n, &m, &k);

  int a[n];
  int b[m];

  for(int i=0;i<n;i++){
    scanf("%d", &a[i]);
  }

  for(int i=0;i<m;i++){
    scanf("%d", &b[i]);
  }

  sort(a,a+n);
  sort(b,b+m);

  int i=0;
  int j =0;
  int count = 0;

  while(j<m){
    if(b[j] <= (a[i]+k) && b[j] >= (a[i]-k)){
      count++;
      i++;
      j++;
    }
    else if(b[j] < (a[i]-k)){
      j++;
    }
    else if(b[j] > (a[i] + k)){
      i++;
    }
  }

  printf("%d", count);
}
