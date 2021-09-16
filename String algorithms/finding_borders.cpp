#include <bits/stdc++.h>

using namespace std;


int main(){
  string s;
  cin >> s;

  long int len = s.length();
  long int z[len];
  long int l=0, r=0;
  z[0] = 0;

  for(int i=1;i<len;i++){
    if(i>r){
      l=r=i;

      while(r<len && s[r-l] == s[r]){
        r++;
      }
      z[i] = r-l;
      r--;
    }

    else{
      long int k = i - l;
      if(z[k] < (r-i+1)){
        z[i] = z[k];
      }
      else{
        l = i;

        while(r<len && s[r-l] == s[r]){
          r++;
        }
        z[i] = r-l;
        r--;
      }
    }
  }
  set<long int> set1;
  for(int i=1;i<len;i++){
    if(z[i]!=0 && z[i] == (len-i)){
      set1.insert(z[i]);
    }
  }

  for(auto i : set1){
    cout << i << " ";
  }
}
