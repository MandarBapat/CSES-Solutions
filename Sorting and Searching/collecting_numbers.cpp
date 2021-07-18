#include <bits/stdc++.h>

using namespace std;

int main(){
  long int n;
  cin >> n;

  map<long int, long int> m;
  for(int i=1;i<=n;i++){
    long int temp;
    cin >> temp;
    m[temp] = i;
  }

  long int rounds = 1;
  for(int i=2;i<=n;i++){
    if(m[i-1] > m[i]){
      rounds++;
    }
  }

  cout << rounds;
}
