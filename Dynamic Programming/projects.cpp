#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int> v1, vector<int> v2){
    if(v1[0] < v2[0]){
        return true;
    }
    else if(v1[0] == v2[0] && v1[1] < v2[1]){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> projects;

    for(int i=0;i<n;i++){
        int a, b, p;
        cin >> a >> b >> p;
        vector<int> temp = {a, b, p};
        projects.push_back(temp);
    }

    sort(projects.begin(), projects.end(), comp);

    long long int dp[n];
    dp[n-1] = projects[n-1][2];

    for(int i=n-2;i>=0;i--){
        long long int val1 = dp[i+1];
        long long int val2 = 0;

        vector<int> key = {projects[i][1], INT_MAX, 0};
        int j = upper_bound(projects.begin(), projects.end(), key) - projects.begin();

        if(j < n){
            val2 = dp[j];
        }

        dp[i] = max(val1, val2 + projects[i][2]);
    }

    cout << dp[0];

    return 0;
}