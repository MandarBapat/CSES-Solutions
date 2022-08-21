#include <bits/stdc++.h>

using namespace std;

#define M ((long long int)(1e9+7))

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int dp[n][n];

    char grid[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(grid[i][j] == '*'){
                dp[i][j] = 0;
            }
            else if( (i == n-1) && (j == n-1) ){
                dp[i][j] = 1;
            }
            else{
                int val1 = 0;
                int val2 = 0;
                if( (i+1) < n ){
                    val1 = dp[i+1][j];
                }
                if( (j+1) < n ){
                    val2 = dp[i][j+1];
                }

                dp[i][j] = ( (long long int)val1 + val2 )%M;
            }
        }
    }

    cout << dp[0][0];

    return 0;
}