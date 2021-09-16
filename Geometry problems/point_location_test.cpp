#include <bits/stdc++.h>

using namespace std;

int main(){
  long int t;
  cin >> t;

  pair<long long int, long long int> p1,p2,p3;
  for(long int i=1;i<=t;i++){
    long long int x,y;
    cin >> x >> y;
    p1 = make_pair(x,y);

    cin >> x >> y;
    p2 = make_pair(x,y);

    cin >> x >> y;
    p3 = make_pair(x,y);

    pair<long long int, long long int> v1 = {(p2.first - p1.first), (p2.second - p1.second)};
    pair<long long int, long long int> v2 = {(p3.first - p1.first), (p3.second - p1.second)};

    long long int diff = (v1.first)*(v2.second) - (v1.second)*(v2.first);
    if(diff>0){
      cout << "LEFT" << "\n";
    }
    else if(diff < 0){
      cout << "RIGHT" << "\n";
    }
    else{
      cout << "TOUCH" << "\n";
    }
  }
}
