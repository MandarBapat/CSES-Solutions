#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;

  cin >> s;
  map<char,int> m;
  unordered_map<char,int> u;
  char odd;
  for(char c : s){
    m[c]++;
  }

  for(auto p : m){
    if((p.second)%2!=0){
      u['o']++;
    }
  }

  if(u['o']>1){
    cout << "NO SOLUTION";
  }
  else{
    for(auto p : m){
      if((p.second)%2!=0){
        odd = (p.first);
      }
    }

    if(u['o']==1){
      for(auto p : m){
        if((p.second)%2==0){
          cout << string((p.second)/2, (p.first));
        }
      }
      cout << string(m[odd], odd);
      for(auto itr = m.rbegin(); itr!=m.rend();itr++){
        if((itr->second)%2==0){
          cout << string((itr->second)/2, (itr->first));
        }
      }
    }
    else{
      for(auto p : m){
        cout << string((p.second)/2, (p.first));
      }
      for(auto itr = m.rbegin(); itr != m.rend(); itr++){
        cout << string((itr->second)/2, (itr->first));
      }
    }
  }
}
