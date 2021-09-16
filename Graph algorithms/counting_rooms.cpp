#include <bits/stdc++.h>

using namespace std;

int visited[1000][1000];
int arr[1000][1000];

void flood_fill(int n, int m, int i, int j){
  if((i>=n) || (j>=m) || (i<0) || (j<0) || (visited[i][j])){
    return;
  }
  else if(arr[i][j] == 0){
    visited[i][j] = 1;
    return;
  }
  else{
    visited[i][j] = 1;
    flood_fill(n, m, i, j-1);
    flood_fill(n, m, i-1, j);
    flood_fill(n, m, i, j+1);
    flood_fill(n, m, i+1, j);
    return;
  }
}



int main(){
  int n,m;
  scanf("%d %d", &n, &m);

  int rooms = 0;

  for(int i=0;i<1000;i++){
    for(int j=0;j<1000;j++){
      visited[i][j] = 0;
    }
  }

  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    for(int j=0;j<m;j++){
      if(s[j] == '#'){
        arr[i][j] = 0;
      }
      else{
        arr[i][j] = 1;
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(visited[i][j] != 1 && arr[i][j]==1){
        flood_fill(n, m, i, j);
        rooms++;
      }
    }
  }

  printf("%d", rooms);
}
