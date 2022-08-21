#include <bits/stdc++.h>

using namespace std;

int parent[(int)(2e5+1)];
int binary_lifting[(int)(2e5+1)][23];
vector<int> adj[(int)(2e5+1)];

void fill_jumps(int index){
    if(index == 1){
        for(int i=0;i<23;i++){
            binary_lifting[index][i] = -1;
        }
    }
    else{
        for(int i=0;i<23;i++){
            if(i == 0){
                binary_lifting[index][i] = parent[index];
            }
            else{
                if(binary_lifting[index][i-1] == -1){
                    binary_lifting[index][i] = -1;
                }
                else{
                    binary_lifting[index][i] = binary_lifting[binary_lifting[index][i-1]][i-1];
                }
            }
        }
    }
    for(auto x : adj[index]){
        fill_jumps(x);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    parent[1] = -1;

    int e;
    for(int i=2;i<=n;i++){
        cin >> e;
        parent[i] = e;
        adj[e].push_back(i);
    }

    fill_jumps(1);

    int x, k;
    for(int i=1;i<=q;i++){
        cin >> x >> k;
        int p = 0;
        int node = x;
        while(node != -1 && k > 0){
            if(k&1){
                node = binary_lifting[node][p];
            }
            p++;
            k = k >> 1;
        }
        cout << node << "\n";
    }

    return 0;
}