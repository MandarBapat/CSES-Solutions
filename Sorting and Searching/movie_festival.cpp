#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);

  set<pair<int,int>> set1;
  int a,b;

  for(int i=0;i<n;i++){
    scanf("%d %d", &a, &b);
    set1.insert({b,a});
  }

  int count = 1;
  pair<int,int> temp = (*set1.begin());

  for(auto itr = set1.begin(); itr!=set1.end(); itr++){
    if(itr->second >= temp.first){
      count++;
      temp = (*itr);
    }
  }

  printf("%d", count);
}
