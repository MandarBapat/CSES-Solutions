#include <bits/stdc++.h>

using namespace std;



int main(){
  int n;

  cin >> n;

  vector<long long int> p;
  long long int temp;
  for(int i=0;i<n;i++){
    cin >> temp;
    p.push_back(temp);
  }

  vector<long long int> v;
  for(int i=1;i<=((long long int)pow(2,n)-2);i++){
    bitset<21> b(i);
    string s = b.to_string();
    long long int sum1 = 0;
    long long int sum2 = 0;
    for(int j=(s.size()-p.size());j<(s.size());j++){
      if(s[j]=='1'){
        sum1 += p[s.size()-j-1];
      }
      else{
        sum2 += p[s.size()-j-1];
      }
    }
    v.push_back(abs(sum1-sum2));
  }

  if(p.size()==1){
    cout << p[0];
  }
  else{
    sort(v.begin(), v.end());
    cout << v[0];
  }

}
