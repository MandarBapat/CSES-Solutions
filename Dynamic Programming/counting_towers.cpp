#include <bits/stdc++.h>

using namespace std;

#define M ((long long int)(1e9+7))

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    long long int dp[(int)(1e6+1)][2];

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i=2;i<(int)(1e6+1);i++){
        dp[i][0] = ((4*dp[i-1][0])%M + dp[i-1][1])%M;
        dp[i][1] = ((2*dp[i-1][1])%M + dp[i-1][0])%M;
    }

    for(int i=1;i<=t;i++){
        int n;
        cin >> n;

        cout << (dp[n][0] + dp[n][1])%M << "\n"; 
    }

}