#include <bits/stdc++.h>

using namespace std;

int main(){
  long int n;
  cin >> n;

  set<long long int> s1;

  for(long int i=1;i<=n;i++){
    long long int x;
    cin >> x;
    s1.insert(x);
  }
  cout << s1.size();
}
