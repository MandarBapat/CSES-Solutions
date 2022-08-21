#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    cin >> a >> b;

    int dp[a+1][b+1];

    for(int i=1;i<(a+1);i++){
        for(int j=1;j<(b+1);j++){
            if(i == j){
                dp[i][j] = 0;
            }
            else if(i == 1){
                dp[i][j] = j-1;
            }
            else if(j == 1){
                dp[i][j] = i-1;
            }
            else{
                int val1 = INT_MAX;
                int val2 = INT_MAX;

                for(int d=1;d<=(i/2);d++){
                    val1 = min(val1, dp[i-d][j] + dp[d][j]);
                }

                for(int d=1;d<=(j/2);d++){
                    val2 = min(val2, dp[i][j-d] + dp[i][d]);
                }

                dp[i][j] = min(val1, val2) + 1;
            }
        }
    }

    cout << dp[a][b];

    return 0;
}