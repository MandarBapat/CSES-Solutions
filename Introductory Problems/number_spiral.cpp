#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
  int t;
  cin >> t;

  for(int i=1;i<=t;i++){
    ll y,x;
    cin >> y >> x;

    if(y>=x){
      if(y%2==0){
        cout << y*y - x + (long long)1 << "\n";
      }
      else{
        cout << (y-1)*(y-1) + x << "\n";
      }
    }

    else{
      if(x%2!=0){
        cout << x*x - y + (long long)1 << "\n";
      }
      else{
        cout << (x-1)*(x-1) + y << "\n";
      }
    }
  }
}
