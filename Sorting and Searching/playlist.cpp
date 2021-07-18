#include <bits/stdc++.h>

using namespace std;

int main(){
  long int n;
  cin >> n;


  vector<long long int> v;

  for(long int i=1;i<=n;i++){
    long long int temp;
    cin >> temp;

    v.push_back(temp);
  }

  long int max = 1;
  long int temp = 1;

  auto i = v.begin();
  auto j = v.begin();
  j++;

  set<long long int> set1;
  set1.insert((*i));

  while(j!=v.end()){
    if(set1.find((*j)) == set1.end()){
      set1.insert((*j));
      temp++;
      j++;
    }
    else{
      while((*i) != (*j)){
        set1.erase((*i));
        i++;
        temp--;
      }
      set1.erase(*i);
      i++;
      temp--;
    }
    if(temp > max){
      max = temp;
    }
  }

  cout << max;
}
