#include <bits/stdc++.h>

using namespace std;

long int count(string s, int n){
    int i = 0;
    unordered_set<string> u;

    while(i <= (s.length()-n)){
      u.insert(s.substr(i,n));
      i++;
    }
    return u.size();
}

int main(){
  string s;
  cin >> s;

  for(int i=1;i<=(s.length());i++){
    printf("%ld ", count(s,i));
  }
}
