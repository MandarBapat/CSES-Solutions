#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,x;
    cin >> n >> x;

    int prices[n];
    for(int i=0;i<n;i++){
        cin >> prices[i];
    }

    int pages[n];
    for(int i=0;i<n;i++){
        cin >> pages[i];
    }

    int dp[n][x+1];
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=x;j++){
            if(i == n-1){
                if(j >= prices[n-1]){
                    dp[n-1][j] = pages[n-1];
                }
                else{
                    dp[n-1][j] = 0;
                }
            }
            else if(j == 0){
                dp[i][j] = 0;
            }
            else{
                int val1 = dp[i+1][j];
                int val2 = 0;
                if( (j - prices[i]) > 0 ){
                    val2 = dp[i+1][j - prices[i]] + pages[i];
                }
                else if(j - prices[i] == 0){
                    val2 = pages[i];
                }
                dp[i][j] = max(val1, val2);
            }
        }
    }

    cout << dp[0][x];

    return 0;
}