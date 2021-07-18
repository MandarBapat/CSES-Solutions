#include <bits/stdc++.h>

using namespace std;

int main(){
  int q;
  cin >> q;

  for(int j=1;j<=q;j++){
    unsigned long long int k;
    scanf("%ulld", &k);
    unsigned long long int i =1;
    unsigned long long int counter = 0;
    string s = "";
    while(counter<=k){
      s = s + to_string(i);
      counter = counter + to_string(i).size();
      i++;
    }
    cout << s[k-1] << "\n";
    }
}
