#include <bits/stdc++.h>

using namespace std;

vector<int> adj[(int)(2e5+1)];

int dp[(int)(2e5+1)][2];

int f(int index, int marked, int parent){
    if(dp[index][marked] != -1){
        return dp[index][marked];
    }
    else{
        int children = 0;
        if(index == 1){
            children = adj[index].size();
        }
        else{
            children = adj[index].size() - 1;
        }

        if(children == 0){
            dp[index][marked] = 0;
            dp[index][1-marked] = 0;
            return 0;
        }
        else{
            if(marked == 1){
                int val = 0;
                for(auto c : adj[index]){
                    if(c != parent){
                        val += f(c, 0, index);
                    }
                }
                dp[index][1] = val;
                return val;
            }
            else{
                int val = 0;
                for(auto c : adj[index]){
                    if(c != parent){
                        val += f(c, 0, index);
                    }
                }

                int val2 = 0;
                for(auto c : adj[index]){
                    if(c != parent){
                        val2 = max(val2, 1 + f(c,1,index) + val-f(c,0,index));
                    }
                }

                dp[index][0] = max(val2, val);
                return dp[index][0];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a, b;
    for(int i=1;i<=(n-1);i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<((int)(2e5+1));i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
    }

    cout << f(1, 0, -1);

    return 0;

}