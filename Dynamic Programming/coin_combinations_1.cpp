#include <bits/stdc++.h>

using namespace std;

#define M ((long long int)(1e9+7))

int n;
int c[100];
int ans[(int)(1e6+1)];

int dp(int x){
    if(x < 0){
        return 0;
    }
    else if(ans[x] != -1){
        return ans[x];
    }
    else{
        long long int rv = 0;
        for(int i=0;i<n;i++){
            rv = (rv + dp(x-c[i]))%M;
        }
        ans[x] = rv;
        return rv;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> n >> x;

    for(int i=0;i<=(1e6);i++){
        ans[i] = -1;
    }
    ans[0] = 1;

    int min1 = INT_MAX;
    for(int i=0;i<n;i++){
        cin >> c[i];
        min1 = min(min1, c[i]);
    }
    ans[min1] = 1;

    cout << dp(x);

    return 0;
}