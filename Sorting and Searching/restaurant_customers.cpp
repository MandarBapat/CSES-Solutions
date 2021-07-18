#include <bits/stdc++.h>

using namespace std;


int main(){
  int n;
  scanf("%d", &n);

  set<pair<int,int>> set1;
  int a,b;
  for(int i=1;i<=n;i++){
    scanf("%d %d", &a, &b);
    set1.insert({a,0});
    set1.insert({b,1});
  }

  int count = 0;
  int max = 0;

  for(auto p : set1){
    if(p.second == 0){
      count++;
    }
    else{
      count--;
    }
    if(count > max){
      max = count;
    }
  }

  printf("%d", max);
}
