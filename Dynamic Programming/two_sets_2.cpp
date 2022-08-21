#include <bits/stdc++.h>

using namespace std;

#define M ((long long int)(1e9+7))

long long int mod_pow(long long int x, long long int y){
    if(y == 1){
        return x;
    }
    else if(y == 0){
        return 1;
    }
    else if(x == 0){
        return 0;
    }
    else{
        long long int p = 1;
        while(y > 0){
            if(y&1){
                p = (p*x)%M;
            }
            x = (x*x)%M;
            y = y >> 1;
        }
        return p;
    }
}

long long int mod_inv(long long int x){
    return mod_pow(x, M-2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int sum = (n*(n+1))/2;

    if(sum&1){
        cout << 0;
    }
    else{
        int t = sum/2;
        

        long long int dp[n][t+1];
        
        dp[n-1][0] = 1;
        
        for(int j=1;j<=t;j++){
            if(j == n){
                dp[n-1][j] = 1;
            }
            else{
                dp[n-1][j] = 0;
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=t;j++){
                if(j == 0){
                    dp[i][j] = 1;
                }
                else{
                    long long int val1 = dp[i+1][j];
                    long long int val2 = 0;
                    if(j-i-1 >= 0){
                        val2 = dp[i+1][j-i-1];
                    }
                    long long int z1 = (val1 + val2)%M;
                    dp[i][j] = z1;
                }
            }
        }

        cout << (dp[0][t]*mod_inv(2))%M;
    }

    return 0;
}