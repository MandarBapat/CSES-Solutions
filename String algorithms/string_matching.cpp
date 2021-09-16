#include <bits/stdc++.h>

using namespace std;

int main(){
  string s1,s2;
  cin >> s1 >> s2;

  long int count = 0;

  string concat = s2 + "$" + s1;
  long int len = concat.length();
  long int z[len];
  long int l = 0, r = 0;
  z[0] = 0;

  for(long int i=1;i<len;i++){
    if(i > r){
      l=r=i;

      while(r<len && concat[r-l] == concat[r]){
        r++;
      }
      z[i] = r-l;
      r--;
    }

    else{
      int k;
      k = i - l;
      if(z[k] < (r-i+1)){
        z[i] = z[k];
      }
      else{
        l = i;

        while(r<len && concat[r-l] == concat[r]){
          r++;
        }
        z[i] = r-l;
        r--;
      }
    }
  }

  long int len2 = s2.length();
  
  for(long int i=(len2+1);i<len;i++){
    if(z[i] == len2){
      count++;
    }
  }

  printf("%ld", count);
}
