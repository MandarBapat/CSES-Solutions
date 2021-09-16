#include <bits/stdc++.h>

using namespace std;

unsigned int dp[(long long int)(1e6+1)][(long long int)(1e6+1)] = {0};

unsigned int choose(long int p, long int q){

  if(dp[p][q] == 0 && (p>=q)){
    if(p==q){
      dp[p][q] = 1;
    }
    else if((q==0) && (p!=0)){
      dp[p][q] = 1;
    }
    else if(q==1){
      dp[p][q] = p;
    }
    else{
      if((dp[p-1][q] == 0) && ((p-1)>=q)){
        dp[p-1][q] = choose(p-1,q);
      }

      if((dp[p-1][q-1] == 0) && (p>=q)){
        dp[p-1][q-1] = choose(p-1,q-1);
      }

      dp[p][q] = ((dp[p-1][q])%((long long int)(1e9 + 7)) + (dp[p-1][q-1])%((long long int)(1e9 + 7)))%((long long int)(1e9 + 7));
    }
  }

  return dp[p][q];
}

int main(){
  long int n,m;

  scanf("%ld %ld", &n, &m);

  long int p = m + n -1;
  long int q = n-1;

  cout << choose(p,q);

}
