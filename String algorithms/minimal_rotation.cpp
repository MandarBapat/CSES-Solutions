#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  long int len = s.length();
  set<string> set1;

  s = s + s;
  string r = "";
  for(int i=0;i<=(len-1);i++){
    r = s.substr(i,len);
    set1.insert(r);
  }

  cout << *(set1.begin());
}
