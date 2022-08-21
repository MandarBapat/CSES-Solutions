#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    long long int arr[n];
    long long int pre_sum[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(i == 0){
            pre_sum[i] = arr[i];
        }
        else{
            pre_sum[i] = pre_sum[i-1] + arr[i];
        }
    }

    long long int dp[n][n];
    for(int i=0;i<n;i++){
        dp[i][i] = arr[i];
    }

    for(int j=n-1;j>=1;j--){
        dp[j-1][j] = max(arr[j-1], arr[j]);
    }

    for(int d=2;d<=n-1;d++){
        for(int j=n-1;j>=d;j--){
            long long int S = 0;
            if(j-d == 0){
                S = pre_sum[j];
            }
            else{
                S = pre_sum[j] - pre_sum[j-d-1];
            }
            dp[j-d][j] = S - min(dp[j-d+1][j], dp[j-d][j-1]);
        }
    }

    cout << dp[0][n-1];
    return 0;
}