#include <bits/stdc++.h>

using namespace std;

#define M ((long long int)(1e9+7))

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int* ans = (int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=6;i++){
        ans[i] = (int)pow(2,i-1);
    }

    for(int i=7;i<=n;i++){
        ans[i] = 0;
        for(int j=1;j<=6;j++){
            ans[i] = ((long long int)ans[i] + ans[i-j])%M;
        }
    }

    cout << ans[n];

    return 0;
}