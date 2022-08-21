#include <bits/stdc++.h>

using namespace std;

vector<int> adj[(int)(2e5+1)];

long long int final_ans[(int)(2e5+1)];

int count_nodes[(int)(2e5+1)];

long long int dist_with_root_as_1[(int)(2e5+1)];

int n;

int calculate_no_nodes(int index, int parent){
    int ans = 0;
    for(auto x : adj[index]){
        if(x != parent){
            ans += calculate_no_nodes(x, index);
        }
    }
    ans += 1;
    count_nodes[index] = ans;
    return ans;
}

long long int calculate_dist_with_root_as_1(int index, int parent){
    long long int ans = 0;
    for(auto x : adj[index]){
        if(x != parent){
            ans += calculate_dist_with_root_as_1(x, index);
            ans += count_nodes[x];
        }
    }

    dist_with_root_as_1[index] = ans;
    return ans;
}

void f(int index, int parent){
    for(auto x : adj[index]){
        if(x != parent){
            final_ans[x] = (final_ans[index] - dist_with_root_as_1[x] - count_nodes[x]) + (n - count_nodes[x]) + dist_with_root_as_1[x];
            f(x, index);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int a,b;
    for(int i=1;i<=(n-1);i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    calculate_no_nodes(1, -1);
    calculate_dist_with_root_as_1(1, -1);

    final_ans[1] = dist_with_root_as_1[1];

    f(1, -1);

    for(int i=1;i<=n;i++){
        cout << final_ans[i] << " ";
    }

    return 0;
}