#include <bits/stdc++.h>

using namespace std;

int main(){
  string dna;
  cin >> dna;

  long int pos = 1;
  long int len = 1;
  long int maxlen = 1;

  while(pos<dna.length()){
    if(dna[pos] == dna[pos-1]){
      len+=1;
    }
    else{
      len = 1;
    }
    if(len>maxlen){
      maxlen=len;
    }
    pos++;
  }
  printf("%ld",maxlen);
}
