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

    bool vis[n+1] = {0};

    queue<int> q;
    q.push(1);

    int dis[n+1] = {0};
    dis[1] = 0;

    while( !(q.empty()) ){
        int temp = q.front();
        q.pop();

        vis[temp] = 1;

        for(auto c : adj[temp]){
            if(!vis[c]){
                dis[c] = dis[temp] + 1;
                q.push(c);
            }
        }
    }

    int max_index = 0;
    int max_dis = 0;
    for(int i=1;i<=n;i++){
        if(dis[i] > max_dis){
            max_dis = dis[i];
            max_index = i;
        }
    }

    queue<int> q1;
    q1.push(max_index);

    bool vis2[n+1] = {0};
    int dis2[n+1] = {0};
    dis[max_index] = 0;

    int diameter = 0;

    while( !(q1.empty()) ){
        int temp = q1.front();
        q1.pop();

        vis2[temp] = 1;

        for(auto c : adj[temp]){
            if(!vis2[c]){
                dis2[c] = dis2[temp] + 1;
                diameter = max(diameter, dis2[c]);
                q1.push(c);
            }
        }
    }

    cout << diameter;
    

    return 0;
}