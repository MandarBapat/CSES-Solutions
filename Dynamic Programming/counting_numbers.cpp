#include <bits/stdc++.h>

using namespace std;

int find_num_of_digits(long long int x){
    int ans = 0;
    while(x > 0){
        ans++;
        x = x/10;
    }

    return ans;
}

int dp(long long int x, int d){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long int a, b;
    cin >> a >> b;

    cout << dp(b, find_num_of_digits(b)) - dp(a-1, find_num_of_digits(a));
}