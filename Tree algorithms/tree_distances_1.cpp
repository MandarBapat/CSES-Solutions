#include <bits/stdc++.h>

using namespace std;

vector<int> adj[(int)(2e5+1)];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a,b;
    for(int i=1;i<=(n-1);i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool vis1[n+1] = {0};
    bool vis2[n+1] = {0};

    int dis1[n+1] = {0};
    int dis2[n+1] = {0};

    queue<int> q1, q2;

    q1.push(1);
    dis1[1] = 0;

    while( !(q1.empty()) ){
        int temp = q1.front();
        q1.pop();

        vis1[temp] = 1;

        for(auto c : adj[temp]){
            if(!vis1[c]){
                dis1[c] = 1 + dis1[temp];
                q1.push(c);
            }
        }
    }

    int max_dist = 0;
    int x = 0;
    for(int i=1;i<=n;i++){
        if(dis1[i] > max_dist){
            max_dist = dis1[i];
            x = i;
        }
    }

    q2.push(x);
    dis2[x] = 0;

    while( !(q2.empty()) ){
        int temp = q2.front();
        q2.pop();

        vis2[temp] = 1;

        for(auto c : adj[temp]){
            if(!vis2[c]){
                dis2[c] = 1 + dis2[temp];
                q2.push(c);
            }
        }
    }

    max_dist = 0;
    int y = 0;
    
    for(int i=1;i<=n;i++){
        if(dis2[i] > max_dist){
            max_dist = dis2[i];
            y = i;
        }
    }

    queue<int> q3;
    q3.push(y);
    int vis3[n+1] = {0};
    int dis3[n+1] = {0};
    dis3[y] = 0;

    while( !(q3.empty()) ){
        int temp = q3.front();
        q3.pop();

        vis3[temp] = 1;

        for(auto c : adj[temp]){
            if(!vis3[c]){
                dis3[c] = 1 + dis3[temp];
                q3.push(c);
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout << max(dis2[i], dis3[i]) << " ";
    }

    return 0;
}