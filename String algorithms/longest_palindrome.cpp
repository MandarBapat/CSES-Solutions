#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;

  long int len = s.length();

  long int maxlen = 0;
  long int temp = 0;

  long int l, r;
  string sub = "";


  for(int i=1;i<len;i++){
    l = (i-1);
    r= i;

    while( (r<len) && (l>=0) && (s[l]==s[r])){
      temp = temp + 2;
      l--;
      r++;
    }
    l++;
    r--;
    if(temp > maxlen){
      sub = s.substr(l,temp);
      maxlen = temp;
    }

    l = (i-1);
    r = (i+1);
    temp = 1;
    while((r<len) && (l>=0) && (s[l]==s[r])){
      temp = temp + 2;
      l--;
      r++;
    }
    l++;
    r--;
    if(temp > maxlen){
      sub = s.substr(l,temp);
      maxlen = temp;
    }
    temp=0;
    i++;
  }


  cout << sub;
}
