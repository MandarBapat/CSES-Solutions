#include <bits/stdc++.h>

using namespace std;

vector<int> adj[(int)(2e5+1)];
int level_of[(int)(2e5+1)];
int binary_lifting[(int)(2e5+1)][23];

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
            int val1 = binary_lifting[index][i-1];
            if(val1 == -1){
                binary_lifting[index][i] = -1;
            }
            else{
                binary_lifting[index][i] = binary_lifting[val1][i-1];
            }
        }
    }

    for(auto x : adj[index]){
        if(x != parent){
            fill_jumps(x, index);
        }
    }
}

int jump_k_levels_up(int x, int k){
    int node = x;
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

int find_level_of_lca(int a, int b){
    int l1 = level_of[a];
    int l2 = level_of[b];
    
    if(l1 > l2){
        a = jump_k_levels_up(a, l1-l2);
    }
    else if(l2 > l1){
        b = jump_k_levels_up(b, l2-l1);
    }

    if(a == b){
        return min(l1, l2);
    }
    else{
        for(int i=22;i>=0;i--){
            if(binary_lifting[a][i] != binary_lifting[b][i]){
                a = binary_lifting[a][i];
                b = binary_lifting[b][i];
            }
        }
        a = binary_lifting[a][0];
        return level_of[a];
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    int a, b;
    for(int i=1;i<=(n-1);i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    fill_levels(1, -1, 1);
    fill_jumps(1, -1);

    for(int i=1;i<=q;i++){
        cin >> a >> b;

        int l1 = level_of[a];
        int l2 = level_of[b];

        int level_of_lca = find_level_of_lca(a, b);

        cout << l1 + l2 - 2*level_of_lca << "\n";
    }

    return 0;
}