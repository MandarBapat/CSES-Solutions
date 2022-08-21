#include <bits/stdc++.h>

using namespace std;

int n;
int c[100];

int ans[(int)(1e6+1)];

int dp(int x){
    if(x <= 0){
        return -1;
    }
    else if(ans[x] != 0){
        return ans[x];
    }
    else{
        int rv = -1;
        for(int j=0;j<n;j++){
            int temp = dp(x-c[j]);
            if(temp!=-1){
                if(rv != -1){
                    rv = min(rv, temp+1);
                }
                else{
                    rv = temp+1;
                }
            }
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

    for(int i=0;i<=(int)1e6;i++){
        ans[i] = 0;
    }

    for(int i=0;i<n;i++){
        cin >> c[i];
        ans[c[i]] = 1;
    }
    
    cout << dp(x);

    return 0;
}