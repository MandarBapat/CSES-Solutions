#include <bits/stdc++.h>

using namespace std;

vector<int> adj[(int)(2e5+1)];
int final_ans[(int)(2e5+1)];
int color[(int)(2e5+1)];

set<int> num_distinct_values(int index, int parent){
    set<int> ans;
    ans.insert(color[index]);
    for(auto x : adj[index]){
        if(x != parent){
            set<int> temp = num_distinct_values(x, index);
            for(auto val : temp){
                ans.insert(val);
            }
        }
    }

    final_ans[index] = ans.size();
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> color[i];
    }

    int a, b;
    for(int i=1;i<=(n-1);i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    num_distinct_values(1, -1);

    for(int i=1;i<=n;i++){
        cout << final_ans[i] << " ";
    }

    return 0;
}