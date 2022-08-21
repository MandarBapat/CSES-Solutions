#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int dp[n+1];

    dp[0] = INT_MIN;
    for(int i=1;i<=n;i++){
        dp[i] = INT_MAX;
    }

    for(int i=0;i<n;i++){
        int pos = upper_bound(dp, dp+n+1, arr[i]) - dp;
        if(arr[i] > dp[pos-1] && arr[i] < dp[pos]){
            dp[pos] = arr[i];
        }
    }

    for(int i=n;i>=0;i--){
        if(dp[i] < INT_MAX){
            cout << i;
            break;
        }
    }

    return 0;
}