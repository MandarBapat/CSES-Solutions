#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int dp[n+1];
    dp[0] = 0;
    for(int i=1;i<=9;i++){
        dp[i] = 1;
    }

    for(int i=10;i<=n;i++){
        int temp = i;
        int ans = INT_MAX;
        while(temp > 0){
            int digit = temp%10;
            temp = temp/10;
            if(digit){
                ans = min(ans, dp[i-digit]);
            }
        }
        dp[i] = ans+1;
    }

    cout << dp[n];

    return 0;
}