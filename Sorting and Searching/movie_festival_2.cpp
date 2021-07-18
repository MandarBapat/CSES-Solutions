#include <bits/stdc++.h>

using namespace std;


int main(){
  int n,k;
  scanf("%d %d", &n, &k);

  int a,b;

  for(int i=0;i<n;i++){
    scanf("%d %d", &a, &b);
    set1.insert({b,a});
  }

  pair<int,int> temp;
  int m = 0;

  vector<pair<int,int>> v;
  while(k>0 && (!set1.empty())){
    temp = *(set1.begin());
    m++;
    for(auto itr = set1.begin();itr!=set1.end();itr++){
      if((itr->second) >= temp.first){
        temp = *itr;
        m++;
        set2.erase(set2.find(temp));
      }
    }
    set2.erase(set2.find(*(set1.begin())));
    set1 = set2;
    k--;
  }

  printf("%d", m);
}
