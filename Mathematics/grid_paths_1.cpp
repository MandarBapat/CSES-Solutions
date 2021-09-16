#include <bits/stdc++.h>

using namespace std;

void mult(int n, int m, int k){
  
}

int arr[100][100];

int main(){
  int n,m,k;
  scanf("%d %d %d", &n, &m, &k);

  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      arr[i][j] = 0;
    }
  }

  for(int i=1;i<=m;i++){
    int a,b;
    scanf("%d %d", &a, &b);
    arr[a-1][b-1] = 1;
  }

  mult(n,m,k);

  printf("%d", arr[i][j]);
}
