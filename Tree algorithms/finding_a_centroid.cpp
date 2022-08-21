#include <bits/stdc++.h>

using namespace std;

vector<int> adj[(int)(2e5+1)];

int num_nodes[(int)(2e5+1)];

int centroid;

int n;
int limit;

int find_num_nodes(int index, int parent){
    int ans = 1;
    for(auto x : adj[index]){
        if(x != parent){
            ans += find_num_nodes(x, index);
        }
    }

    num_nodes[index] = ans;
    return ans;
}

void find_centroid(int index, int parent){
    bool cond = true;
    for(auto x : adj[index]){
        if(x != parent){
            cond = cond && ( num_nodes[x] <= limit );
        }
    }
    if(parent != -1){
        int temp = n - num_nodes[index];
        cond = cond && (temp <= limit);
    }

    if(cond){
        centroid = index;
    }

    for(auto x : adj[index]){
        if(x != parent){
            find_centroid(x, index);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;

    int limit = (int)floor(n/2);

    int a, b;
    for(int i=1;i<=(n-1);i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    find_num_nodes(1, -1);
    find_centroid(1, -1);

    cout << centroid;

    return 0;
}