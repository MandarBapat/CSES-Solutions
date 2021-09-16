#include <bits/stdc++.h>

using namespace std;

unordered_map<set<int>, int> u;


int max_count(int h[], set<int> set1, int s[]){
  
}

int main(){
  int n,x;
  scanf("%d %d", &n, &x);

  int h[n], s[n];
  for(int i=0;i<n;i++){
    scanf("%d", &h[i]);
  }
  for(int i=0;i<n;i++){
    scanf("%d", &s[i]);
  }

  set<int> set1;

  for(int i=1;i<=n;i++){
    set1.insert(i);
  }

  for(int i=1;i<=n;i++){
    set<int> set2;
    set2.insert(i);
    if(h[i-1] < x){
      u[set2] = s[i-1];
    }
  }

  printf("%d", max_count(h, set1, s));

}
