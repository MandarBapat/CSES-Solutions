#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> u;
int start, end;
deque<int> q;

void bfs(int arr[], int dis[]){
  int node = q.pop_front();
  for(auto c : arr[node]){
    if(!visited[node]){
      q.push_back(c);
      dis[c] = dis[node]+1;
    }
  }
}

int main(){
  int n,m;
  scanf("%d %d", &n, &m);

  vector<int> arr[n*m];
  int visited[n*m];
  int dis[n*m] = {INT_MAX};

  int mat[n][m];
  for(int i=0;i<n;i++){
    string r;
    cin >> r;
    for(int j=0;j<m;j++){
      if(s[j]=='#'){
        mat[i][j] = 0;
      }
      else if(s[j]=='.'){
        mat[i][j] = 1;
      }
      else if(s[j] == 'A'){
        start = i*n + j;
      }
      else{
        end = i*n + j;
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int node = i*n+j;
      if(i-1 >=0 && mat[i-1][j] != 0){
        arr[node].push_back((i-1)*n + j);
      }
      if(i+1 <n && mat[i+1][j] != 0){
        arr[node].push_back((i+1)*n + j);
      }
      if(j-1 >=0 && mat[i][j-1] != 0){
        arr[node].push_back((i)*n + j-1);
      }
      if(j+1 <m && mat[i][j+1] != 0){
        arr[node].push_back((i)*n + (j+1));
      }
    }
  }

  dis[start] = 0;
  bfs(start, end);
}
