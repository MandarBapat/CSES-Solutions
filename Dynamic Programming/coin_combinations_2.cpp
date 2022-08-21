#include <bits/stdc++.h>

using namespace std;

#define M ((long long int)(1e9+7))

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    int c[n];

    for(int i=0;i<n;i++){
        cin >> c[i];
    }

    int ans[n][x+1];

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=x;j++){
            if(j == 0){
                ans[i][j] = 1;
            }
            else if(i == n-1){
                if(j%c[i] == 0){
                    ans[i][j] = 1;
                }
                else{
                    ans[i][j] = 0;
                }
            }
            else{
                int val1 = ans[i+1][j];
                int val2 = 0;
                if( (j-c[i]) >= 0 ){
                    val2 = ans[i][j-c[i]];
                }
                ans[i][j] = ((long long int)val1 + val2)%M;
            }
        }
    }

    cout << ans[0][x];

    return 0;
}