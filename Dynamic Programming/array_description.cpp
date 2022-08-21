#include <bits/stdc++.h>

using namespace std;

#define M ((long long int)(1e9+7))

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int dp[n][m+1];

    if(arr[n-1] == 0){
        for(int j=1;j<=m;j++){
            dp[n-1][j] = 1;
        }
    }
    else{
        for(int j=1;j<=m;j++){
            if(arr[n-1] == j){
                dp[n-1][j] = 1;
            }
            else{
                dp[n-1][j] = 0;
            }
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j=m;j>=1;j--){
            if(arr[i] == 0){
                int val1 = 0, val2 = dp[i+1][j], val3 = 0;
                if( (j-1) >= 1 ){
                    val1 = dp[i+1][j-1];
                }
                if( (j+1) <= m ){
                    val3 = dp[i+1][j+1];
                }
                dp[i][j] = ((long long int)val1 + val2 + val3)%M;
            }
            else{
                if(j == arr[i]){
                    int val1 = 0, val2 = dp[i+1][j], val3 = 0;
                    if( (j-1) >= 1 ){
                        val1 = dp[i+1][j-1];
                    }
                    if( (j+1) <= m ){
                        val3 = dp[i+1][j+1];
                    }
                    dp[i][j] = ((long long int)val1 + val2 + val3)%M;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=m;i++){
        ans =  ((long long int)ans + dp[0][i])%M;
    }

    cout << ans;

    return 0;
}