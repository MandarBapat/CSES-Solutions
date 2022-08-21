#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int l1 = s1.length();
    int l2 = s2.length();

    int dp[l1+1][l2+1];

    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i == 0){
                dp[i][j] = j;
            }
            else if(j == 0){
                dp[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j-1]), dp[i-1][j]);
            }
        }
    }

    cout << dp[l1][l2];

    return 0;
}