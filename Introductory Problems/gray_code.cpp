#include <bits/stdc++.h>

using namespace std;


vector<string> hamming(int n){
  vector<string> v;
  if(n==1){
    v.push_back("0");
    v.push_back("1");
    return v;
  }
  else if(n==2){
    v.push_back("00");
    v.push_back("01");
    v.push_back("11");
    v.push_back("10");
    return v;
  }
  else{
    vector<string> v2 = hamming(n-1);
    for(auto itr = v2.begin(); itr != v2.end(); itr++){
      v.push_back("0" + *itr);
    }
    for(auto itr = v2.rbegin(); itr!=v2.rend(); itr++){
      v.push_back("1" + *itr);
    }
    return v;
  }
}

int main(){
  int n;

  cin >> n;

  vector<string> v3 = hamming(n);
  for(auto itr = v3.begin(); itr != v3.end(); itr++){
    cout << *itr << "\n";
  }
}
