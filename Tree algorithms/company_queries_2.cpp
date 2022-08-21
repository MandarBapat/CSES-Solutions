#include <bits/stdc++.h>

using namespace std;

int parent[(int)(2e5+1)];
vector<int> adj[(int)(2e5+1)];
int level_of[(int)(2e5+1)];

int binary_lifting[(int)(2e5+1)][23];

void fill_jumps(int index){
    if(index == 1){
        for(int i=0;i<23;i++){
            binary_lifting[index][i] = -1;
        }
    }
    else{
        binary_lifting[index][0] = parent[index];
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
        fill_jumps(x);
    }
}

void fill_levels(int index, int l){
    level_of[index] = l;
    for(auto x : adj[index]){
        fill_levels(x, l+1);
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    int e;
    for(int i=2;i<=n;i++){
        cin >> e;
        parent[i] = e;
        adj[e].push_back(i);
    }

    fill_jumps(1);
    fill_levels(1, 1);

    int a, b;
    for(int i=1;i<=q;i++){
        cin >> a >> b;
        int l1 = level_of[a];
        int l2 = level_of[b];

        if(l1 > l2){
            a = jump_k_levels_up(a, l1-l2);
        }
        else if(l2 > l1){
            b = jump_k_levels_up(b, l2-l1);
        }
        
        if(a == b){
            cout << a << "\n";
        }
        else{
            for(int i=22;i>=0;i--){
                if(binary_lifting[a][i] != binary_lifting[b][i]){
                    a = binary_lifting[a][i];
                    b = binary_lifting[b][i];
                }
            }
            cout << binary_lifting[a][0] << "\n";
        }
    }

    return 0;
}