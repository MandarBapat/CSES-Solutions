#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  scanf("%d %d", &n, &m);

  multiset<int> h;
  int temp;
  for(int i=0;i<n;i++){
    scanf("%d", &temp);
    h.insert(temp);
  }

  int t[m];

  for(int i=0;i<m;i++){
    scanf("%d", &t[i]);
  }

  for(int i=0;i<m;i++){
    auto itr = h.lower_bound(t[i]);
    if((*itr) == t[i]){
      printf("%d\n", *itr);
      h.erase(itr);
    }
    else if((*itr) != t[i] && itr == h.begin()){
      printf("%d\n",-1);
    }
    else if((*itr) != t[i] && itr!= h.begin()){
      itr--;
      printf("%d\n", (*itr));
      h.erase(itr);
    }
  }
}
