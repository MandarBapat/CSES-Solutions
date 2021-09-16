#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  scanf("%d %d", &n, &m);

  vector<pair<int,int>> h,c;
  int temp;
  map<int,int> u;
  for(int i=0;i<n;i++){
    scanf("%d", &temp);
    h.push_back({temp,i});
    u[temp] = 0;
  }
  c= h;
  sort(c.begin(), c.end());

  for(int i=0;i<m;i++){
    scanf("%d", &temp);
    vector<pair<int,int>>::iterator itr = lower_bound(c.begin(), c.end(), {temp,0});
    if(itr != c.end() && u[(itr->first)] != 1){
      u[(itr->first)] = 1;
      printf("%d ", (itr->first));
    }
    else{
      printf("%d ",0);
    }
  }
}
