#include <bits/stdc++.h>

using namespace std;

int fact(int x){
  if(x==0 || x==1){
    return 1;
  }
  else if(x==2){
    return 2;
  }
  else if(x==3){
    return 6;
  }
  else{
    return x*fact(x-1);
  }
}

set<string> permute(string s){
  set<string> set1;
  if(s.length()==1){
    set1.insert(s);
    return set1;
  }
  else if(s.length()==2){
    if(s[0]==s[1]){
      set1.insert(s);
      return set1;
    }
    else{
      set1.insert(s);
      char temp = s[0];
      s[0] = s[1];
      s[1] = temp;
      set1.insert(s);
      return set1;
    }
  }
  else{
    for(int i=0;i<s.length();i++){
      char temp = s[0];
      s[0] = s[i];
      s[i] = temp;
      string r = s.substr(1);
      set<string> set2 = permute(r);
      for(auto k : set2){
        set1.insert(s[0] + k);
      }
    }
    return set1;
  }
}


int main(){
  string s;

  cin >> s;

  map<char, int> m;
  set<string> set1;

  for(char c : s){
    m[c]++;
  }

  int num = fact(s.length());

  for(auto p : m){
    num = num/fact(p.second);
  }

  cout << num << "\n";

  set1 = permute(s);


  for(auto k : set1){
    cout << k << "\n";
  }
}
