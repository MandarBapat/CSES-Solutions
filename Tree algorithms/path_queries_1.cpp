#include <bits/stdc++.h>

using namespace std;

int values[(int)(2e5+1)];
vector<int> adj[(int)(2e5+1)];
vector<int> tour;
int first[(int)(2e5+1)];
int last[(int)(2e5+1)];

void euler_tour(int index, int parent){
    tour.push_back(values[index]);
    first[index] = tour.size() - 1;

    for(auto x : adj[index]){
        if(x != parent){
            euler_tour(x, index);
        }
    }

    tour.push_back(-values[index]);
    last[index] = tour.size() - 1;
}

void build_tree(long long int* tree, int index, int l, int r){
    if(l <= r){
        if(l == r){
            tree[index] = tour[l];
        }
        else{
            int mid = l + (r-l)/2;
            build_tree(tree, 2*index+1, l, mid);
            build_tree(tree, 2*index+2, mid+1, r);
            tree[index] = tree[2*index+1] + tree[2*index+2];
        }
    }
}

void modification_query(long long int* tree, int index, int l, int r, int index2, int diff){
    if(l <= r){
        if(l == r && l == index2){
            tree[index] += diff;
        }
        else if( l<=index2 && index2<=r ){
            int mid = l + (r-l)/2;
            tree[index] += diff;
            modification_query(tree, 2*index+1, l, mid, index2, diff);
            modification_query(tree, 2*index+2, mid+1, r, index2, diff);
        }
    }
}

long long int sum_query(long long int* tree, int index, int l, int r, int ql, int qr){
    if(l <= r){
        if( ql <= l && r <= qr ){
            return tree[index];
        }
        else if( r < ql || l > qr ){
            return 0;
        }
        else{
            int mid = l + (r-l)/2;
            long long int ans1 = sum_query(tree, 2*index+1, l, mid, ql, qr);
            long long int ans2 = sum_query(tree, 2*index+2, mid+1, r, ql, qr);
            return ans1 + ans2;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i=1;i<=n;i++){
        cin >> values[i];
    }

    int a, b;
    for(int i=1;i<=(n-1);i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int h = (int)ceil(1 + log2(n));
    int len = 2*(int)pow(2, h) - 1;
    long long int tree[len];

    euler_tour(1, -1);
    build_tree(tree, 0, 0, 2*n-1);

    for(int i=1;i<=q;i++){
        int t;
        cin >> t;

        if(t == 1){
            int s, x;
            cin >> s >> x;
            int index1 = first[s];
            int index2 = last[s];
            modification_query(tree, 0, 0, 2*n-1, index1, x - tour[index1]);
            tour[index1] = x;
            modification_query(tree, 0, 0, 2*n-1, index2, -x - tour[index2]);
            tour[index2] = -x;
        }
        else{
            int s;
            cin >> s;
            int index1 = first[s];
            cout << sum_query(tree, 0, 0, 2*n-1, 0, index1) << "\n";
        }
    }

    return 0;
}