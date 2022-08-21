#include <bits/stdc++.h>

using namespace std;

int ans[(int)(2e5+1)];
vector<int> tree[(int)(2e5+1)];

int f(int index){
    if(ans[index] != -1){
        return ans[index];
    }
    else{
        if(tree[index].size() == 0){
            ans[index] = 0;
            return 0;
        }
        else{
            int val = tree[index].size();
            for(auto c : tree[index]){
                val += f(c);
            }
            ans[index] = val;
            return val;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;

    for(int i=2;i<=n;i++){
        int temp;
        cin >> temp;
        tree[temp].push_back(i);
    }

    for(int i=1;i<((int)(2e5+1));i++){
        ans[i] = -1;
    }

    f(1);

    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }

    return 0;
}