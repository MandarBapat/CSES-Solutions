#include <bits/stdc++.h>

using namespace std;

vector<int> adj[(int)(2e5+1)];
int level_of[(int)(2e5+1)];
int binary_lifting[(int)(2e5+1)][23];
int values[(int)(2e5+1)];
int final_ans[(int)(2e5+1)];

void fill_levels(int index, int parent, int l){
    level_of[index] = l;
    for(auto x : adj[index]){
        if(x != parent){
            fill_levels(x, index, l+1);
        }
    }
}

void fill_jumps(int index, int parent){
    if(index == 1){
        for(int i=0;i<23;i++){
            binary_lifting[index][i] = -1;
        }
    }
    else{
        binary_lifting[index][0] = parent;
        for(int i=1;i<23;i++){
            int val = binary_lifting[index][i-1];
            if(val == -1){
                binary_lifting[index][i] = val;
            }
            else{
                binary_lifting[index][i] = binary_lifting[val][i-1];
            }
        }
    }

    for(auto x : adj[index]){
        if(x != parent){
            fill_jumps(x, index);
        }
    }
}

int jump_k_levels_up(int index, int k){
    int node = index;
    int p = 0;
    while(node != -1 && k > 0){
        if(k&1){
            node = binary_lifting[node][p];
        }
        p++;
        k = k >> 1;
    }

    return node;
}

int find_lca_of(int a, int b){
    int l1 = level_of[a];
    int l2 = level_of[b];

    if(l1 > l2){
        a = jump_k_levels_up(a, l1-l2);
    }
    else if(l2 > l1){
        b = jump_k_levels_up(b, l2-l1);
    }

    if(a == b){
        return a;
    }
    else{
        for(int i=22;i>=0;i--){
            if(binary_lifting[a][i] != binary_lifting[b][i]){
                a = binary_lifting[a][i];
                b = binary_lifting[b][i];
            }
        }
        return binary_lifting[a][0];
    }
}

void find_sum(int index, int parent){
    int ans = 0;
    for(auto x : adj[index]){
        if(x != parent){
            find_sum(x, index);
            ans += final_ans[x];
        }
    }
    ans += values[index];
    final_ans[index] = ans;
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b;
    for(int i=1;i<=(n-1);i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    fill_levels(1, -1, 1);
    fill_jumps(1, -1);

    for(int i=0;i<m;i++){
        cin >> a >> b;
        int lca = find_lca_of(a, b);
        int p_lca = binary_lifting[lca][0];
        values[a] += 1;
        values[b] += 1;
        values[lca] -= 1;
        if(p_lca != -1){
            values[p_lca] -= 1;
        }
    }

    find_sum(1, -1);

    for(int i=1;i<=n;i++){
        cout << final_ans[i] << " ";
    }

    return 0;
}