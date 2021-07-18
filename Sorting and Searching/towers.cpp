#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);

  int k[n], p[n], z[n];
  int temp;
  for(int i=0;i<n;i++){
    scanf("%d", &temp);
    k[i] = temp;
    p[i] = temp;
    z[temp] = i;
  }

  sort(k, k+n);

  int count = 1;
  vector<vector<int>> v;
  v[0].push_back(p[0]);
  for(int i=1;i<n;i++){
    auto itr = upper_bound(p,p+n,p[i]);
    
  }

}
