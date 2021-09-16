#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;

  long int k;
  scanf("%ld", &k);

  set<string> set1;

  int j = 0;
  int len = s.length();
  for(int i=1;i<=k;i++){
    j = 0;
    while(j<=(len-i)){
      set1.insert(s.substr(j,i));
      j++;
    }
  }

  auto itr = set1.begin();
  advance(itr, k-1);

  cout << *(itr);
}
